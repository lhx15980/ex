#include"putString.h"
#include"goto.h"
int ischinese(char ch)//�ж��Ƿ�������
{ 
	if(ch&0x80)  
	{  
		return 1;  
	}  
	return 0;
}
/*******************************************************************
	���ƣ�����������ĸ�����ֵĺ���
	������
acStr    ��ʾ: ���������
		iMaxLen��ʾ: ��������ַ���
		iPutType��ʾ: 
			0 (�޿���)  1(ֻ����������)  2(ֻ��������ĸ)
		    3 (ֻ���������ֺ���ĸ) 4(ֻ������)
		isPlaintext��ʾ�Ƿ���ʾ���� 1��ʾ����
 ***************************************************************
int glb_putString(char acStr[100], int iMaxLen, int iPutType, int isPlaintext)
���ԣ��ο���˻���Ŀ�ֲ�ĵ�¼���ܣ�
ʵ���û���������Ŀ�������
���û���Ҫ�����ġ��8λ��ֻ�����ֺ���ĸ��ɣ�����Ҫ���ļ�*����ʾ���6λ��ֻ��������ɣ���
��������û���Ϊadmin������Ϊ123456����ʾ��¼�ɹ���������ʾ��¼ʧ�ܡ�*/
int glb_putString(char str[],int iPutType,int iMaxLen,int isPlaintext)
{

	char ch;
	int i=0;
	if(iPutType==4)
	{
		glb_putChinese(str,iMaxLen,isPlaintext);
		return glb_putChinese(str,iMaxLen,isPlaintext);;
	}
	while(1)
	{
		fflush(stdin);
		ch=getch();//�Ȳ��������� Ȼ���ж��Ƿ�������� ��ѡ���Ƿ����Ļ���*
		if(ch==-32)
		{
			fflush(stdin);
			getch();
			continue;
		}
		if(ch==13&&i!=0)
		{
			return 13;//�س���������
		}
		if (ch==13&&i==0)
		{
			continue;
		}
		if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
		{
			continue;
		}
		if(ch==8)// �˸����
		{
			i--;
			str[i]='\0';
			putchar(8);
			putchar(' ');
			putchar(8);
			continue;			
		}
		if(ch==27)
		{
			return 27;
		}
		switch(iPutType)
		{
		case 0:
			if(isPlaintext)//���������
			{
				if(i<iMaxLen)
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 
			{
				if(i<iMaxLen)
				{
					putchar('*');
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			break;
		case 1://ֻ������
			if(isPlaintext)//���������
			{
				if(i<iMaxLen&&isdigit(ch))
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 
			{
				if(i<iMaxLen&&isdigit(ch))
				{
					putchar('*');
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			break;
		case 2://ֻ����ĸ
			if(isPlaintext)//���������
			{
				if(i<iMaxLen&&isalpha(ch))
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 
			{
				if(i<iMaxLen&&isalpha(ch))
				{
					putchar('*');
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			break;
		case 3://ֻ�����ֺ�Ӣ��
			if(isPlaintext)//���������
			{
				if(i<iMaxLen&&isalnum(ch))
				{
					putchar(ch);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			else 
			{
				if(i<iMaxLen&&isalnum(ch))
				{
					putchar('*');
					str[i]=ch;
					i++;
					str[i]='\0';
				}
			}
			break;
		
			
		}
	}
	return 1;
}
int glb_putChinese(char str[],int iMaxLen,int isPlaintext)
{	
	char ch;
    int i=0;
	while(1)
	{
		fflush(stdin);
		ch=getch();//�Ȳ��������� Ȼ���ж��Ƿ�������� ��ѡ���Ƿ����Ļ���*
		if(ch==-32)
		{
			fflush(stdin);
			getch();
			continue;
		}
		if(ch==13&&i!=0)
		{
			return 13;//�س���������
		}
		if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
		{
			continue;
		}
		if(ch==8)// �˸����
		{
			{
				i-=2;
				str[i]='\0';
				putchar(8);
				putchar(' ');
				putchar(8);
				putchar(8);
				continue;
			}
		}
		if(ch==27)
		{
			return 27;
		}
		if(isPlaintext)//���������
		{
			if(i<iMaxLen&&ischinese(ch))
			{
				//putchar(ch);
				str[i]=ch;
				i++;
				str[i]='\0';
				if(i%2==0)
				{
					printf("%c%c",str[i-2],str[i-1]);
				}
			}
		}		 
		/*else //���벻���������� ���ÿ��ǰ�����
		{
		if(i<iMaxLen&&ischinese(ch))
		{
		putchar('*');
		str[i]=ch;
		i++;
		str[i]='\0';
		}
	}*/ 
	}
	return 1;
}

int glb_putNumber(int Imaxnum)//��װ��ֻ�����ֲ���������ʽ����ĺ��� Imaxnum �����λ��
{
	char ch,str[8];
	int i=0,n;
	int inum=0;
	while(1)
	{
		ch=getch();
		if(ch==13&&i!=0)
		{
			break ;//�س�����while
		}
		if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
		{
			continue;
		}
		if (ch==13&&i==0)
		{
			continue;
		}
		if(ch==27)
		{
			return 27 ;
		}
		if(ch==8)// �˸����
		{
			i--;
			str[i]='\0';
			putchar(8);
			putchar(' ');
			putchar(8);
			continue;			
		}
		if(isdigit(ch)&&i<Imaxnum)
		{
			putchar(ch);
			str[i]=ch;
			i++;
			str[i]='\0';
		}
	}
	n=i-1;
	for(i=0;str[i];i++)
	{
		inum=inum+(int)((str[i]-'0')*pow(10,n-i));
	}
	//printf("%d",inum);  ��֤�õ�
	return inum;
}
int glb_putYN(char str)
{
	int i=0;
	char ch;
	while(1)
	{
		if(i==1)
		{
			ch=getch();
			if(ch==13&&i!=0)
			{
				break ;//�س�����while
			}
			if (ch==13&&i==0)
			{
				continue;
			}
			if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
			{
				continue;
			}
			if(ch==27)
			{
				return 27 ;
			}
			if(ch==8)// �˸����
			{
				i--;
				putchar(8);
				putchar(' ');
				putchar(8);
				continue;			
			}
		}
		if(i==0)
		{
			str=getch();
			if(str=='y'||str=='n')
			{
				putchar(str);
				i++;
			}
		}
	}
	if(str=='y')
		return 1;
	else 
		return 0;
}
int glb_putOneStr(char str)
{
	int i=0;
	char ch;
	while(1)
	{
		if(i==1)
		{
			ch=getch();
			if(ch==13&&i!=0)
			{
				break ;//�س�����while
			}
			if(ch==8&&i==0)//�ܲ���ʲô��û���ʱ���ǰ��ĸ�ɾ�˰�
			{
				continue;
			}
			if (ch==13&&i==0)
			{
				continue;
			}
			if(ch==27)
			{
				return 27 ;
			}
			if(ch==8)// �˸����
			{
				i--;
				putchar(8);
				putchar(' ');
				putchar(8);
				continue;			
			}
		}
		if(i==0)
		{
			fflush(stdin);
			str=getch();
			putchar(str);
			i++;
		}
	}
	return str;
}
int glb_putDirection()
{
	char ch;
	while(1)
	{
		fflush(stdin);
		ch=getch();
		if(ch==27)
			return 27;
		if(ch!=-32)
		{
			continue;
		}
		ch=getch();
		if(ch==80||ch==78||ch==77||ch==75)
		{
			return ch;
		}
		else 
		{
			
			continue;
		}
	}
}