SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g  -I$(INC) -c


all: $(BIN)/letras_backtracking
branch: $(BIN)/letras_branch
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) $(SRC)/utilidades.cpp -o $(OBJ)/utilidades.o

$(BIN)/letras_backtracking: $(OBJ)/variaciones.o $(OBJ)/letras_backtracking.o $(OBJ)/utilidades.o
	$(CXX) -o $(BIN)/letras_backtracking  $(OBJ)/letras_backtracking.o $(OBJ)/variaciones.o $(OBJ)/utilidades.o
$(BIN)/letras_branch: $(OBJ)/variaciones.o $(OBJ)/letras_branch.o $(OBJ)/utilidades.o
	$(CXX) -o $(BIN)/letras_branch  $(OBJ)/letras_branch.o $(OBJ)/variaciones.o $(OBJ)/utilidades.o

$(OBJ)/letras_backtracking.o: $(SRC)/letras_backtracking.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/letras_backtracking.cpp -o $(OBJ)/letras_backtracking.o

$(OBJ)/letras_branch.o: $(SRC)/letras_branch_and_bound.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/letras_branch_and_bound.cpp -o $(OBJ)/letras_branch.o

$(BIN)/pruebavariaciones: $(OBJ)/variaciones.o $(OBJ)/pruebavariaciones.o
	$(CXX) -o $(BIN)/pruebavariaciones  $(OBJ)/pruebavariaciones.o $(OBJ)/variaciones.o

$(OBJ)/pruebavariaciones.o: $(SRC)/pruebavariaciones.cpp $(INC)/variaciones.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebavariaciones.cpp -o $(OBJ)/pruebavariaciones.o
$(OBJ)/variaciones.o: $(SRC)/variaciones.cpp $(INC)/variaciones.h
	$(CXX) $(CPPFLAGS) $(SRC)/variaciones.cpp -o $(OBJ)/variaciones.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
