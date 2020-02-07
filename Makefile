# this is a makefile of c++ project string
# the standerd c++ compiler in the ubuntu linux is g++
# written by damon on March 11th, 2014
CC :=clang++
CFLAGS :=-Wall -std=c++17 -O3
.PHONY: clean
all: ocp.o
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o
# # TARGET =.
# # CC =g++
# # CFLAGS =-g
# # CFLAGC =-c
# #
# # MAINC =main.cpp
# # STRING =String.cpp
# OBJ =String.o
#
# INCLUDE =-I$(TARGET)
# EXEC =$(TARGET)/main
#
# all: $(EXEC)
# $(EXEC): $(OBJ) $(MAINC)
# 	$(CC) $(CFLAGS) $(OBJ) S(MAIN) $(INCLUDE) -o $@
# 	rm -f $(OBJ)
# 	@rm -f $(OBJ)
# 	@echo "<<<<<< $@ is created successfunlly! >>>>>>"
# $(OBJ): $(STRING)
# 	$(CC) $(CFLAGC) $(STRING) -o $@
