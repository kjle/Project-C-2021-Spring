#ifndef _VUE_H
#define _VUE_H

#include "libsx.h"

void quitProgram(Widget w, void *data);
void drawAnimate(void *data);
void drawBackground(Widget w,int width,int height,void *data);
void init_display(void);
void StopAnimate(Widget w,void *data);
void Aniamate(Widget w,void *data);

#endif
