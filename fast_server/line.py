"""
{
"idx": 1,
"length": 10,
"point": [
    1,
    7
]} """

class Line():


    def __init__(self, data):
        self.idx = data["idx"]
        self.length = data["length"]
        self.point = data["point"]

    def in_point(self, position):
        if position == 0:
            return self.point[0]
        if position == self.length:
            return self.point[1]
        return None
