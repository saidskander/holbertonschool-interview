#!/usr/bin/python3
""" Change comes from within """


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total
    """
    if total <= 0:
        return 0

    newcointotal = total + 1
    amount = {0: 0}

    for x in range(1, total + 1):
        amount[x] = newcointotal

        for coin in coins:
            current = x - coin
            if current < 0:
                continue

            amount[x] = min(amount[current] + 1, amount[x])

    if amount[total] == total + 1:
        return -1

    return amount[total]
