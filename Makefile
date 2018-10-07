output: myspeller.o function.o 
	g++ myspeller.o function.o -o output
speller.o: myspeller.cpp
	g++ -c myspeller.cpp
myqueue.o: function.cpp function.h
	g++ -c function.cpp
clean:
	rm *.o output

