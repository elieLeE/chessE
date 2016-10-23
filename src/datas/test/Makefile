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
SRC= $(wildcard *.cpp ~/Bureau/projetPerso/chessE/src/datas/src/*.cpp ~/Bureau/projetPerso/chessE/src/datas/src/piece/*.cpp ~/Bureau/projetPerso/chessE/src/game/src/*.cpp ~/Bureau/projetPerso/chessE/src/gui/src/*.cpp) 
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
