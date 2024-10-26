#!/env/usr/bash

cd $1
for file in ./*.c 
do
  filename=$(echo $file | sed -E 's|\.\/(.*)\.c|\1|')
  mkdir $filename
  mv $file $filename
done
