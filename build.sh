#!/bin/bash

CC=clang

$CC -O1 -DMANUAL_INLINE matmul.c -o matmul_manual_inline
$CC -O1 -DCOMPILER_INLINE matmul.c -o matmul_compiler_inline
$CC -O1 matmul.c -o matmul_noinline

ITER=99999999

echo ""
echo "No function abstration"
time ./matmul_manual_inline 2 $ITER

echo ""
echo "Matmul is a non-inlined function"
time ./matmul_noinline 2 $ITER

echo ""
echo "Matmul is inlined by the compiler"
time ./matmul_compiler_inline 2 $ITER
