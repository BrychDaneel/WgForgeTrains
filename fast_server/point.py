"""{
    "idx": 1,
    "post_id": 1
}"""


class Point():

    def __init__(self, data):
        self.idx = data["idx"]
        self.post_id = data["post_id"]
        self.line = []


    def add_line(self, line):
        self.line.append(line)
