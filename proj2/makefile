HEADERS = Document.h
OBJECTS = main.o Document.o

myEditor: $(OBJECTS)
	g++ -std=c++11 -g $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -std=c++11 -g -c $< -o $@

clean:
	rm -f *.o myEditor
