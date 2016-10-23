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

opt=
if [ $# == 1 ]
then
    echo "1 argument"
    if [ $1 == -v ] || [ $1 == -valgrind ]
    then
	echo "avec valgrind"
	opt=valgrind --leak-check=full --show-leak-kinds=all
    fi
fi
echo $1
echo $opt

echo "lancement des test unitaires"
echo
$opt ./datas/test/./prog
resultTest "datas" $?

echo 
$opt ./game/test/./prog $opt
resultTest "game" $? 

echo 
$opt ./gui/test/./prog $opt
resultTest "gui" $?

echo 
echo "All tests OK"
