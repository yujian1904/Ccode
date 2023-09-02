//
// Created by dcfhospitalcgb on 2023/8/28.
//

#ifndef CPRO_HEAD_H
#define CPRO_HEAD_H

char showmenu(void);

void eatline(void);     // read through end of line
void show(void (*fp)(char *), char *str);

void ToUpper(char *);   // convert string to uppercase
void ToLower(char *);   // convert string to uppercase
void Transpose(char *); // transpose cases
void Dummy(char *);     // leave string unaltered
#endif //CPRO_HEAD_H
