#!/env/usr/bash

cd $1
for file in ./*.c 
do
  filename=$(echo $file | tr -d ".c")
  mkdir $filename
  mv $file $filename
done
