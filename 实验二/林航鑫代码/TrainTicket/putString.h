#include <windows.h>
#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#define NUM 20
#ifndef _PUTSTRING_H_
#define _PUTSTRING_H_
int ischinese(char ch);
int glb_putString(char str[],int iPutType,int iMaxLen,int isPlaintext);
int glb_putChinese(char str[],int iMaxLen,int isPlaintext);
int glb_putNumber(int Imaxnum);//�����������λ�������� �����������
int glb_putYN(char str);//����ֻ������YN Y����1 N 0
int glb_putOneStr(char str);//����ֻ������һ���ַ� ���ذ�˹����ֵ
int glb_putDirection();
#endif