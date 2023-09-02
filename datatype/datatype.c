#include <stdio.h>
#include "stdlib.h"
#include <time.h>
#include <string.h>

#define YEARS 5
#define SIZE 80
#define MONTHS 12
#define CH 10
#define LEN 20
struct names {
    char first[LEN];
    char last[LEN];
};

struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

struct namect {
    char *fname;  // using pointers
    char *lname;
    int letters;
};

void getinfo(struct namect *);        // allocates memory
void makeinfo(struct namect *);

void showinfo(const struct namect *);

void cleanup(struct namect *);        // free memory when done

enum spectrum {
    red, orange, yellow, green, blue, violet
};

char *mgets(char *st, int n);

void mfputs(const char *st);

int main() {
    /*
    //整型常量及变量定义、赋值、输出
    _Bool bo = 0;
    char ch1 = 'A';
    char ch2 = 'H';
    short sint = 99;
    int i = 979;
    unsigned int ui = 428U;
    long lint = 288L;
    long long llint = 466LL;
    unsigned long long ullint = 156LLU;
    printf("Enter a char to ch1:");
    scanf("%c", &ch1);
    getchar();
    printf("Enter a digit to (char)ch2:");
    scanf("%hhu", &ch2);
    getchar();
    printf("Enter a short integer to short:");
    scanf("%hd", &sint);
    getchar();
    printf("Enter a integer to int:");
    scanf("%d", &i);
    getchar();
    printf("Enter a unsigned integer to unsigned int ui:");
    scanf("%u", &ui);
    getchar();
    printf("Enter a long integer tolong:");
    scanf("%ld", &lint);
    getchar();
    printf("Enter a long long integer to long long:");
    scanf("%lld", &llint);
    getchar();
    printf("Enter a unsigned long long integer to unsigned long long ullint:");
    scanf("%llu", &ullint);
    getchar();
    printf("char ch = %c\n", ch1);
    printf("short sint = %hd\n", sint);
    printf("int i = %6d\n", i);
    printf("unsigned int ui = %u\n", ui);
    printf("long lint = %ld\n", lint);
    printf("long long llint = %lld\n", llint);
    printf("unsigned long long ullint = %llu\n", ullint);
    //%o与%x是非负的，所以等于%u
    printf("dec = %d, octal = %#o, hec = %#x \n", ui, ui, ui);
    printf("int has %zd bytes", sizeof(int));
    puts("-----------------------------------------------");

    //浮点型常量、变量及输入输出

    float f = 5.93f;
    double df = 7.68E6;
    long double ldf = 48.62L;
    printf("Enter a double to df:");
    scanf("%lf", &df);
    printf("Enter a long double to ldf:");
    scanf("%Lf", &ldf);
    printf("float f = %9.3f\n", f);
    printf("double df = %f, df(exp) = %e\n", df, df);
    printf("long double ldf = %Lf, ldf(exp) = %Le\n", ldf, ldf);
    puts("-----------------------------------------------");

    //数组：相同数据类型元素的聚集
    //基本数据类型数组的声明与初始化
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++) {
        printf("Month %2d has %2d days\n", i + 1, days[i]);
    }
    double rain[YEARS][MONTHS];
    srand((unsigned int) time(0));//time()包含在time.h中
    for (int i = 0; i < YEARS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            double val = rand() % 100;
            rain[i][j] = val / 5;//rand()包含在stdlib.h中
        }
    }
    for (int i = 0; i < YEARS; i++) {
        for (int j = 0; j < MONTHS; j++)
            printf("rain[%2d][%2d] is %4.2f    ", i, j, rain[i][j]);
    }
    puts("\n");
    //array + i == &array[i]
    //*(array + i) == array[i]
    //*(*(array+i)+j) == array[i][j]
    //指向多维数组的指针：int (*pz)[n];每一行有n个元素
    int zippo[4][2] = {{2, 4},
                       {6, 8},
                       {1, 3},
                       {5, 7}};
    int(*pz)[2];
    pz = zippo;

    printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
    */

    //字符串
    /*
    char name[40];
    printf("Enter your name:\n");
    scanf("%s", &name);//接受单个单词输入
    printf("Hello %s!\n", name);
    //字符串处理函数string.h
    printf("you name have %d letters\n", strlen(name));
    printf("you name use %zd bytes to save!\n", sizeof name);
    //双引号括起来的是字符串常量，静态存储不可修改，字符数组的形式是把字符串常量中的字符赋值给数组中的元素。字符串指针是指向静态存储的数组，所以使用const。数组名是指针常量，指针名是变量
    char words[] = "I am a string in an array.";//将静态全局区的字符串赋值给栈中的数组中
    const char *pt1 = "Something is pointing at me.";//指针指向静态全局区的字符串
    puts("Here are some strings:");
    puts(words);
    puts(pt1);

    //字符串输入gets(),fgets(),自定义sgets()
    //gets()的缺点是无法检测数组能否容纳输入的字符，读取全部字符后可能会覆盖原有数据
    //fgets()的缺点是从输入流读取一定量字符后，输入流中依然有一些字符等待读取
    char str[10];
    puts("Enter a string:");
    gets(str);
    puts(str);

    char str1[10];
    char str2[10];
    puts("Enter a string:");
    fgets(str1, 10, stdin);
    puts(str1);
    puts("Enter another string:");
    fgets(str2, 10, stdin);
    fputs(str2, stdout);
    //printf("\n");

    char str3[10];
    char str4[10];
    puts("Enter a string:");
    mgets(str3, 10);
    mfputs(str3);
    mgets(str4, 10);
    mfputs(str4);

    //字符串函数
    //strcat()
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    char copy[SIZE];

    puts("What's your favorite flower?");
    if (mgets(flower, SIZE)) {
        //if (strcmp(flower,addon)!=0)
        if (strncmp(flower, addon, 4) != 0) {
            //strcat(flower, addon);
            strncat(flower, addon, 20);
            puts(flower);
            puts(addon);
        } else {
            puts("error!");
        }

    } else {
        puts("End of file encountered!");
    }
    char *ps = strncpy(copy, addon + 2, 3);
    *(ps + 3) = '\0';
    puts(ps);

    //struct
    struct guy fellow[2] = {
            {{"Ewen",   "Villard"},
                    "grilled salmon",
                    "personality coach",
                    58112.00
            },
            {{"Rodney", "Swillbelly"},
                    "tripe",
                    "tabloid editor",
                    232400.00
            }
    };
    struct guy *him;    // here is a pointer to a structure

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];    //tell the pointer where to point
    printf("pointer #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);
    him++;                //point to the next structure
    printf("him->favfood is %s:  him->handle.last is %s\n", him->favfood, him->handle.last);

    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    union hold {
        int digit;
        double bigfl;
        char letter
    };
    union hold fit;
    fit.bigfl = 24;
    fit.digit = 23;
    printf("%f", fit.bigfl);
*/
    enum spectrum color;
    for (color = red; color <= violet; color++) {
        //puts(fit.digit);
        puts("gag");
    }

}

char *mgets(char *st, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else//已读取了n-1个字符，第n个字符设置为了\0，输入流中还有字符
            while (getchar() != '\n')//读取输入流中的剩余字符，直到\n，读取了\n，但不保存
                continue;
    }
    return ret_val;
}

void mfputs(const char *st) {
    fputs(st, stdout);
    int i = 0;
    while (st[i] != '\0') {
        i++;
    }
    if (st[i - 1] != '\n') {
        putc('\n', stdout);
    }
}

void getinfo(struct namect *pst) {
    char temp[81];
    printf("Please enter your first name.\n");
    gets(temp);
    // allocate memory to hold name
    pst->fname = (char *) malloc(strlen(temp) + 1);
    // copy name to allocated memory
    strcpy(pst->fname, temp);
    printf("Please enter your last name.\n");
    gets(temp);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void makeinfo(struct namect *pst) {
    pst->letters = strlen(pst->fname) +
                   strlen(pst->lname);
}

void showinfo(const struct namect *pst) {
    printf("%s %s, your name contains %d letters.\n",
           pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect *pst) {
    free(pst->fname);
    free(pst->lname);
}
