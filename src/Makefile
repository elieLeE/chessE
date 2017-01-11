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

PROJECT=~/Bureau/projetPerso/chessE/src

all: $(EXEC_SRC) $(EXEC_TST) 

$(EXEC_SRC): $(OBJ_SRC)
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC_TST):
	cd $(PROJECT)/datas/test; 	make -f Makefile
	cd $(PROJECT)/game/test;	make -f Makefile
	cd $(PROJECT)/gui/test;		make -f Makefile
	#cd $(PROJECT)/testCPP; 	make -f Makefile test
	#cd $(projet)/common/test; 	make -f Makefile

.PHONY: cleanSimple clean 

cleanSimple:
	rm -rf $(OBJ_SRC)
	cd $(PROJECT)/datas/test; 	make -f Makefile clean
	cd $(PROJECT)/game/test; 	make -f Makefile clean
	cd $(PROJECT)/gui/test; 	make -f Makefile clean
	cd $(PROJECT)/common/test; 	make -f Makefile clean
	cd $(PROJECT)/testCPP; 	make -f Makefile clean

clean: cleanSimple
	rm -rf $(EXEC_SRC) $(EXEC_TST)
