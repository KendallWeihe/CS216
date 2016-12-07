#object files
OBJECTS = main.o term.o autocomplete.o
#header files
HEADERS = term.h autocomplete.h

#target program
CS216PA3: $(OBJECTS)
	g++ -std=c++11 -g $^ -o $@

#compile and keep track of object files
%.o: %.cpp $(HEADERS)
	g++ -std=c++11 -g -c $< -o $@

#clean the object files and target program
clean:
	rm -f *.o CS216PA3
