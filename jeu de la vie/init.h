#ifndef _INIT_H
#define _INIT_H

#include<stdlib.h>
#include<stdio.h>
#include "libsx.h"
#include<string.h>
#include<ctype.h>

#define winWidth 400
#define winHeight 400
#define sqarePixel 10
#define animateTime 800
Widget areaWidget,nameAreaWidget,buttonWidget[6];


int lifeGame[winWidth*2/sqarePixel+6][winHeight/sqarePixel+2];
int dayAndNight[winWidth*2/sqarePixel+6][winHeight/sqarePixel+2];
int ifStop;

char nowStructure[105];
int myAtoi(const char s[],int num[]);
void initData(Widget w,void *data);

#endif
