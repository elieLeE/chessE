#!/bin/bash

resultTest(){
    #echo "test "$1
    if [ $2 != 0 ]
    then
	echo "Error"
	exit
    fi
}

if [ ! -f ./datas/test/test ] || [ ! -f ./game/test/test ] || [ ! -f ./gui/test/test ] 
then
	echo "Compilez les tests !"
	exit
fi

opt=

#echo "lancement des test unitaires"
#echo
#$opt ./common/test/./prog
#./common/test/prog
#resultTest "common" $?

echo
#$opt ./datas/test/./prog

if [ $? = 1 ] 
then
	if [ $1 = -v ] || [ $1 = -valgrind ]
	then
		valgrind ./datas/test/test
	fi
else
	./datas/test/test
fi
resultTest "datas" $?

echo 
#$opt ./game/test/./prog $opt
if [ $? = 1 ]
then
	if [ $1 = -v ] || [ $1 = -valgrind ]
	then
		valgrind ./game/test/test
	fi
else
	./game/test/test
fi
resultTest "game" $? 

echo 
#$opt ./gui/test/./prog $opt
if [ $? = 1 ]
then
	if [ $1 = -v ] || [ $1 = -valgrind ]
	then
		valgrind ./gui/test/test
	fi
else
	./gui/test/test
fi
resultTest "gui" $?

echo 
echo "All tests OK"

echo 
echo 
echo "aFaire : "
more aResoudre
