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

CODE:=$(shell pwd)
SRCDIR=$(CODE)/src
OBJDIR=../bin
SRC=$(shell find . -name "*.cpp" -not -path "*test*" -not -path "*common/src/UnitTest.cpp")
OBJ_SRC=$(SRC:.cpp=.o)

EXEC_SRC=prog
EXEC_TST=test

# Liste des fichiers objets :
#NOM = $(basename $(notdir $(SRC)))
#OBJ_TST=$(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))
OBJ_TST=$(TST:.cpp=.o) #$(OBJ_SRC)

projet=~/Bureau/projetPerso/chessE/src

all: $(EXEC_SRC) $(EXEC_TST)

$(EXEC_SRC): $(OBJ_SRC)
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC_TST): $(OBJ_TST)
	cd $(projet)/datas/test; 	make -f Makefile
	cd $(projet)/game/test;		make -f Makefile
	cd $(projet)/gui/test;		make -f Makefile
	cd $(projet)/common/test; 	make -f Makefile

.PHONY: cleanSimple clean 

cleanSimple:
	rm -rf $(OBJ_SRC)
	cd $(projet)/datas/test; 	make -f Makefile clean
	cd $(projet)/game/test; 	make -f Makefile clean
	cd $(projet)/gui/test; 	make -f Makefile clean
	cd $(projet)/common/test; 	make -f Makefile clean

clean: cleanSimple
	rm -rf $(EXEC_SRC) $(EXEC_TST)	
