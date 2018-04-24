All: bin/gem 

bin/gem: build/main.o
	gcc -Wall -o bin/gem build/main.o  -lncurses 

build/main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o

library:
	sudo apt-get install libncursesw5-dev

.PHONY: clean
clean:
	rm -rf build/*.o