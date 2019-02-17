CXX = g++
CXX_FLAGS = -O3 -Wall -Wno-sign-compare -Wno-reorder -Wno-attributes -Wno-unknown-pragmas -Wno-unused-variable -shared -fPIC -std=c++11
CXX_FLAGS_NO_SHARED = -O3 -Wall -Wno-sign-compare -Wno-reorder -Wno-attributes -Wno-unknown-pragmas -Wno-unused-variable -std=c++11

MKDIR_P = mkdir -p

INC_DIR = include/
SRC_DIR = src/
OBJ_DIR = src/obj/

$(shell $(MKDIR_P) $(OBJ_DIR))

testInteger: $(OBJ_DIR)integer.o $(INC_DIR)integer.hpp
	$(CXX) $(CXX_FLAGS_NO_SHARED) $(SRC_DIR)testInteger.cpp $(OBJ_DIR)integer.o -I $(INC_DIR) -o testInteger

$(OBJ_DIR)integer.o: $(SRC_DIR)integer.cpp
	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)integer.cpp -I $(INC_DIR) -o $(OBJ_DIR)integer.o

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)*.o testInteger
