
CC=gcc
LD=gcc

VAR_TYPE_DIR=../

OBJECTFILES=main.o var_type.o

# DIR_TARGET=../bin
TARGET=var_type

CFLAGS=-m64 -O3 -I$(VAR_TYPE_DIR)
LDFLAGS=-m64


$(TARGET): $(OBJECTFILES)
	$(LD) $(LDFLAGS) $(OBJECTFILES) -o $(TARGET)
	
clean:
	rm -rf *.o $(TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

var_type.o: $(VAR_TYPE_DIR)/var_type.c $(VAR_TYPE_DIR)/var_type.h
	$(CC) -c $(CFLAGS) $< -o $@
