#!/bin/bash

resultTest(){
    #echo "test "$1
    if [ $2 != 0 ]
    then
	echo "Error"
	exit
    fi
}

echo "lancement des test unitaires"
echo
./datas/test/./prog
resultTest "datas" $?

echo 
./game/test/./prog
resultTest "game" $? 

echo 
./gui/test/./prog
resultTest "gui" $?

echo 
echo "All tests OK"