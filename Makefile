CC = gcc
nsum_test: nsum_test.c libnsum.1.0.dylib
	$(CC) nsum_test.c libnsum.1.0.dylib -o nsum_test

nsum_runtime_test: nsum_runtime_test.c libnsum.1.0.dylib
	$(CC) nsum_runtime_test.c -o nsum_runtime_test

libnsum.1.0.dylib: nsum.c
	$(CC) -dynamiclib nsum.c -current_version 1.0 -compatibility_version 1.0 -o libnsum.1.0.dylib
