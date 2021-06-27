#!/usr/bin/python3
"""UTF-8"""

def validUTF8(data):
    """ valid UTF-8 encoding """
    byte_numbers = 0
    encoding_bytes = 1 << 7
    encoding_number = 1 << 6
    for utf in data:
        utf_data = 1 << 7
        if byte_numbers == 0:
            while utf_data & utf:
                byte_numbers += 1
                utf_data = utf_data >> 1
            if byte_numbers == 0:
                continue
            if byte_numbers == 1 or byte_numbers > 4:
                return False
        else:
            if not (utf & encoding_bytes and not (utf & encoding_number)):
                return False
        byte_numbers -= 1
    return byte_numbers == 0
