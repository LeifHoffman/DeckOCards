SRC = main_folder/card.c main_folder/deck.c main_folder/main.c war/war.c directions/directions.c

main: $(SRC)
	mkdir -p build
	gcc -Wall $(SRC) -o build/main

clean:
	rm -rf build