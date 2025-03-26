CC=gcc
CFLAGS=-c -std=c11 -Wall -Werror -Wextra
BUILD_DIR=../build
SOURCES= print_module.c documentation_module.c
OBJECTS=$(SOURCES:.c=.o)

$(shell mkdir -p $(BUILD_DIR))

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

all: clean print_module documentation_module bst_create_test

clean:
	rm -rf *.o
	rm -fr $(BUILD_DIR)/Quest_*

print_module: $(OBJECTS)
	$(CC) $(CFLAGS) -DPRINT_MODULE -DPRINT_MODULE1 main_module_entry_point.c -o main_module_entry_point.o
	$(CC) main_module_entry_point.o print_module.o documentation_module.o -o $(BUILD_DIR)/Quest_1

documentation_module:$(OBJECTS)
	$(CC) $(CFLAGS) -DDOC_MODULE -DDOC_MODULE1 main_module_entry_point.c -o main_module_entry_point.o
	$(CC) main_module_entry_point.o print_module.o documentation_module.o -o $(BUILD_DIR)/Quest_2

bst_create_test:
	$(CC) $(CFLAGS) bst.c -o bst.o
	$(CC) $(CFLAGS) bst_creat.c -o bst_creat.o
	$(CC) bst_creat.o bst.o -o $(BUILD_DIR)/Quest_3