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
int glb_putNumber(int Imaxnum);//限制输入多少位数的整数 返回这个数字
int glb_putYN(char str);//限制只能输入YN Y返回1 N 0
int glb_putOneStr(char str);//限制只能输入一个字符 返回阿斯科马值
int glb_putDirection();
#endif