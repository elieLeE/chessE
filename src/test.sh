#!/bin/bash

resultTest(){
    #echo "test "$1
    if [ $2 != 0 ]
    then
	echo "Error"
	exit
    fi
}

if [ ! -f ./datas/test/./prog ] || [ ! -f ./game/test/./prog ] || [ ! -f ./gui/test/./prog ]
then
	echo "Compilez les tests !"
	exit
fi

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