SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebavariaciones

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
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
