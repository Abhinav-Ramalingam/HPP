#!/bin/bash

values=(3 5 7 9 11)

for value in "${values[@]}"; do
    echo "Running ./pyramid with input: $value"
    ./pyramid "$value"
    echo ""
done
