CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
BUILD_DIR=../build
SOURCES=s21_string.c s21_string_test.c
OBJECTS=$(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Создаем директорию для сборки, если ее нет
$(shell mkdir -p $(BUILD_DIR))

clean:
	rm -rf s21_string.o s21_string_test.o

strlen_tests:
	$(CC) $(CFLAGS) s21_string.c
	$(CC) $(CFLAGS) -DSTRLN_TEST s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_1

strcmp_tests:
	$(CC) $(CFLAGS) s21_string.c
	$(CC) $(CFLAGS) -DSTRCMP_TEST s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_2

strcpy_tests:
	$(CC) $(CFLAGS) s21_string.c
	$(CC) $(CFLAGS) -DSTRCPY_TEST s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_3

strcat_tests:
	$(CC) $(CFLAGS) s21_string.c
	$(CC) $(CFLAGS) -DSTRCAT_TEST s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_4

strchr_tests:
	$(CC) $(CFLAGS) s21_string.c
	$(CC) $(CFLAGS) -DSTRCHR_TEST s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_5

strstr_tests:
	$(CC) $(CFLAGS) s21_string.c
	$(CC) $(CFLAGS) -DSTRSTR_TEST s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_6

strtok_tests:
	$(CC) $(CFLAGS) s21_string.c
	$(CC) $(CFLAGS) -DSTRTOK_TEST s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o ../build/Quest_7

all:strlen_tests strcmp_tests strcpy_tests strcat_tests strcat_tests strchr_tests strstr_tests strtok_tests clean