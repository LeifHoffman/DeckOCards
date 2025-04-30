###############################
#
# Makefile for this program.
#
###############################

BUILD_DIR = build
SRC = main_folder/card.c main_folder/deck.c main_folder/main.c 
EXTRA = war/war.c scoundrel/scoundrel.c directions/directions.c

main: $(SRC) $(EXTRA)
	mkdir -p $(BUILD_DIR)
	gcc -Wall $(SRC) $(EXTRA) -o $(BUILD_DIR)/main

clean:
	rm -rf $(BUILD_DIR)