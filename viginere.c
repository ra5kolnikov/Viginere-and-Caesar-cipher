#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key_to_num (int key);

int main(int argc, char* argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Not enough arguments\n");
		return 1;
	}
	if(argc > 2) {
		fprintf(stderr, "Too many arguments\n");
		return 1;
	}

	int key[101] = {0};
	int key_max = 0;

	for (int i = 0, n = strlen(argv[1]); i < n; ++i) {
		key[i] = key_to_num(argv[1][i]);
		if (i == n - 1) key_max = i + 1;
	}

	char str[101] = {'0'};
	printf("Enter string for cipher: ");
	fgets(str, 100, stdin);

	for (int i = 0, j = 0, n = strlen(str); i < n; ++i) {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) {
			str[i] = 'A' + ((str[i] - 'A' + key[j % key_max]) % 26);
			j++;
		} else if ((str[i] >= 'a') && (str[i] <= 'z')) {
			str[i] = 'a' + ((str[i] - 'a' + key[j % key_max]) % 26);
			j++;
		}
	}
    str[strlen(str) - 1] = 0;
	printf("Cipher string is: %s", str);
}

int key_to_num (int key) {
	if ((key >= 'A') && (key <= 'Z')) {
			key = key - 'A';
		} else if ((key >= 'a') && (key <= 'z')) {
			key = key - 'a';
		}
	return key;
}
