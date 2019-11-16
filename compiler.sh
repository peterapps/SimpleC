#!/bin/bash

out_file=${1%.*}
dir=$(dirname "$0")

$dir/src/simplec $1 $out_file.s
gcc $out_file.s -o $out_file
rm $out_file.s
