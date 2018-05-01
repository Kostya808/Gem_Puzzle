All: bin/gem 

bin/gem: build/main.o build/init.o build/shuffle.o build/check.o build/complexity.o build/interface.o
	gcc -Wall -o bin/gem build/main.o build/init.o build/shuffle.o build/check.o build/complexity.o build/interface.o -lncurses 	

build/main.o: src/main.c
	gcc -Wall -c src/main.c -o build/main.o
	
build/init.o: src/init.c
	gcc -Wall -c src/init.c -o build/init.o
	
build/shuffle.o: src/shuffle.c
	gcc -Wall -c src/shuffle.c -o build/shuffle.o
	
build/check.o: src/check.c
	gcc -Wall -c src/check.c -o build/check.o

build/complexity.o: src/complexity.c
	gcc -Wall -c src/complexity.c -o build/complexity.o

build/interface.o: src/interface.c
	gcc -Wall -c src/interface.c -o build/interface.o

.PHONY: clean
clean:
	rm -rf build/*.o
