# NSUM

## What?

NSUM is a trivial number summation function dynamic library for macosx.

## Why?

> TLDR; Learning purposes.

## Okay, so what now again?

`nsum.h` defines the API of a single function `nsum` which takes in as parameters, `n` an integer of the count of numbers to sum, and `numbers` a pointer to `int` of the numbers to be summed.

`nsum.c` implements the API

`nsum_test.c` shows the basic usage of the library at linker time

`nsum_runtime_test.c` shows the advanced usage of the library at runtime

`nsum_test.py` shows how to use the library from Python 3!

`Makefile` builds the C projects:

## How do I build this?

Build the library

```
$ make libnsum.1.0.dylib
```

Build the tests

```
$ make nsum_test
$ make nsum_runtime_test
```

## Great, it built, but now what?

Run the tests

```
$ ./nsum_test

$ ./nsum_runtime_test

$ python3 ./nsum_test.py
```

## LICENSE

All code licensed with the MIT License (c) 2019, Richard Marks <ccpsceo@gmail.com>
