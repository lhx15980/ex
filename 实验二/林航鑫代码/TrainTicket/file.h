#ifndef _FILE_H_
#define _FILE_H_
#include <stdio.h>
#include"list.h"
FILE* file_open(char *str);
void file_readall(FILE *fp,LIST_T*head,int size);
void file_writeall(LIST_T*head,int size,char *str);
#endif