# Name of the project
PROJ_NAME=morse

# Directories
SRC_DIR=./src
INC_DIR=./include
OBJ_DIR=./obj

# .c files
C_SOURCE=$(wildcard $(SRC_DIR)/*.c)

# .h files
H_SOURCE=$(wildcard $(INC_DIR)/*.h)

# Object files
OBJ=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCE))

# Compiler and linker
CC=gcc

# Flags for compiler
CC_FLAGS=-c -W -Wall -ansi -pedantic -I$(INC_DIR) -std=c99

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: objFolder $(OBJ_DIR)/$(PROJ_NAME) run

$(OBJ_DIR)/$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

$(OBJ_DIR)/functions.o: $(SRC_DIR)/functions.c $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p $(OBJ_DIR)

run:
	@ clear
	@./$(OBJ_DIR)/$(PROJ_NAME).exe

clean:
	@ $(RM) $(OBJ_DIR)/*.o $(PROJ_NAME) *~
	@ rmdir $(OBJ_DIR)

.PHONY: all clean
