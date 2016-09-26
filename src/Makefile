#Makefile
#cible: dependances
#	commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

CC=g++
CFLAGS=#-std=c++11
#-11 -g11 -m32 -fPIC -Wno-deprecated -pthread -m32#-std=c99 -Wextra -Wall# -ansi -pedantic
LDFLAGS=
EXEC=prog 
SRC=$(wildcard *.cpp datas/src/*.cpp gui/src/*.cpp game/src/*.cpp) 
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: cleanSimple clean 

cleanSimple:
	rm -rf $(OBJ)

clean: cleanSimple
	rm -rf $(EXEC)	
