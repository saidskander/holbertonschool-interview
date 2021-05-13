#!/usr/bin/python3
"""copy past script"""


def minOperations(n):
    """minimumoperation"""
    if n <= 1:
        return 0
    div = 2
    oper = 0
    num = n
    while num > 1:
        if (num % div) == 0:
            num = num // div
            oper += div
        else:
            div += 1
    return oper
