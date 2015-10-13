#include"file.h"
FILE* file_open(char *str)
{
	FILE *fp;
	fp=fopen(str,"r+");
	if(fp==NULL)
	{
		fp=fopen(str,"w+");
		if(fp==NULL)
		{
			return NULL;
		}
	}
	return fp;
}

void file_readall(FILE *fp,LIST_T*head,int size)
{
	void *newsta;
	newsta=(void*)malloc(size);
	memset(newsta,0,size);
	rewind(fp);
	while(fread(newsta,size,1,fp)>0)
	{
		list_add(head,newsta);
		newsta=(void*)malloc(size);
		memset(newsta,0,size);
	}
}

void file_writeall(LIST_T*head,int size,char *str)
{
	FILE *fp=fopen(str,"w+");
	LIST_T*temp=head;
	fp=fopen(str,"w+");
	rewind(fp);
	while(temp->pnext!=NULL)
	{
		temp=temp->pnext;
		fwrite(temp->data,size,1,fp);
		fflush(fp);
	}
}