#!/bin/bash

resultTest(){
    #echo "test "$1
    if [ $2 != 0 ]
    then
	echo "Error"
	exit
    fi
}

if [ ! -f ./datas/testUnitaires/test ] || [ ! -f ./game/testUnitaires/test ] || [ ! -f ./gui/testUnitaires/test ] 
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
		valgrind ./datas/testUnitaires/test
	fi
else
	./datas/testUnitaires/test
fi
resultTest "datas" $?

echo 
#$opt ./game/test/./prog $opt
if [ $? = 1 ]
then
	if [ $1 = -v ] || [ $1 = -valgrind ]
	then
		valgrind ./game/testUnitaires/test
	fi
else
	./game/testUnitaires/test
fi
resultTest "game" $? 

echo 
#$opt ./gui/test/./prog $opt
if [ $? = 1 ]
then
	if [ $1 = -v ] || [ $1 = -valgrind ]
	then
		valgrind ./gui/testUnitaires/test
	fi
else
	./gui/testUnitaires/test
fi
resultTest "gui" $?

echo 
echo "All tests OK"

echo 
echo 

if [ -f aResoudre ]
then
    echo "aFaire : "
    more aResoudre
fi
