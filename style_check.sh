#!/usr/bin bash

cp ../materials/linters/.clang-format .

for file in `find . -type f -name "*.c"`
do
   clang-format -i ${file} ;
done

for file in `find . -type f -name "*.h"`
do
   clang-format -i ${file} ;
done

rm -rf .clang-format
