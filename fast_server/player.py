"""{
"home": {
"idx": 1,
"post_id": 1
},
"idx": "8f53c0f7-9260-4c4b-ab20-9fa8041895d3",
"name": "botVasya",
"train": [
{
    "capacity": 15,
    "idx": 0,
    "line_idx": null,
    "player_id": "8f53c0f7-9260-4c4b-ab20-9fa8041895d3",
    "position": null,
    "product": 0,
    "speed": 0
}
]
}"""

import train
import json

class Player():

    def buffer(self ):
        dict = {
        "home": self.home,
        "idx": self.idx,
        "name": self.name,
        "train": [tr.buffer() for tr in self.trains]
        }
        return json.dumps(dict)

    _idx = 1
    def __init__(self, name):
        self.home = { "idx": 1, "post_id": 1 }
        self.idx = str(Player._idx)
        Player._idx += 1
        self.name = name

        self.trains = [train.Train({
            "capacity": 15,
            "line_idx": None,
            "player_id": self.idx,
            "position": None,
            "product": 0,
            "speed": 0
        })]
