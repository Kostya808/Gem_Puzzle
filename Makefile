All: bin/gem 

bin/gem: build/main.o build/init.o build/shuffle.o build/check.o
	gcc -Wall -o bin/gem build/main.o build/init.o build/shuffle.o build/check.o  -lncurses 
	

build/main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o
	
build/init.o: src/init.c
	gcc -Wall -c src/init.c -o build/init.o
	
build/shuffle.o: src/shuffle.c
	gcc -Wall -c src/shuffle.c -o build/shuffle.o
	
build/check.o: src/check.c
	gcc -Wall -c src/check.c -o build/check.o

library:
	sudo apt-get install libncursesw5-dev

.PHONY: clean
clean:
	rm -rf build/*.o
