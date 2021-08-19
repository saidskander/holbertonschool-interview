#!/usr/bin/python3
""" Visual representation of the walls """


def rain(walls):
    """ Return rainwall array of wall heights"""
    y, j = 0, len(walls) - 1
    lmax = rmax = x = 0
    while y < j:
        if walls[j] > walls[y]:
            if walls[y] > lmax:
                lmax = walls[y]
            else:
                x += lmax - walls[y]
            y += 1
        else:
            if walls[j] > rmax:
                rmax = walls[j]
            else:
                x += rmax - walls[j]
            j -= 1
    return x
