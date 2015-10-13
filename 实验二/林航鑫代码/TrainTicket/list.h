#ifndef _LIST_H_
#define _LIST_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct list
{
	void *data;
	struct list *pnext;
}LIST_T;
#define ILIST sizeof(LIST_T)
LIST_T* list_init();//初始化链表
int list_count(LIST_T*head);//计算节点数量
void  list_add(LIST_T* head,void*data);//尾插
void* list_search_id(int id,LIST_T*head,int (*fun)(int,void*));//按int型数据找到节点
void  list_print_page(LIST_T* head,int i,int j,void (*fun)(void *));//翻页打印
void  list_add_name(LIST_T* head,char *name,void*data,int (*fun)(char*,void *));//找到对应名字节点 插入
void  list_add_count(LIST_T* head,int i,void*data);//找到对应次序节点 插入
void* list_search_name(char *name,LIST_T*head,int (*fun)(char*,void*));
void list_modify(int id,LIST_T*head,int (*fun)(int,void*),void *data);
int list_login(int id,char*pawd,LIST_T*head,int (*fun)(int,char*,void*));
int list_delete(int id,LIST_T*head,int (*fun)(int,void*));//删除节点
void list_free(LIST_T*head);//释放链表
#endif