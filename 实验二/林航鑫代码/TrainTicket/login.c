#include "login.h"
void print_function()
{
	system("cls");
	printf("--------------------------------------------------------------------------------");
	printf("                         ���Զ���Ʊϵͳ                                       ");
	printf("--------------------------------------------------------------------------------");
	printf("                       ->1.����                                                 ");
	printf("                         2.ע��                                                 ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("    ȷ��[Enter]                                           �˳�[Esc]             ");
}
void print_login()
{
	system("cls");
    printf("--------------------------------------------------------------------------------");
	printf("                              �û��������                                      ");
	printf("--------------------------------------------------------------------------------");
	printf("                   �û���:                                                      ");
	printf("                                                                                ");
	printf("                   ��  ��:                                                      ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("    ȷ��[Enter]                                           �˳�[Esc]             ");
}
void print_register()
{
	system("cls");
    printf("--------------------------------------------------------------------------------");
	printf("                              �û�ע�����                                      ");
	printf("--------------------------------------------------------------------------------");
	printf("               ��  ��  ��:                                                      ");
	printf("                                                                                ");
	printf("               ��      ��:                                                      ");
	printf("                                                                                ");
	printf("               ȷ��  ����:                                                      ");
	printf("                                                                                ");
	printf("               ���֤����:                                                     ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("                                                                                ");
	printf("    ȷ��[Enter]                                           �˳�[Esc]             ");
}
void user_login(LIST_T*head)
{
	int get;
	char acname[11]=" ",acpwd[7]=" ";
	print_login();
	gotoXY(26,3);
	get=glb_putString(acname,3,10,1);
	if(get==27)
	{
		return;
	}
	gotoXY(26,5);
	get=glb_putString(acpwd,1,6,0);
	if(get==27)
	{
		return;
	}
	if(strcmp(acname,"admin")==0&&strcmp(acpwd,"123456")==0)
	{
		printf("\nadmin");
		system("pause");
	}
	else
	{
		if(strcmp(((PSG_T*)list_search_name(acname,head,user_namemacth))->pawd,acpwd)==0)
			printf("OK");
		system("pause");
	}
}
void user_register(LIST_T*head)
{
	int get;
	PSG_T*data;
	char temppwd[7]=" ";
	data=(PSG_T*)malloc(IPSG);
	print_register();
	while (1)
	{
		gotoXY(26,3);
		printf("             ");
		gotoXY(26,3);
		get=glb_putString(data->name,3,10,1);
		if(get==27)
		{
			return;
		}
		if(list_search_name(data->name,head,user_namemacth)!=NULL||strcmp(data->name,"admin")==0)//����NULL˵���Ѿ�����ͬ������
		{
			gotoXY(20,11);
			printf("�Ѿ�������ͬ���û���������������");
			Sleep(1000);
			gotoXY(20,11);
			printf("                                ");
		}
		else
		{
			break;
		}
	}
	while(1)
	{
		gotoXY(26,5);
		printf("             ");
		gotoXY(26,7);
		printf("             ");
		gotoXY(26,5);
		get=glb_putString(data->pawd,1,6,0);
		if(get==27)
		{
			return;
		}
		gotoXY(26,7);
		get=glb_putString(temppwd,1,6,0);
		if(get==27)
		{
			return;
		}
		if(strcmp(temppwd,data->pawd)==0)
		{
			break;
		}
	}
	while (1)
	{
		gotoXY(26,9);
		printf("                                   ");
		gotoXY(26,9);
		get=glb_putString(data->id,1,18,1);
		if(get==27)
		{
			return;
		}
		if(user_id(data->id,head)!=0)
		{
			break;
		}
		else
		{
			gotoXY(10,11);
			printf("������Ϸ������֤�ţ������ظ�ʹ�����֤��");
			Sleep(1000);
			gotoXY(10,11);
			printf("                                          ");
		}
	}


	list_add(head,data);
	gotoXY(28,11);
	printf("����ÿͳɹ�");
	Sleep(1000);
}

void user_function()
{
	int get;
	LIST_T*user_head;
	FILE*user_fp;
	user_fp=file_open("user.txt");
	user_head=list_init();
	file_readall(user_fp,user_head,IPSG);
	while(1)
	{
		print_function();
		get=modify_direction(23,3,4);
		switch(get)
		{
		case 3:
			{
				user_login(user_head);
				break;
			}
		case 4:
			{
				user_register(user_head);
				break;
			}
		case 27:
			{
				file_writeall(user_head,IPSG,"user.txt");
				exit(0);
			}
		default :
			{
				break;
			}
		}
	}
}

int user_namemacth(char*name,void*data)
{
	if(strcmp(name,((PSG_T*)(data))->name)==0)
	{
		return 1;
	}
	else return 0;
}

int sta_idmatch(char *id,void *data)
{
	if(strcmp(((PSG_T*)(data))->id,id)==0)
		return 1;
	else 
		return 0;
}

int user_id(char* id,LIST_T*head)
{
	if(strlen(id)!=18)
		return 0;
	if(list_search_name(id,head,sta_idmatch)==NULL)
	{
		return 1;
	}
	else 
		return 0;
}
