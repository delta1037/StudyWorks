# /bin/bash

#对文件路径的本目录的所有文件的文件名进行排序

path=$1
files=$(ls $path)

for filename in $files

do
   echo $filename>>sort.txt
done

echo "排序之后:"

sort sort.txt

rm sort.txt




