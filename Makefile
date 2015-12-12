objects=algorithm.o

dynamic: $(objects)
	g++ -shared $(addprefix bin/,$?) -o libevo.so
	
static: $(objects)
	ar rcs libevo.a $(addprefix bin/,$?)
	
test: test.o
	g++ -o test.exe bin/test.o
	
%.o : src/cpp/%.cpp
	g++ -c -std=c++11 -pthread -o bin/$@ $<