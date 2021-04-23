#!/usr/bin/python3
"""check if all boxes can be opened"""


def canUnlockAll(boxes):
    """check if boxes can be opened"""
    NumBoxes = len(boxes)

    keys = [0]

    for key in keys:
        box = boxes[key]
        for NewKey in box:
            if NewKey < NumBoxes and NewKey not in keys:
                keys.append(NewKey)
    if NumBoxes == len(keys):
        return True
    else:
        return False
