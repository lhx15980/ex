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
LIST_T* list_init();//��ʼ������
int list_count(LIST_T*head);//����ڵ�����
void  list_add(LIST_T* head,void*data);//β��
void* list_search_id(int id,LIST_T*head,int (*fun)(int,void*));//��int�������ҵ��ڵ�
void  list_print_page(LIST_T* head,int i,int j,void (*fun)(void *));//��ҳ��ӡ
void  list_add_name(LIST_T* head,char *name,void*data,int (*fun)(char*,void *));//�ҵ���Ӧ���ֽڵ� ����
void  list_add_count(LIST_T* head,int i,void*data);//�ҵ���Ӧ����ڵ� ����
void* list_search_name(char *name,LIST_T*head,int (*fun)(char*,void*));
void list_modify(int id,LIST_T*head,int (*fun)(int,void*),void *data);
int list_login(int id,char*pawd,LIST_T*head,int (*fun)(int,char*,void*));
int list_delete(int id,LIST_T*head,int (*fun)(int,void*));//ɾ���ڵ�
void list_free(LIST_T*head);//�ͷ�����
#endif