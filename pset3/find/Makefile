#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

# make all files
all: find generate

# make find and helpers.c and helpers.h
find: find.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

# all compiled files will be deleded
clean:
	rm -f *.o a.out core find generate