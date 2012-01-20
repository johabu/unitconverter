#!/bin/bash

echo
echo "gcc -O2 -o unitconv -W -Wall unitconverter.c unitconv_func.c unitconv_units.c"
echo "Start compiling ..."
gcc -O2 -o unitconv -W -Wall unitconverter.c unitconv_func.c unitconv_units.c
echo
echo "compiled."
echo
