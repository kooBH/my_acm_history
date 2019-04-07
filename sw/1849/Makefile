#define customized suffixes
.SUFFIXES : .cpp .o

#Macro for objects
OBJ = DisjointSetOnly.cpp  

#output file
TARGET = a 

#make method
CXX = g++

#flag for g++ #use CFLAGS for gcc -I: including dictionary
CXXFLAGS = -c -Idic/

$(TARGET) : $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

#remove used object files
clean :
	rm -rf $(OBJ) $(TARGET) core
