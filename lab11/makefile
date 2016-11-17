HEADERS = Clock.h Country.h Pokemon.h SortingList.h # header files
OBJECTS = Lab11.o Clock.o Country.o Pokemon.o SortingList.o # object files

Lab11: $(OBJECTS) #compile target
	g++ -std=c++11 -g $^ -o $@

%.o: %.cpp $(HEADERS) #compile object files
	g++ -std=c++11 -g -c $< -o $@

clean: # clean older builds
	rm -f *.o Lab11
