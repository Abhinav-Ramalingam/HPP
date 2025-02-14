#!/bin/bash

mkdir -p tests
cd tests

sizes=("900" "450" "225" "100" "50")

for size in "${sizes[@]}"; do
    ../a.out $size
    gprof ../a.out gmon.out > test_$size.txt
    rm gmon.out
done

cat test_*.txt
