/*
Regular expression: a*bb also do for a+bb
accept char string
ensure input is terminated with new line character
write code in c
Testcases:
aaabb ok
Abab not ok
^, bbbb,aaa ,baaabb, aaabbb,baaabb, aaaab, abb,aaaaabb
*/
#include <stdio.h>
int isValid_a_star_bb(const char *str) {
    int i = 0;

    while (str[i] == 'a') {
        i++;
    }

    if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == '\0') {
        return 1;
    }

    return 0;
}

int isValid_a_plus_bb(const char *str) {
    int i = 0;
    if (str[i] != 'a') {
        return 0;
    }
    while (str[i] == 'a') {
        i++;
    }
    if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == '\0') {
        return 1;
    }
    return 0;
}

int main() {
    char str[50];
    int i = 0, c;
    printf("Enter string: ");
    for (i = 0; i < 49; i++) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        str[i] = c;
    }
    str[i] = '\0';
    int validForStar = isValid_a_star_bb(str);
    int validForPlus = isValid_a_plus_bb(str);

    if (validForStar && validForPlus) {
        printf("Valid for both a*bb and a+bb\n");
    } else if (validForStar) {
        printf("Valid for a*bb\n");
    } else if (validForPlus) {
        printf("Valid for a+bb\n");
    } else {
        printf("Invalid input\n");
    }
    return 0;
}