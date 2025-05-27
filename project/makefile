CC = m68k-elf-gcc
AC = gcc
AS = m68k-elf-as

CFLAGS = -m68000 -nostdlib -ffreestanding -Wall -Iinclude -fomit-frame-pointer
LDFLAGS = -T linker.ld
ERRORS = 2>> errors.txt

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
ASM_SRC = $(wildcard src/*.asm)
ASM_OBJ = $(patsubst src/%.asm, build/%.o, $(ASM_SRC))

HOST_SRC = $(wildcard p2/*.c)
HOST_OBJ = $(patsubst p2/%.c, p2/%.o, $(HOST_SRC))



# Default build
all: build build/main.elf

build:
	mkdir -p build

# Cross compile for M68000
build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(ERRORS)

build/%.o: src/%.asm
	$(AS) -o $@ $< $(ERRORS)

build/main.elf: $(OBJ) $(ASM_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(ASM_OBJ) -o $@ $(LDFLAGS)
	m68k-elf-objdump -d $@ > build/main.asm
	rm -f $(OBJ)

# Host build and test
ptwo: $(HOST_OBJ) 
	$(AC) -o ptwo $(HOST_OBJ) 
	./ptwo
	rm -f $(HOST_OBJ) ptwo

p2/%.o: p2/%.c
	rm errors.txt
	$(AC) -c $< -o $@ -Wunused-variable $(ERRORS)

# Clean all
clean:
	rm -rf build
	rm -f p2/*.o errors.txt NAME
