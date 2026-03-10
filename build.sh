#!/bin/bash

echo "Running: flex Scanner.l"
flex Scanner.l || { echo "Flex failed"; exit 1; }

echo "Running: bison -d parser.y"
bison -d parser.y || { echo "Bison failed"; exit 1; }

echo "Running: gcc lex.yy.c parser.tab.c symbolTable.c c.cpm -o exe.cpm -lfl"
gcc lex.yy.c parser.tab.c symbolTable.c -o cpm -lfl || { echo "GCC failed"; exit 1; }

echo "✅ Build complete. Executable: exe.cpm"