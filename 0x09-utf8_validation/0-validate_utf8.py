#!/usr/bin/python3
""" valid UTF-8 encoding """


def validUTF8(data):
    """ Encode UTF-8 """
    bytes_number = 0
    for num in data:
        encoding_num = format(num, '#010b')[-8:]
        if bytes_number == 0:
            for n in encoding_num:
                if n == '0':
                    break
                bytes_number += 1
            if bytes_number == 0:
                continue
            if bytes_number == 1 or bytes_number > 4:
                return False
        else:
            if not (encoding_num[0] == '1' and encoding_num[1] == '0'):
                return False
        bytes_number = bytes_number - 1
    return bytes_number == 0
