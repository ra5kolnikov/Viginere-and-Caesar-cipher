build=gcc -Wall -Werror -Wextra

all: caesar viginere

caesar: 
	$(build) caesar.c -o caesar

viginere: 
	$(build) viginere.c -o viginere

clean: 
	rm -rf caesar viginere

rebuild: clean all