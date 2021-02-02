CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c -std=c++14 $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile:	main.out

main.out:	main.o	ItemType.o	BinaryTree.o
	$(CC)	$(LFLAGS)	-o	main.out	main.o	ItemType.o	BinaryTree.o

main.o:	main.cpp	ItemType.o	BinaryTree.o
	$(CC)	$(CFLAGS)	main.cpp

ItemType.o:	ItemType.cpp	ItemType.h
	$(CC)	$(CFLAGS)	ItemType.cpp

BinaryTree.o:	BinaryTree.cpp	BinaryTree.h
	$(CC)	$(CFLAGS)	BinaryTree.cpp

run:	main.out
	./main.out	input.txt

clean:
	rm *.o
	rm *.out
