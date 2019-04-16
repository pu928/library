
CC=gcc
LD=gcc

OBJECTFILES=var_type.o

# DIR_TARGET=../bin
TARGET=var_type

CFLAGS=-m64 -O3
LDFLAGS=-m64


$(TARGET): $(OBJECTFILES)
	# $(LD) $(LDFLAGS) $(OBJECTFILES) -o $(TARGET)
	
clean:
	rm -rf *.o $(TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

var_type.o: var_type.c var_type.h
	$(CC) -c $(CFLAGS) $< -o $@
