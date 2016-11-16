HEADERS = Document.h # header files
OBJECTS = main.o Document.o # object files

myEditor: $(OBJECTS) #compile target
	g++ -std=c++11 -g $^ -o $@

%.o: %.cpp $(HEADERS) #compile object files
	g++ -std=c++11 -g -c $< -o $@

clean: # clean older builds
	rm -f *.o myEditor
