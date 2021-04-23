
#!/usr/bin/python3
"""check if all boxes can be opened"""


def canUnlockAll(boxes):
    """check if boxes can be opened"""
    keys = [0]
    open_box = [0]
    check_key = True
    while check_key:
        check_key = False
        for box in boxes:
            if boxes.index(box) in keys:
                if boxes.index(box) not in open_box:
                    open_box.append(boxes.index(box))
                for x in box:
                    if x not in keys:
                        keys.append(x)
                        check_key = True
    if len(open_box) == len(boxes):
        return True
    else:
        return False
