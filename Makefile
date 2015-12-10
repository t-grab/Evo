objects=algorithm.o

dynamic: $(objects)
	g++ -shared $(addprefix bin/,$?) -o libevo.so
	
static: $(objects)
	ar rcs libevo.a $(addprefix bin/,$?)
	
test: static test.o
	g++ bin/test.o -o test.exe -L. -levo
	
%.o : src/cpp/%.cpp
	g++ -c -std=c++11 -pthread -o bin/$@ $<