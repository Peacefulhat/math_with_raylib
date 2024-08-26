!#/usr/bin/zsh

gcc -o main $1 $2 -lraylib -lm 

./main

rm -rf main