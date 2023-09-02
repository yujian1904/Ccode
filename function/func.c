//function、statement、运算符
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "head.h"

int main() {
    int count = 0;
    while (count <= 9) {
        printf("%d\n", count++);
    }
    puts("-----------------------------");

    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    puts("-----------------------------");

    do {
        printf("%d\n", --count);
    } while (count > 0);
    puts("-----------------------------");

    srand((unsigned int) time(0));
    count = rand() % 100;
    while (count > 20) {
        if (count < 50) {
            printf("count < 50,count is %d\n", count);
        } else if (count < 80) {
            printf("count < 80,count is %d\n", count);
        } else {
            printf("count > 80,count is %d\n", count);
        }
        count = rand() % 100;
    }
    puts("-----------------------------");

    char ch;
    puts("Enter a char:");
    while ((ch = getchar()) != '#') {
        if ('\n' == ch)
            continue;
        if (islower(ch))     /* lowercase only          */
            switch (ch) {
                case 'a':
                    printf("argali, a wild sheep of Asia\n");
                    break;
                case 'b':
                    printf("babirusa, a wild pig of Malay\n");
                    break;
                case 'c':
                    printf("coati, racoonlike mammal\n");
                    break;
                case 'd':
                    printf("desman, aquatic, molelike critter\n");
                    break;
                case 'e':
                    printf("echidna, the spiny anteater\n");
                    break;
                case 'f':
                    printf("fisher, brownish marten\n");
                    break;
                default:
                    printf("That's a stumper!\n");
            }                /* end of switch           */
        else
            printf("I recognize only lowercase letters.\n");
        while (getchar() != '\n')
            continue;      /* skip rest of input line */
        printf("Please type another letter or a #.\n");
    }                        /* while loop end          */
    getchar();
    char line[81];
    char copy[81];
    char choice;
    void (*pfun)(char *); // points a function having a
    // char * argument and no
    // return value
    puts("Enter a string (empty line to quit):");
    while (gets(line) != NULL && line[0] != '\0') {
        while ((choice = showmenu()) != 'n') {
            switch (choice)  // switch sets pointer
            {
                case 'u':
                    pfun = ToUpper;
                    break;
                case 'l':
                    pfun = ToLower;
                    break;
                case 't':
                    pfun = Transpose;
                    break;
                case 'o':
                    pfun = Dummy;
                    break;
            }
            strcpy(copy, line);// make copy for show()
            show(pfun, copy);  // use selected function
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");


    return 0;
}

