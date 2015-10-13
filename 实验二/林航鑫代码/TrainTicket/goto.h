
#ifndef _GOTO_H_
#define _GOTO_H_
#include <windows.h>
#include <stdio.h>
#include <conio.h>
void ConPrint(char *CharBuffer, int len);
void ConPrintAt(int x, int y, char *CharBuffer, int len);
void gotoXY(int x, int y);
void ClearConsole(void);
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground(int ForgC, int BackC);
void SetColor(int ForgC);
void HideTheCursor(void);
void ShowTheCursor(void);
int modify_direction(int i,int j,int sum);
#endif