HEADERS = converter.h stack.h LinkedList.h bound_err.h
OBJECTS = Lab8.o converter.o stack.o LinkedList.o

Lab8: $(OBJECTS)
	g++ -g $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -g -c $< -o $@

clean:
	rm -f *.o Lab8
