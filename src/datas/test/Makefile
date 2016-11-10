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
EXEC=prog
projet=../../
toExclude=main.cpp
SRC=$(shell find $(projet) -name "*.cpp" -not -path "../../main.cpp" -not -path "*game/test*" -not -path "*gui/test*" -not -path "*common/test*" -not -path "*common/src/UnitTest.cpp")
#SRC=$(shell find $(projet) -name "*.cpp" -not -path "../../main.cpp" -not -path "*game/test*" -not -path "*gui/test*") 
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: cleanSimple clean 

cleanSimple:
	rm -rf $(OBJ)

clean: cleanSimple
	rm -rf $(EXEC)	
