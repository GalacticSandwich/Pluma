
SRC_DIR := ./src
INC_DIR := ./include
OBJ_DIR := ./obj
BIN_DIR := ./bin

CC := gcc
CFLAGS := -Wall -std=c99

ifeq ($(DEBUG), 1)
	OFLAGS := -g -D_DEBUG
else
	OFLAGS := -O2
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(OFLAGS) -I $(INC_DIR) -o $@ $^
