#!/bin/bash
rm test_result.txt

test_times=(
1000
2000
4000
6000
8000
10000
12000
14000
#100000
#120000
#140000
)

for data in ${test_times[@]}
do 
    echo ${data},`./test_sort ${data} 0` | tr -cd "[0-9\n,]" >> test_result.txt
done  
