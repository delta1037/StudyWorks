#!/bin/bash

#对文件路径本目录及其所有子目录文件名排序

function ergodic(){
    for filename in $(ls $1)
    do
        if [ -d $1"/"$filename ]
        then
            ergodic $1"/"$filename
        else
                
            echo $filename>>test.txt
        fi
    done
}
ergodic $1

echo "排序之后:"

sort test.txt

rm test.txt
