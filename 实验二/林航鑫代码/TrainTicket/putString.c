#include"putString.h"
#include"goto.h"
int ischinese(char ch)//判断是否是中文
{ 
	if(ch&0x80)  
	{  
		return 1;  
	}  
	return 0;
}
/*******************************************************************
	名称：允许输入字母和数字的函数
	参数：
acStr    表示: 保存的数组
		iMaxLen表示: 最大输入字符数
		iPutType表示: 
			0 (无控制)  1(只能输入数字)  2(只能输入字母)
		    3 (只能输入数字和字母) 4(只能中文)
		isPlaintext表示是否显示明文 1表示明文
 ***************************************************************
int glb_putString(char acStr[100], int iMaxLen, int iPutType, int isPlaintext)
测试：参考点菜机项目手册的登录功能，
实现用户名和密码的控制输入
（用户名要求明文、最长8位、只可数字和字母组成，密码要求暗文及*号显示、最长6位、只可数字组成）。
如输入的用户名为admin，密码为123456则提示登录成功，否则提示登录失败。*/
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
		ch=getch();//先不明文输入 然后判断是否符合类型 子选择是否明文还是*
		if(ch==-32)
		{
			fflush(stdin);
			getch();
			continue;
		}
		if(ch==13&&i!=0)
		{
			return 13;//回车跳出函数
		}
		if (ch==13&&i==0)
		{
			continue;
		}
		if(ch==8&&i==0)//总不能什么都没输的时候把前面的给删了吧
		{
			continue;
		}
		if(ch==8)// 退格操作
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
			if(isPlaintext)//如果是明文
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
		case 1://只能数字
			if(isPlaintext)//如果是明文
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
		case 2://只能字母
			if(isPlaintext)//如果是明文
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
		case 3://只能数字和英文
			if(isPlaintext)//如果是明文
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
		ch=getch();//先不明文输入 然后判断是否符合类型 子选择是否明文还是*
		if(ch==-32)
		{
			fflush(stdin);
			getch();
			continue;
		}
		if(ch==13&&i!=0)
		{
			return 13;//回车跳出函数
		}
		if(ch==8&&i==0)//总不能什么都没输的时候把前面的给删了吧
		{
			continue;
		}
		if(ch==8)// 退格操作
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
		if(isPlaintext)//如果是明文
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
		/*else //密码不可能用中文 不用考虑暗文了
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

int glb_putNumber(int Imaxnum)//封装的只能数字并以整形形式保存的函数 Imaxnum 是最大位数
{
	char ch,str[8];
	int i=0,n;
	int inum=0;
	while(1)
	{
		ch=getch();
		if(ch==13&&i!=0)
		{
			break ;//回车跳出while
		}
		if(ch==8&&i==0)//总不能什么都没输的时候把前面的给删了吧
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
		if(ch==8)// 退格操作
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
	//printf("%d",inum);  验证用的
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
				break ;//回车跳出while
			}
			if (ch==13&&i==0)
			{
				continue;
			}
			if(ch==8&&i==0)//总不能什么都没输的时候把前面的给删了吧
			{
				continue;
			}
			if(ch==27)
			{
				return 27 ;
			}
			if(ch==8)// 退格操作
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
				break ;//回车跳出while
			}
			if(ch==8&&i==0)//总不能什么都没输的时候把前面的给删了吧
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
			if(ch==8)// 退格操作
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