all: state_sort state_search clear_state

clean:
	rm -rf *.o ../build/Quest_*

state_sort: state_sort.c
	gcc -std=c11 -Wall -Werror -Wextra  -c state_sort.c -o state_sort.o
	gcc state_sort.o -o ../build/Quest_1

state_search:
	gcc -std=c11 -Wall -Werror -Wextra  -c state_search.c -o state_search.o
	gcc state_search.o -o ../build/Quest_2

clear_state:
	gcc -std=c11 -Wall -Werror -Wextra  -c clear_state.c -o clear_state.o
	gcc clear_state.o -o ../build/Quest_3

rebuild: clean state_sort state_search clear_state

.PHONY: all clean rebuild state_sort state_search clear_state