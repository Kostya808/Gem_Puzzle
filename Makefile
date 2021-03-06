All: bin/gem bin/test

test: bin/test
	bin/test

bin/gem: build/main.o build/init.o build/shuffle.o build/check.o build/complexity.o build/interface.o build/move.o build/win.o
	gcc -Wall -o bin/gem build/main.o build/init.o build/shuffle.o build/check.o build/complexity.o build/interface.o build/move.o build/win.o -lncurses 	

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

build/move.o: src/move.c
	gcc -Wall -c src/move.c -o build/move.o

build/win.o: src/win.c
	gcc -Wall -c src/win.c -o build/win.o

bin/test: build/test.o build/ctest.o build/check.o build/win.o build/init.o build/shuffle.o
	gcc -Wall -o bin/test build/test.o build/ctest.o build/win.o build/init.o build/check.o build/shuffle.o

build/test.o: test/test.c
	gcc -Wall -c test/test.c -o build/test.o -Ithirdparty -Isrc

build/ctest.o: test/ctest.c
	gcc -Wall -c test/ctest.c -o build/ctest.o -Ithirdparty

.PHONY: clean
clean:
	rm -rf build/*.o
