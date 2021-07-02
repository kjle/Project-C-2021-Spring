#include "vue.h"
#include "data.h"
#include "init.h"

/*
 Function: Set refresh stop flag ifStop (0/1).
 */
void StopAnimate(Widget w,void *data)
{
   ifStop=1;
}

/*
 Function: Start update and Animate.
 */
void Animate(Widget w,void *data)
{
  if(ifStop==0) return;
  ifStop=0;
  AddTimeOut(animateTime,drawAnimate,data);
}

/*
 Function: Quit.my program
 */
void quitProgram(Widget w, void *data)
{
  exit(0);
}

/*
 Function: Update the screen according to the data.
 */
void drawAnimate(void *data)
{
  SetColor(GREEN);
  int maxX=winWidth/sqarePixel,maxY=winHeight/sqarePixel;
  for(int i=0;i<maxX;i++)
  for(int j=0;j<maxY;j++)
  {
    if(lifeGame[i][j])
    DrawFilledBox(i*sqarePixel+1,(j+3)*sqarePixel+1, sqarePixel-1, sqarePixel-1);
    if(dayAndNight[i][j])
     DrawFilledBox(i*sqarePixel+1,(maxY+j+6)*sqarePixel+1, sqarePixel-1, sqarePixel-1);
  }
  SetColor(WHITE);
  for(int i=0;i<maxX;i++)
  for(int j=0;j<maxY;j++)
  {
    if(!lifeGame[i][j])
    DrawFilledBox(i*sqarePixel+1,(j+3)*sqarePixel+1, sqarePixel-1, sqarePixel-1);
    if(!dayAndNight[i][j])
    DrawFilledBox(i*sqarePixel+1,(maxY+j+6)*sqarePixel+1, sqarePixel-1, sqarePixel-1);
  }
   DayAndNightData();
   lifeGameData();
  if(!ifStop)
  AddTimeOut(animateTime,drawAnimate,data);
}

/*
 Function: Draw the grids and background color.
 */
void drawBackground(Widget w,int width,int height,void *data)
{
  int maxX=winWidth/sqarePixel,maxY=winHeight/sqarePixel;
  ClearDrawArea();
  SetDrawArea(w);
  SetColor(BLACK);
  for(int i=0;i<=height;i+=sqarePixel)
  DrawLine(0,i, width, i);   /* just draw a diagonal line */
  int border=3*sqarePixel,totalheight=2*height+3*sqarePixel;
  // the room of 3 square to put the name of rule in the begin
  for(int i=height+border;i<=totalheight;i+=sqarePixel)
  DrawLine(0,i, width, i);   /* just draw a diagonal line */
  for(int i=0;i<=width;i+=sqarePixel)
  DrawLine(i,0, i, height);   /* just draw a diagonal line */

  SetColor(WHITE);
  for(int i=0;i<maxX;i++)
  for(int j=0;j<=2;j++)
  DrawFilledBox(i*sqarePixel,j*sqarePixel, sqarePixel, sqarePixel);
  for(int i=0;i<maxX;i++)
  for(int j=maxY+3;j<=maxX+5;j++)
  DrawFilledBox(i*sqarePixel,j*sqarePixel, sqarePixel, sqarePixel);
  // draw the red round 
  SetColor(RED);
  for(int i=0;i<maxX;i++)
  for(int j=0;j<=2;j++)
  if(i==0||i==maxX-1||j==0||j==2)
  DrawFilledArc(i*sqarePixel+1,j*sqarePixel+1,sqarePixel, sqarePixel, 0, 360);
  for(int i=0;i<maxX;i++)
  for(int j=maxY+3;j<=maxX+5;j++)
  if(i==0||i==maxX-1||j==maxY+3||j==maxX+5)
  DrawFilledArc(i*sqarePixel+1,j*sqarePixel+1,sqarePixel, sqarePixel, 0, 360);
  
  SetColor(BLACK);
  char s2[20]="DAY   AND   NIGHT";
  char s1[20]="LIFE    GAME";
  DrawText(s1,winWidth/3,2*sqarePixel);
  DrawText(s2,winWidth/3,winHeight+5*sqarePixel);
 
 AddTimeOut(animateTime,drawAnimate,data);
}

/*
 Function: Open the window and creat the widgets.
 */
void init_display(void)
{
 
  char *s1="StructureStable";
  char *s2="StructurePeriod";
  char *s3="StructureVasseux";
  
   buttonWidget[0]= MakeButton("QUIT", quitProgram, NULL);
  buttonWidget[1]=MakeButton("STOP", StopAnimate, NULL);
  buttonWidget[2]=MakeButton("ANIMATE",Animate, &nameAreaWidget);
  buttonWidget[3]=MakeButton("Stable", initData, s1);
  buttonWidget[4]=MakeButton("Period", initData, s2);
  buttonWidget[5]=MakeButton("Vasseux", initData,s3);
  nameAreaWidget=MakeLabel("Structures Now is Vasseux");
  initData(buttonWidget[4],s3);
  areaWidget= MakeDrawArea(winWidth,winHeight*2+sqarePixel*6, drawBackground,NULL);
  //set postion of buttom
  for(int i=0;i<5;i++)
  SetWidgetPos(buttonWidget[i+1], PLACE_RIGHT, buttonWidget[i], NO_CARE, NULL);
  SetWidgetPos(nameAreaWidget, PLACE_UNDER, buttonWidget[2], NO_CARE, NULL);
   
  SetWidgetPos(areaWidget, PLACE_UNDER, nameAreaWidget, NO_CARE, NULL);
}
