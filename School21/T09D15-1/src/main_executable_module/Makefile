CC=gcc
CFLAGS=-c -std=c11 -Wall -Werror
LDFLAGS=
SOURCES=main_executable_module.c ../data_libs/data_io.c ../yet_another_decision_module/decision.c ../data_module/data_process.c ../data_libs/data_stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../../build/Quest_3

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) | $(dir $(EXECUTABLE))
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(dir $(EXECUTABLE)):
	mkdir -p $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

clean_o:
	rm -rf $(OBJECTS)

rebuild: clean all

data_stat.a:
	rm -rf ../data_libs/data_stat.a ../data_libs/data_stat.o
	gcc -std=c11 -Wall -Werror -Wextra -c ../data_libs/data_stat.c -o ../data_libs/data_stat.o
	ar rcs ../data_libs/data_stat.a ../data_libs/data_stat.o

build_with_static:
	data_stat.a
	gcc main_executable_module.o ../data_libs/data_io.o ../yet_another_decision_module/decision.o ../data_module/data_process.o -L ../data_libs -ldata_stat -o ../../build/Quest_5

ddd:
	$(CC) -c -Wall -Werror -Wextra -fPIC  $(OBJECTS) -o $@


data_process.so:
	gcc -c -Wall -Werror -Wextra -fPIC  ../data_module/data_process.c
	gcc -shared -o ../data_module/data_process.so ../data_module/data_process.o ../data_libs/data_stat.o -lm

build_with_dynamic:
	gcc -DUSE_DYNAMIC_LIB main_executable_module.o ../data_libs/data_io.o ../yet_another_decision_module/decision.o ../data_module/data_process.so -o ../../build/Quest_6 


