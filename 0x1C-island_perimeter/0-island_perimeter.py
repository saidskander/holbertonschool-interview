#!/usr/bin/python3
""" Island perimeter """


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    p = 0
    """ Length: number of lines"""
    length = len(grid)
    """ Width: number of columns """
    width = len(grid[0])
    for c in range(length):
    """ loop through lines """
        for i in range(width):
            """ If there is 1 and no 1 above it """
            if grid[c][i] == 1 and ((c > 0 and grid[c - 1][i] != 1) or c == 0):
                p += 1
            """ If there is 1 and no 1 below it """
            if grid[c][i] == 1 and ((c + 1 != length and grid[c + 1][i] != 1)
                                    or c + 1 == length):
                p += 1
            """ If there is 1 and no 1 on the left """
            if grid[c][i] == 1 and ((i > 0 and grid[c][i - 1] != 1) or i == 0):
                p += 1
            """ If there is 1 and no 1 on the right """
            if grid[c][i] == 1 and ((i + 1 != width and grid[c][i + 1] != 1)
                                    or i + 1 == width):
                p += 1
    return p
