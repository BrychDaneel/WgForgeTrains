import json
import struct

def load_from_json(path):
    with open(path, "r") as json_file:
        json_dict = json.loads(json_file.read())
    return json_dict

def read_file(path):
    with open(path, "r") as file:
        buffer = file.read()
    return buffer


from line import Line
from player import Player
from train import Train
from point import Point

class World():
    def __init__(self):
        self.players = {}
        self.players_idx = {}
        self.players_addr = {}

        static = load_from_json("static.txt")
        self.points = {}
        self.lines = {}
        self.trains = {}

        for point in static["point"]:
            pp = Point(point)
            self.points[pp.idx] = pp

        for line in static["line"]:
            ll = Line(line)
            self.points[ll.point[0]].add_line(ll.idx)
            self.points[ll.point[1]].add_line(ll.idx)
            self.lines[ll.idx] = ll

        self.dynamic = load_from_json("dynamic.txt")




    def make_command(self, command, buffer, addr):
        if command == 1:
            return self._login(buffer, addr)
        elif command == 3:
            return self._move(buffer, addr)
        elif command == 10:
            return self._map(buffer)


    def disconnect(self, addr):
        del self.players_addr[addr]

    def _login(self, buffer, addr):
        data = json.loads(str(buffer))
        if data["name"] not in self.players:
            pp = Player(data["name"])
            self.players[data["name"]] = pp
            self.players_idx[pp.idx] = pp
            self.players_addr[addr] = pp
            for tt in pp.trains:
                self.trains[tt.idx] = tt
        else:
            self.players_addr[addr] = self.players[data["name"]]


        buffer = self.players[data["name"]].buffer()
        send_buffer = struct.pack("<2L", 0, len(buffer))
        send_buffer += buffer.encode()
        return send_buffer

    def _move(self, buffer, addr):
        """{
            "line_idx": 1,
            "speed": 1,
            "train_idx": 0
        }"""
        data = json.loads(str(buffer))


        if (data["train_idx"] not in self.trains
                or data["line_idx"] not in self.lines) :
            return struct.pack("<2L", 1, 0)

        print("Hello")
        train = self.trains[data["train_idx"]]
        if (self.players_idx[train.player_id] !=
            self.players_addr[addr]):
            return struct.pack("<2L", 1, 0)

        line_idx = train.line_idx;
        if line_idx is None:
            point_idx = self.players_addr[addr].home["idx"]
        else:
            point_idx = self.lines[line_idx].in_point()

        if point_idx is None:
            return struct.pack("<2L", 1, 0)

        line_idx = data["train_idx"]
        if line_idx in self.points[point_idx]:
            train.line_idx = line_idx
            train.speed = data["speed"]
            if self.lines[line_idx].point[0] == point_idx:
                train.position = 0
            else:
                train.position = self.lines[line_idx].length
            return struct.pack("<2L", 0, 0)
        else:
            return struct.pack("<2L", 1, 0)




    def _map(self, buffer):
        data = json.loads(str(buffer))
        if data["layer"] == 0:
            buffer = read_file("static.txt")
        else:
            self.dynamic["train"] = [tr.buffer() for tr in list(self.trains.values())]
            buffer = json.dumps(self.dynamic)

        send_buffer = struct.pack("<2L", 0, len(buffer))
        send_buffer += buffer.encode()
        return send_buffer
