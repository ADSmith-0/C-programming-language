#!/env/usr/bash

# Use with "fdfind . --type d --exec bash ../generateExec.sh '{}' \;"
cd $1
for file in ./*.c
do
  filename=$(echo $file | tr -d ".c")
  echo $filename
  bash ../../run.sh $filename
done
cd ..

