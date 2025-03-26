CC=gcc
CFLAGS=-c -std=c11 -Wall -Werror -Wextra
BUILD_DIR=../build
SOURCES=dmanager_module.c list.c list_test.c stack_test.c stack.c
OBJECTS=$(SOURCES:.c=.o)

$(shell mkdir -p $(BUILD_DIR))

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

all: clean door_struct list_test stack_test
	rm -rf *.o

clean:
	rm -rf *.o
	rm -fr $(BUILD_DIR)/Quest_*

door_struct: dmanager_module.o	
	$(CC) dmanager_module.o -o $(BUILD_DIR)/Quest_1

list_test:	list.o list_test.o
	$(CC) list.o list_test.o -o $(BUILD_DIR)/Quest_2

stack_test:	stack_test.o stack.o
	$(CC) stack_test.o stack.o -o $(BUILD_DIR)/Quest_3