MAIN_FILES = card.c card.h deck.c deck.h main.c
MAIN = card.c deck.c main.c

main: $(MAIN_FILES)
	gcc -Wall $(MAIN) -o main

clean:
	rm *.o main