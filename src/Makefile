#Makefile
#cible: dependances
#	commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

CC=g++
CFLAGS=-std=c++11 -Wextra -Wall #-Wno-reorder
#-11 -g11 -m32 -fPIC -Wno-deprecated -pthread -m32#-std=c99 -Wextra -Wall# -ansi -pedantic
LDFLAGS=
EXEC_SRC=prog
EXEC_TST=test
SRC=$(wildcard *.cpp datas/src/*.cpp gui/src/*.cpp game/src/*.cpp)
TST=$(wildcard datas/test/*.cpp game/test/*.cpp gui/test/*.cpp)
OBJ_SRC=$(SRC:.cpp=.o)
OBJ_TST=$(TST:.cpp=.o) #$(OBJ_SRC)
projet=~/Bureau/projetPerso/chessE/src

all: $(EXEC_SRC) $(EXEC_TST)

$(EXEC_SRC): $(OBJ_SRC)
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC_TST): $(OBJ_TST)
	cd $(projet)/datas/test; 	make -f Makefile
	echo
	cd $(projet)/game/test;		make -f Makefile
	echo
	cd $(projet)/gui/test;		make -f Makefile

.PHONY: cleanSimple clean 

cleanSimple:
	rm -rf $(OBJ_SRC)

clean: cleanSimple
	rm -rf $(EXEC_SRC) $(EXEC_TST)	
