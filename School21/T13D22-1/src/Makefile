all: clean cipher

clean:
	rm -rf ../build/*.txt ../build/cipher

cipher:
	gcc -std=c11 -Wall -Werror -Wextra cipher.c logger.c -o ../build/cipher