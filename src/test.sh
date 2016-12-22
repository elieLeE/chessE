#!/bin/bash

resultTest(){
    #echo "test "$1
    if [ $2 != 0 ]
    then
	echo "Error"
	exit
    fi
}

if [ ! -f ./datas/test/prog ] || [ ! -f ./game/test/prog ] || [ ! -f ./gui/test/prog ] 
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
		valgrind ./datas/test/prog
	fi
else
	./datas/test/prog
fi
resultTest "datas" $?

echo 
#$opt ./game/test/./prog $opt
if [ $? = 1 ]
then
	if [ $1 = -v ] || [ $1 = -valgrind ]
	then
		valgrind ./game/test/prog
	fi
else
	./game/test/prog
fi
resultTest "game" $? 

echo 
#$opt ./gui/test/./prog $opt
if [ $? = 1 ]
then
	if [ $1 = -v ] || [ $1 = -valgrind ]
	then
		valgrind ./gui/test/prog
	fi
else
	./gui/test/prog
fi
resultTest "gui" $?

echo 
echo "All tests OK"

echo 
echo 
echo "aFaire : "
more aResoudre
