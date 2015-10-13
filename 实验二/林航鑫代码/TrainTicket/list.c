#include "list.h"
LIST_T* list_init()
{
	LIST_T *head;
	head=(LIST_T *)malloc(ILIST);
	if(head==NULL)
	{
		return NULL;
	}
	memset(head,0,ILIST);
	head->pnext=NULL;
	//head->data=data;
	return head;
}
int list_count(LIST_T*head)
{
	int i=0;
	LIST_T*temp=head;
	while(temp->pnext!=NULL)
	{
		i++;
		temp=temp->pnext;
	}
	return i;
}

void  list_add(LIST_T* head,void*data)
{
	LIST_T*newlist;
	LIST_T*temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
	}
	newlist=(LIST_T *)malloc(ILIST);
	if(newlist==NULL)
	{
		return ;
	}
	memset(newlist,0,ILIST);
	newlist->data=data;
	newlist->pnext=NULL;
	temp->pnext=newlist;
}

void  list_add_count(LIST_T* head,int i,void*data)//在第i个节点后插入
{
	LIST_T*newlist;
	LIST_T*temp=head;
	int icount=0;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		icount++;
		if(icount==i)//找到第i个节点跳出
		{
			break;
		}
	}
	newlist=(LIST_T *)malloc(ILIST);
	if(newlist==NULL)
	{
		return ;
	}
	memset(newlist,0,ILIST);
	newlist->data=data;
	newlist->pnext=temp->pnext;//将原本第i+1个节点作为新节点的后继
	temp->pnext=newlist;
}

void  list_add_name(LIST_T* head,char *name,void*data,int (*fun)(char*,void *))//类似 list_search_name
{
	LIST_T*newlist;
	LIST_T*temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(name,temp->data))//找到符合条件的节点跳出
		{
			break;
		}
	}
	newlist=(LIST_T *)malloc(ILIST);
	if(newlist==NULL)
	{
		return ;
	}
	memset(newlist,0,ILIST);
	newlist->data=data;
	newlist->pnext=temp->pnext;
	temp->pnext=newlist;
}

void  list_print_page(LIST_T* head,int i,int j,void (*fun)(void *))
{
	LIST_T *temp=head;
	while (i--)
	{
		temp=temp->pnext;
	}
	while(j--)
	{
		temp=temp->pnext;
		fun(temp->data);
		if(temp->pnext==NULL)
			break;
	}
}

void  list_print_all(LIST_T* head,void (*fun)(void *))
{
	LIST_T *temp=head;

	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		fun(temp->data);
	}
}

void* list_search_id(int id,LIST_T*head,int (*fun)(int,void*))
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(id,temp->data))
			return temp->data;
	}
	return NULL;
}
void* list_search_name(char *name,LIST_T*head,int (*fun)(char*,void*))
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(name,temp->data))
			return temp->data;
	}
	return NULL;
}
int list_login(int id,char*pawd,LIST_T*head,int (*fun)(int,char*,void*))
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(id,pawd,temp->data)!=100)
		{
			return fun(id,pawd,temp->data);
		}
		
	}
	return 100;//100就代表错误
}
int list_delete(int id,LIST_T*head,int (*fun)(int,void*))
{
	LIST_T*temp=head;
	LIST_T*ptemp=head;
	while (temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(id,temp->data))//匹配
		{
			ptemp->pnext=temp->pnext;
			free(temp);
			return 1;
		}
		ptemp=temp;
	}
	return 0;
}
void list_free(LIST_T*head)
{
	LIST_T*temp;
	while(head->pnext!=NULL)
	{
		temp=head->pnext;
		head->pnext=temp->pnext;
		free(temp);
	}
	free(head);
}
void list_modify(int id,LIST_T*head,int (*fun)(int,void*),void *data)
{
	LIST_T *temp=head;
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		if(fun(id,temp->data))
		{
			temp->data=data;
			return;
		}
	}
	return ;
}