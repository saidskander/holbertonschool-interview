#!/usr/bin/python3
"""
methods:
https://www.tutorialspoint.com/
different-methods-to-find-prime-number-in-python-program
"""


def isWinner(x, nums):
    """Prime Game"""
    if not nums or x < 1:
        return None
    n = max(nums)
    filter = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not filter[i]:
            continue
        for range_numbers in range(i * i, n + 1, i):
            filter[range_numbers] = False

    filter[0] = filter[1] = False
    h = 0
    for i in range(len(filter)):
        if filter[i]:
            h += 1
        filter[i] = h

    place = 0
    for n in nums:
        place += filter[n] % 2 == 1
    if place * 2 == len(nums):
        return None
    if place * 2 > len(nums):
        return "Maria"
    return "Ben"
