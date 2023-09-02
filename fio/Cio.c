#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SIZE 1024

int main() {
    FILE *fpa;
    FILE *fpb;

    char stringa[SIZE];
    char stringb[SIZE];
    //打开fa.txt
    if ((fpa = fopen("../fio/fa.txt", "r+")) == NULL) {
        fprintf(stdout, "Can't open \"fa.txt\".\n");
        exit(EXIT_FAILURE);
    }
    //打开fb.txt
    if ((fpb = fopen("../fio/fb.txt", "r+")) == NULL) {
        fprintf(stdout, "Can't open \"fb.txt\".\n");
        exit(EXIT_FAILURE);
    }
    /*
    //test fgets() fputs()
    fputs("test fputs() to fpa", fpa);
    fputs("test fputs() to fpb", fpb);
    rewind(fpa);
    rewind(fpb);
    if (fgets(stringa, 30, fpa) != NULL) {
        puts(stringa);
        if (feof(fpa))
            puts("ending");
    }
    if (fgets(stringb, sizeof(stringb), fpb) != NULL)
        puts(stringb);

    rewind(fpa);
    rewind(fpb);

    char str1[] = "test fwrite() to fpa.";
    char str2[] = "test fwrite() to fpb.";
    fwrite(str1, strlen(str1), 1, fpa);
    fwrite(str2, strlen(str2), 1, fpb);
    rewind(fpa);
    rewind(fpb);
    fread(stringa, sizeof(stringa), 1, fpa);
    puts(stringa);
    fread(stringb, sizeof(stringb), 1, fpb);
    puts(stringb);
*/
    /*
    char str3[] = "test fprintf() to fpa.";
    char str4[] = "test fprintf() to fpb.";
    fprintf(fpa, "%s\n", str3);
    fprintf(fpb, "%s\n", str4);
    rewind(fpa);
    rewind(fpb);
    fscanf(fpa, "%s", stringa);
    fscanf(fpb, "%s", stringb);
    puts(stringa);
    puts(stringb);

    rewind(fpa);
    rewind(fpb);
    char ch = 'Q';
    fputc(ch, fpa);
    rewind(fpa);
    char ch2 = fgetc(fpa);
    putchar(ch2);
*/
    fclose(fpa);
    fclose(fpb);
    return 0;
}