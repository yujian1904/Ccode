//
// Created by dcfhospitalcgb on 2023/8/28.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char showmenu(void) {
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase       l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = getchar();    // get response
    ans = tolower(ans); // convert to lowercase
    eatline();          // dispose of rest of line
    while (strchr("ulton", ans) == NULL) {
        puts("Please enter a u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void eatline(void) {
    while (getchar() != '\n')
        continue;
}

void ToUpper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char *str) {
    while (*str) {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

void Dummy(char *str) {
    // leaves string unchanged
}

void show(void (*fp)(char *), char *str) {
    (*fp)(str); // apply chosen function to str
    puts(str);  // display result
}