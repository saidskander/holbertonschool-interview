#!/usr/bin/python3
""" Log Parsing """
from sys import stdin

lines = 0
file_size = 0
status_code = 0
status_codes = {"200": 0, "301": 0,
                "400": 0, "401": 0,
                "403": 0, "404": 0,
                "405": 0, "500": 0}


def printstats(file_size, status_codes):
    """ print sorted Pr  """
    print("File size: " + str(file_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] >= 1:
            print(code + ": " + str(status_codes[code]))

try:
    for line in stdin:
        lines += 1
        split_line = line.split()
        if len(split_line) >= 2:
            file_size += int(split_line[-1])
        if len(split_line) >= 3 and split_line[-2].isnumeric():
            status_code = split_line[-2]
        else:
            status_code = 0

        if status_code in status_codes.keys():
            status_codes[status_code] += 1
        if lines % 10 == 0:
            printstats(file_size, status_codes)
    printstats(file_size, status_codes)
except (KeyboardInterrupt):
    printstats(file_size, status_codes)
    raise
