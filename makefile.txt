CFLAGS = -Wall -Werror
SOURCES = src/main.cpp
OBJECTS = build/main.o

.PHONY: clean all Kurswork test

all :
	make bin/Kurswork

bin/Kurswork : $(OBJECTS)
	g++ main.o -o bin/Kurswork $(CFLAGS)

build/main.o : $(SOURCES)
	g++ -c src/main.cpp -o build/main.o $(CFLAGS)


clean : 
	@rm -rf build/*.o build/test/*.o
	@rm bin/Kurswork  bin/Kurswork-test
	@echo "All files have been cleaned."
