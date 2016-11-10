HEADERS = Matrix.h
OBJECTS = Lab10.o Matrix.o

Lab10: $(OBJECTS)
	g++ -g $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -g -c $< -o $@

clean:
	rm -f *.o Lab10
