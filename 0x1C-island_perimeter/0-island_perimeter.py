#!/usr/bin/python3
""" Island perimeter """


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    p = 0
    length = len(grid)
    width = len(grid[0])
    for c in range(length):
        for i in range(width):
            if grid[c][i] == 1 and ((c > 0 and grid[c - 1][i] != 1) or c == 0):
                p += 1
            if grid[c][i] == 1 and ((c + 1 != length and grid[c + 1][i] != 1)
                                    or c + 1 == length):
                p += 1
            if grid[c][i] == 1 and ((i > 0 and grid[c][i - 1] != 1) or i == 0):
                p += 1
            if grid[c][i] == 1 and ((i + 1 != width and grid[c][i + 1] != 1)
                                    or i + 1 == width):
                p += 1
    return p
