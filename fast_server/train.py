"""{
"capacity": 15,
"idx": 0,
"line_idx": null,
"player_id": "8f53c0f7-9260-4c4b-ab20-9fa8041895d3",
"position": null,
"product": 0,
"speed": 0
}
"""

import json
class Train():

    _idx = 0
    def __init__(self, data):
        self.idx = Train._idx
        self.capacity = data["capacity"]
        self.line_idx = data["line_idx"]
        self.player_id = data["player_id"]
        self.position = data["position"]
        self.product = data["product"]
        self.speed = data["speed"]
        Train._idx += 1

    def buffer(self):
        dict = {
        "capacity": self.capacity,
        "idx": self.idx,
        "line_idx": self.line_idx,
        "player_id": self.player_id,
        "position": self.position,
        "product": self.product,
        "speed": self.speed
        }
        return dict
