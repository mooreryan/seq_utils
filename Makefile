CFLAGS = -Wall -g -std=c11 -lm
DEPS = utilities.c

clean_and_flatten: clean_and_flatten.c $(DEPS)
	gcc $(CFLAGS) -o clean_and_flatten clean_and_flatten.c $(DEPS)
