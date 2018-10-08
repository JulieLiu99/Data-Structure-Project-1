myspeller: myspeller.o function.o 
	g++ myspeller.o function.o -o myspeller
speller.o: myspeller.cpp
	g++ -c myspeller.cpp
function.o: function.cpp function.h
	g++ -c function.cpp
clean:
	rm *.o myspeller

