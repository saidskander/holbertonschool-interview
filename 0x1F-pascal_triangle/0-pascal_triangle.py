#!/usr/bin/python3


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing
    Pascal's triangle of depth n.
    """
    if n <= 0:
        return []
    if n == 1:
        return [[1]]
    if n == 2:
        return [[1], [1, 1]]
    pascal = [[1], [1, 1]]

    for i in range(2, n):
        row = []
        row.append(1)
        for x in range(1, i):
            row.append(pascal[-1][x - 1] + pascal[-1][x])
        row.append(1)
        pascal.append(row)
    return pascal
