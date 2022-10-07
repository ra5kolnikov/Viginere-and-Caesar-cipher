#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void get_string(char *str);

int main(int argc, char *argv[]) {
    int flag = 0;
    if (argc == 2) {
        int k = atoi(argv[1]);
        char str[1000];
        int tmp;
        printf("Enter a text for encrypt\n");
        get_string(str);
        for (int i = 0; i < (int)strlen(str); i++) {
            if (isalpha(str[i])) {
                if (isupper(str[i])) {
                    tmp = ((int)str[i] - 65 + k) % 26 + 65;
                    str[i] = (char)tmp;
                } else if (islower(str[i])) {
                    tmp = ((int)str[i] - 97 + k) % 26 + 97;
                    str[i] = (char)tmp;
                }
            }
        }
        for (int i = 0; i < (int)strlen(str); i++) {
            printf("%c", str[i]);
        } 
    } else {
        printf("print the key next time \n");
        flag = 1;
    }
    return flag;
}

void get_string(char *str) {
    int cnt = 0;
    while (str[cnt - 1] != '\n') {
        scanf("%c", &str[cnt]);
        cnt++;
    }
    str[cnt - 1] = 0;
}
