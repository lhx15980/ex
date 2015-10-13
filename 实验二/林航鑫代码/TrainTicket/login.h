#ifndef _LOGIN_H_
#define _LOGIN_H_
#include <stdio.h>
#include "putString.h"
#include "goto.h"
#include "list.h"
typedef struct passenger
{
	char name[11];
	char pawd[7];
	char id[19];
}PSG_T;
#define IPSG sizeof(PSG_T)
void print_function();
void print_login();
void user_login(LIST_T*head);
void user_register(LIST_T*head);
void user_function();
int user_namemacth(char*name,void*data);
int sta_idmatch(char *id,void *data);
int user_id(char* id,LIST_T*head);
#endif