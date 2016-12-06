OBJECTS = main.o term.o autocomplete.o
HEADERS = term.h autocomplete.h

CS216PA3: $(OBJECTS)
	g++ -std=c++11 -g $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -std=c++11 -g -c $< -o $@

clean:
	rm -f *.o CS216PA3


