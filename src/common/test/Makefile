#Makefile
#cible: dependances
#	commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

CC=g++
CFLAGS=-std=c++11 -Wextra -Wall# -ansi -pedantic
LDFLAGS=
EXEC=test
projet=../../
SRC=$(shell find $(projet) -name "*.cpp" -not -path "../../main.cpp" -not -path "*datas/test*" -not -path "*gui/test*" -not -path "*game/test*" -not -path "*common/src/UnitTest.cpp" -not -path "*testCPP*")
#SRC=$(wildcard ../../datas/src/*.cpp ../../gui/src/*.cpp ../../game/src/*.cpp *.cpp) 
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
	
main.cpp: ../src/UnitTest.h

.PHONY: cleanSimple clean 

cleanSimple:
	rm -rf $(OBJ)

clean: cleanSimple
	rm -rf $(EXEC)	
