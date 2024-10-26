#!/env/usr/bash

# Use with "fdfind . --type d --exec bash ../generateExec.sh '{}' \;"
cd $1
for file in ./*.c
do
  filename=$(echo $file | sed -E 's|\.\/(.*)\.c|\1|')
  echo $filename
  bash ../../run.sh $filename
done
cd ..

