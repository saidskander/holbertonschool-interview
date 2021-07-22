#!/usr/bin/python3
""" nqueez challenge """
import sys


def verify(solution, pos):
    """ verify possitioninig """
    for n_queen in solution:
        if n_queen[1] == pos[1]:
            return False
        if (n_queen[0] + n_queen[1]) == (pos[0] + pos[1]):
            return False
        if (n_queen[0] - n_queen[1]) == (pos[0] - pos[1]):
            return False
    return True


def queens_r(row, n, solution):
    """ recursively solution """
    if (row == n):
        print(solution)
    else:
        for x in range(n):
            pos = [row, x]
            if verify(solution, pos):
                solution.append(pos)
                queens_r(row + 1, n, solution)
                solution.remove(pos)


def solution_call(n):
    """ solve queens arguments function """
    solution = []
    queens_r(0, n, solution)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        x = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        sys.exit(1)
    x = int(sys.argv[1])
    if x < 4:
        print('N must be at least 4')
        sys.exit(1)

    """ Calling the last function """
    solution_call(x)
