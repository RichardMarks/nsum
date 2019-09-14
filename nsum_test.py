#!/usr/bin/env python3

import ctypes

def main():
    nsum = ctypes.CDLL('libnsum.1.0.dylib')
    numbers = [10, 20]
    n = len(numbers)
    print(nsum.nsum(n, (ctypes.c_int * n)(*numbers)))

if __name__ == '__main__':
    main()
