#!/bin/sh
# build_nasm_debug.sh
# Usage: ./build_nasm_debug.sh main.asm
# Compiles NASM x64 assembly with debug symbols and links to executable

if [ $# -ne 1 ]; then
  echo "Usage: $0 <file.asm>"
  exit 1
fi

ASM_FILE="$1"
OBJ_FILE="${ASM_FILE%.asm}.o"
EXE_FILE="${ASM_FILE%.asm}"

# Assemble with debug info
nasm -f elf64 -g -F dwarf "$ASM_FILE" -o "$OBJ_FILE"
if [ $? -ne 0 ]; then
  echo "NASM assembly failed."
  exit 1
fi

# Link to executable
gcc -no-pie -g -o "$EXE_FILE" "$OBJ_FILE"
if [ $? -ne 0 ]; then
  echo "Linking failed."
  exit 1
fi

echo "Built $EXE_FILE (with debug symbols)"
echo "Built $EXE_FILE (with debug symbols and C library support)"
