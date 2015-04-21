SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all:$(BIN)/testocultar $(BIN)/testrevelar 

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
		
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h 
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o	

	
$(BIN)/testocultar: $(OBJ)/testocultar.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/utilidades.o
	$(CXX) -o $(BIN)/testocultar  $(OBJ)/testocultar.o $(OBJ)/imagen.o $(OBJ)/utilidades.o $(OBJ)/imagenES.o	

	
	
$(BIN)/testrevelar: $(OBJ)/testrevelar.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/utilidades.o
	$(CXX) -o $(BIN)/testrevelar  $(OBJ)/testrevelar.o $(OBJ)/imagen.o $(OBJ)/utilidades.o $(OBJ)/imagenES.o	
	
	
$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/imagen.h $(INC)/utilidades.h 
	$(CXX) $(CPPFLAGS) $(SRC)/utilidades.cpp -o $(OBJ)/utilidades.o	
	
	
$(OBJ)/testocultar.o: $(SRC)/testocultar.cpp $(INC)/imagen.h $(INC)/utilidades.h 
	$(CXX) $(CPPFLAGS) $(SRC)/testocultar.cpp -o $(OBJ)/testocultar.o		

	
$(OBJ)/testrevelar.o: $(SRC)/testrevelar.cpp $(INC)/imagen.h $(INC)/utilidades.h 
	$(CXX) $(CPPFLAGS) $(SRC)/testrevelar.cpp -o $(OBJ)/testrevelar.o		
	
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
