#include<fstream.h>
#include<iostream.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<iomanip.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>

int food_count=0,lose_count=0,level_count=0,fxi=0,fyi=0;

void right(int &x1,int &y1,long int &ch1,int fx1,int fy1);
void left(int &x2,int &y2,long int &ch2,int fx2,int fy2);
void down(int &x3,int &y3,long int &ch3,int fx3,int fy3);
void up(int &x4,int &y4,long int &ch4,int fx4,int fy4);
void controller(int xi,int yi,long int chi,int check);
void levelup();
void change(long int &chi);
void curves();
void curtain();
void transit();
void help();
void score();
void game_();
void intro();
void levelup();
void highscore();
void newscore();
void food_(int &f1,int&f2);

void main()
{
 clrscr();
 curves();
 intro();
}

void levelup()
{
 level_count++;
 int x=getmaxx(),y=getmaxy(),i,flag=0;
 char level[40];
 setcolor(WHITE);
 if(level_count>=4)
  {
   flag=1;
   settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
   outtextxy(x/3-20,y/3,"YOU WIN");
   delay(500);
   transit();
   goto jump;
  }
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
 sprintf(level,"LEVEL %d",level_count);
 outtextxy(x/3,y/3,level);
 for(i=1;i<10;i++)
 {setbkcolor(i); delay(250);}
 cleardevice();
 game_();
 jump:
 if(flag==1)
 {cleardevice();
 closegraph();
 newscore();}
}

void game_()
{
 int a,b,x,y,check=1,c=level_count*5;
 long int ch=54;
 char target[80];
 x=getmaxx();
 y=getmaxy();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
 setcolor(WHITE);
 outtextxy(x/2-180,y/3,"PLEASE  WAIT");
 delay(100);
 transit();
 cleardevice();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 sprintf(target,"TARGET - %d",c);
 outtextxy(x-170,y-30,target);
 outtextxy(40,y-30,"YOUR SCORE - ");
 setcolor(GREEN);
 rectangle(200,y-25,225,y-5);
 setfillstyle(SOLID_FILL,GREEN);
 floodfill(205,y-15,GREEN);
 controller(20,20,ch,check);
}
void controller(int xi,int yi,long int chi,int check)
{
 int x=getmaxx(),y=getmaxy();
 char ch_new;

  if(check==1)
   {
    food_(fxi,fyi);
   }
 check=0;
 setbkcolor(BLUE);

 if(chi==56)
  {up(xi,yi,chi,fxi,fyi);}

 else if(chi==54)
  {right(xi,yi,chi,fxi,fyi);}

 else if(chi==52)
  {left(xi,yi,chi,fxi,fyi);}

 else if(chi==50)
  {down(xi,yi,chi,fxi,fyi);}

 else if(chi==53)
  {
   setcolor(GREEN);
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
   outtextxy(x/4,y/4-30," KYA HUA !! ");
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
   outtextxy(x/4+10,y/3,"A)RESUME  ");
   outtextxy(x/4+10,y/3+40,"B)MAIN MENU  ");
   outtextxy(x/4+10,y/3+80,"C)EXIT  ");
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
   outtextxy(35,y-90,"Note : Once you have paused, snake can move in any random");
   outtextxy(x/3-50,y-70," direction from previous coordinates.");
  while(!kbhit())
  {}
   ch_new=getch();
   cleardevice();

  if(ch_new=='a')
  { change(chi);
    food_(fxi,fyi);
    controller(xi,yi,chi,check);
  }

  else if(ch_new=='b')
  { closegraph(); intro();}

  else if(ch_new=='c')
  { exit(0);}

 }
  else
  {
   lose_count=1;
   settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
   setcolor(WHITE);
   outtextxy(x/2-130,y/3,"YOU LOSE");
   delay(100);
   setbkcolor(RED);
   transit();
   cleardevice();
   newscore();
  }
}

void intro()
{
 food_count=0; lose_count=0; level_count=0;
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\Turboc3\\bgi");
 cleardevice();
 int a,b,c,d,x,y;
 char look;
 x=getmaxx();
 y=getmaxy();
 again:
 setlinestyle(SOLID_LINE,0,1);
 look='z';
 setbkcolor(BLACK);
 setcolor(BLUE);
 rectangle(10,10,x-10,y-10);
 setcolor(BLUE);
 rectangle(12,12,x-12,y-12);
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 7);
 setcolor(GREEN);
 outtextxy(x/3,y/10,"SNAKE");
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
 outtextxy(x/3,y/3+50,"A). START GAME");
 outtextxy(x/3,y/3+90,"B). HELP");
 outtextxy(x/3,y/3+130,"C). HIGHSCORE");
 outtextxy(x/3,y/3+170,"D). EXIT");
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
 outtextxy(x/2-100,y-100,"Press A,B or C to continue");

 for(c=25;c<=x-25;c+=20)
  { if(!kbhit())
   {
   setcolor(GREEN);
   circle(c,25,10);
   setfillstyle(SOLID_FILL,GREEN);
   floodfill(c,25,GREEN);
    if(c>=105)
      { setcolor(BLACK);
	circle(c-80,25,10);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(c-80,25,BLACK);
       }
   }
  if(kbhit())
   { look=getch(); goto skip; }
  delay(30);
 }
		   for(d=c-80;d<=x-25;d+=20)
		   {
		      setcolor(BLACK);
		      circle(d,25,10);
		      setfillstyle(SOLID_FILL,BLACK);
		      floodfill(d,25,BLACK);

		      if(kbhit())
		      { look=getch(); goto skip; }
		   }
 for(c=25;c<=y-25;c+=20)
  { if(!kbhit())
   {setcolor(GREEN);
    circle(x-25,c,10);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(x-25,c,GREEN);
     if(c>=105&& !kbhit())
       {
	setcolor(BLACK);
	circle(x-25,c-80,10);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(x-25,c-80,BLACK);
       }
   }
  if(kbhit())
   { look=getch(); goto skip;}
  delay(30);
 }
		     for(d=c-80;d<=y-25;d+=20)
		     {
			setcolor(BLACK);
			circle(x-25,d,10);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(x-25,d,BLACK);

			if(kbhit())
			{ look=getch(); goto skip; }
		     }

 for(c=x-25;c>=25;c-=20)
  { if(!kbhit())
   {setcolor(GREEN);
    circle(c,y-25,10);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(c,y-25,GREEN);
     if(c<=x-25&& !kbhit())
       {
	setcolor(BLACK);
	circle(c+80,y-25,10);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(c+80,y-25,BLACK);
       }
   }
  if(kbhit())
   { look=getch(); goto skip; }
  delay(30);
 }
		   for(d=c+80;d>=25;d-=20)
		   {
		      setcolor(BLACK);
		      circle(d,y-25,10);
		      setfillstyle(SOLID_FILL,BLACK);
		      floodfill(d,y-25,BLACK);

		      if(kbhit())
		      { look=getch(); goto skip; }
		   }

 for(c=y-25;c>=25;c-=20)
  {if(!kbhit())
   {setcolor(GREEN);
    circle(25,c,10);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(25,c,GREEN);
     if(c<=y-25&& !kbhit())
       {
	setcolor(BLACK);
	circle(25,c+80,10);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(25,c+80,BLACK);
       }
    }
  if(kbhit())
   { look=getch(); goto skip;}
  delay(30);
  }
		   for(d=c+80;d>=25;d-=20)
		   {
		      setcolor(BLACK);
		      circle(25,d,10);
		      setfillstyle(SOLID_FILL,BLACK);
		      floodfill(25,d,BLACK);

		      if(kbhit())
		      { look=getch(); goto skip; }
		   }

 skip:
 if(look=='z')
 { goto again;
 }
 else if(look=='a' || look=='A')
  { cleardevice();
  food_count=0;
  lose_count=0;
  level_count=0;
  levelup();}
 else if(look=='b'|| look=='B')
  {
  closegraph();
  help();
  }
 else if(look=='c'|| look=='c')
  {
  cleardevice();
  closegraph();
  highscore();
  }
 else if( look=='d'|| look=='D')
  {
  cleardevice();
  setcolor(RED);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
  outtextxy(x/4-50,y/3," COME AGAIN LATER ");
  delay(1000);
  curtain();
  exit(0);
  }
 else
  {
  cout<<"\nwrong input  ";
  delay(1000);
  cleardevice();
  goto again;
  }
  closegraph();
}

void help()
{
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\Turboc3\\bgi");

 cleardevice();
 setcolor(RED);
 int x=getmaxx(),y=getmaxy();
 setbkcolor(BLACK);
 setcolor(BLUE);
 rectangle(10,10,x-10,y-10);
 rectangle(12,12,x-12,y-12);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
 setcolor(RED);
 outtextxy(x/3+40,25,"HELP");
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
 setcolor(GREEN);

 outtextxy(35,y/6+20,"THE RULES OF THIS GAME ARE SIMPLE! ");
 outtextxy(35,y/6+50,"YOU HAVE TO USE NUMPAD KEYS FOR THE MOVEMENT OF SNAKE");

 outtextxy(30,y/6+90 ,"8 -> UP");
 outtextxy(30,y/6+120,"2 -> DOWN");
 outtextxy(30,y/6+150,"6 -> RIGHT");
 outtextxy(30,y/6+180,"4 -> LEFT");
 outtextxy(30,y/6+210,"5 -> PAUSE");

 outtextxy(35,y/6+250,"REMEMBER YOU MUST STAY INSIDE THE BORDERS ON THE ");
 outtextxy(35,y/6+280,"SCREEN TO CONTINUE PLAYING.IF YOU WANT TO PAUSE THE");
 outtextxy(35,y/6+310,"GAME CLICK 5 ON THE NUMPAD ,FROM THERE YOU CAN EXIT,");
 outtextxy(35,y/6+340,"GO TO MAIN MENU OR RESUME YOUR GAME.");
 outtextxy(x-180,y-50,"press any key");
 while(!kbhit())
 {}
 cleardevice();
 setbkcolor(BLACK);
 setcolor(BLUE);
 rectangle(10,10,x-10,y-10);
 rectangle(12,12,x-12,y-12);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
 setcolor(RED);
 outtextxy(x/3+40,25,"HELP");
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
 setcolor(GREEN);

 outtextxy(35,y/6+20 ,"YOU CAN SEE YOUR REAL TIME SCORE AT BOTTOM RIGHT ");
 outtextxy(35,y/6+50 ,"CORNER OF THE SCREEN,ONCE THE TARGET IS COMPLETED ");
 outtextxy(35,y/6+80 ,"YOU WILL BE TAKEN TO NEXT LEVEL AUTOMATICALLY.");

 outtextxy(35,y/6+120 ,"HAPPY PLAYING...");
 outtextxy(x-180,y-50,"press any key");
 getch();
 while(!kbhit())
 {}
 getch();
 closegraph();
 intro();
}
 void change(long int &chi)
 {  randomize();
  again:
  int num1=random(4)+1,num2=random(2)+1;
  if(num1%2!=0)
   {if(num2%2!=0)
     chi=chi+num1;
    else
     chi=chi-num1;
   }
  else
   goto again;
 }

void right(int &x1,int &y1,long int &ch1,int fx1,int fy1)
 {
 int x=getmaxx(),y=getmaxy(),check=0,e;
  score();
  setbkcolor(BLUE);
  for(x1;x1<=x;x1+=20)
   { if(!kbhit())
      {
	setcolor(GREEN);
	circle(x1,y1,10);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(x1,y1,GREEN);
	moveto(x1,y1);

       if(x1>=(100+food_count*20))
	 {  setcolor(BLACK);
	    circle(x1-(80+food_count*20),y1,10);
	    setfillstyle(SOLID_FILL,BLACK);
	    floodfill(x1-(80+food_count*20),y1,BLACK);
	 }
   delay(90-level_count*20);
       if((abs(x1-fx1))<=5 && (abs(y1-fy1)<=5))
	 {
	  check=1;
      food_count++;
      break;
	 }
   }
  if(kbhit())
   { ch1=getch(); break; }

   setcolor(WHITE);
   rectangle(20,20,x-20,y-30);
  }
  x1=getx();
  y1=gety();
  if(x1>=x-20)
  {//lose_count=1;
  ch1=1;
  goto last;}
		   for( e=x1-(80+food_count*20);e<=x1;e+=20)
		    { setcolor(BLACK);
		      circle(e,y1,10);
		      setfillstyle(SOLID_FILL,BLACK);
		      floodfill(e,y1,BLACK);
		    }
 last:
 controller(x1,y1,ch1,check);
 }
 void left(int &x2,int &y2,long int &ch2,int fx2,int fy2)
 {
 int x=getmaxx(),y=getmaxy(),check=0,e;
 score();
 setbkcolor(BLUE);
 for(x2;x2>=20;x2-=20)
 {
 if(!kbhit())
  {
 setcolor(GREEN);
 circle(x2,y2,10);
 setfillstyle(SOLID_FILL,GREEN);
  floodfill(x2,y2,GREEN);
  moveto(x2,y2);
  if(x2<=x-(20+food_count*20))
  { setcolor(BLACK);
    circle(x2+(80+food_count*20),y2,10);
     setfillstyle(SOLID_FILL,BLACK);
     floodfill(x2+(80+food_count*20),y2,BLACK);
   }
  delay(90-level_count*20);
  if((abs(x2-fx2)<=5) && (abs(y2-fy2)<=5))
     {
      check=1;
	food_count++;
	break;
     }
  }
  if(kbhit())
  { ch2=getch(); break; }
   setcolor(WHITE);
  rectangle(20,20,x-20,y-30);
 }
 x2=getx();
 y2=gety();
  if(x2<=20)
  {ch2=1;
  goto last;}
		   for(e=x2+(80+food_count*20);e>=x2;e-=20)
		   { setcolor(BLACK);
		     circle(e,y2,10);
		      setfillstyle(SOLID_FILL,BLACK);
		      floodfill(e,y2,BLACK);
		   }
  last:
  controller(x2,y2,ch2,check);
 }
 void up(int &x3,int &y3,long int &ch3,int fx3,int fy3)
 {
 int y=getmaxy(),x=getmaxx(),check=0,e;
  score();
  setbkcolor(BLUE);
 for(y3;y3>=20;y3-=20)
 {if(!kbhit())
  {
  setcolor(GREEN);
  circle(x3,y3,10);
  setfillstyle(SOLID_FILL,GREEN);
  floodfill(x3,y3,GREEN);
  moveto(x3,y3);
  if(y3<=y-(20+food_count*20))
  { setcolor(BLACK);
    circle(x3,y3+(80+food_count*20),10);
     setfillstyle(SOLID_FILL,BLACK);
     floodfill(x3,y3+(80+food_count*20),BLACK);
  }
  delay(90-level_count*20);
  if((abs(x3-fx3)<=5) && (abs(y3-fy3)<=5))
     {
      check=1;
      food_count++;
      break;
     }
  }
  if(kbhit())
  { ch3=getch(); break; }

   setcolor(WHITE);
  rectangle(20,20,x-20,y-30);
 }
 x3=getx();
 y3=gety();
  if(y3<=20)
 { ch3=1;
 goto last;}
		   for (e=y3+(80+food_count*20);e>=y3;e-=20)
		   { setcolor(BLACK);
		     circle(x3,e,10);
		      setfillstyle(SOLID_FILL,BLACK);
		      floodfill(x3,e,BLACK);
		   }
  last:
  controller(x3,y3,ch3,check);
 }
 void down(int &x4,int &y4,long int &ch4,int fx4,int fy4)
 {
 int y=getmaxy(),x=getmaxx(),check=0,e;
  score();
  setbkcolor(BLUE);
 for(y4;y4<=y-20;y4+=20)
 {if(!kbhit())
  {
  setcolor(GREEN);
  circle(x4,y4,10);
  setfillstyle(SOLID_FILL,GREEN);
  floodfill(x4,y4,GREEN);
  moveto(x4,y4);
   if(y4>=(100+food_count*20))
   { setcolor(BLACK);
    circle(x4,y4-(80+food_count*20),10);
     setfillstyle(SOLID_FILL,BLACK);
     floodfill(x4,y4-(80+food_count*20),BLACK);
   }
  delay(90-level_count*20);
  if((abs(x4-fx4)<=5) && (abs(y4-fy4)<=5))
     {
      check=1;
    food_count++;
    break;
     }
  }
  if(kbhit())
  { ch4=getch(); break; }
   setcolor(WHITE);
  rectangle(20,20,x-20,y-30);
 }
 x4=getx();
 y4=gety();
  if(y4>=y-40)
  {ch4=1;
  goto last;}
		     for(e=y4-(80+food_count*20);e<=y4;e+=20)
		     { setcolor(BLACK);
		       circle(x4,e,10);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(x4,e,BLACK);
		     }
 last:
 controller(x4,y4,ch4,check);
 }



void score()
{
 setcolor(WHITE);
 int x=getmaxx(),y=getmaxy(),c=level_count*5;
 char points[80],points1[80],target[80];
 int backup=food_count-1;

 sprintf(points1, " %d ",backup);
 sprintf(points, " %d ",food_count);

 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 sprintf(target,"TARGET - %d",c);
 outtextxy(x-170,y-30,target);
 outtextxy(40,y-30,"YOUR SCORE - ");
 setcolor(GREEN);
 rectangle(200,y-25,225,y-5);
 setfillstyle(SOLID_FILL,GREEN);
 floodfill(205,y-15,GREEN);
 if(food_count != 0)
  {
   setcolor(GREEN);
   outtextxy(200,y-30,points1);
  }
 setcolor(WHITE);
 outtextxy(200,y-30,points);
 if(food_count>=c && food_count>=15)
 {setbkcolor(RED);
 cleardevice();
 levelup();
 }
 else if(food_count>=c)
   {
    settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
    outtextxy(x/8,y/3,"TARGET COMPLETED");
    delay(100);
    setbkcolor(RED);
    transit();
    cleardevice();
    levelup();
   }
}

void food_(int &f1,int &f2)
{
 int x,y,a,b;
 x=getmaxx();
 y=getmaxy();
 setbkcolor(BLUE);
 setcolor(WHITE);
 rectangle(20,20,x-20,y-30);
 randomize();
 a=f1;
 b=f2;
 again:
 f1=random(x-89)+50;
 f2=random(y-89)+50;
 if((f1%20==0 && f2%20==0) && (a!=f1 && b!=f2))
  { setcolor(WHITE);
    circle(f1,f2,10);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(f1,f2,WHITE);
  }
 else
 goto again;

}
void curtain()
{
 int x,y;
 x=getmaxx();
 y=getmaxy();
 for(int a=0;a<=y;a++)
 {
   for(int j=20;j<=x;j+=40)
 {
  if(a%2==0)
  {setcolor(2*a);  circle(j,a,20);    }
  else
  {setcolor(6*a);  circle(x-j,a,20);  }
  }
}
}

void transit()
{
 for (int a=0;a<=800;a=a+100)
  {
   for ( int i=0 ; i<=1000 ; i++ )
    { int x=i;
      int y1=2*x;
      circle(x-200+a,y1,1);
      setcolor(YELLOW);
      int y2=-(4*x-1000)/2;
      circle(x-200+a,y2,1);
    }
    delay(100);
  }
 for (int b=0;b<=800;b=b+100)
  {
   for ( int i=0 ; i<=1000 ; i++ )
    { int x=i;
      setcolor(BLACK);
      int y1=2*x;
      circle(x-200+b,y1,1);
      int y2=-(4*x-1000)/2;
      setcolor(BLACK);
      circle(x-200+b,y2,1);
    }
  }
}

void curves()
 {
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\Turboc3\\bgi");
 cleardevice();
 int c=1,x,y;
 x=getmaxx();
 y=getmaxy();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);

 do
 {setcolor(c);
  outtextxy(x/2-130,y/3,"LOADING");
  for ( int i=0 ; i<=1000 ; i++ )
  { double x=(double)i;
    double a=x*3.14;
    double y1=50*sin(a/180);
    circle(x,y1+100,1);
    circle(x,y1+200,1);
    circle(x,y1+300,1);
    circle(x,y1+400,1);
    delay(1);
  }
 for(i=0 ; i<=1000 ; i++ )
  {
    double x=(double)i;
    double a=x*3.14;
    double y2=50*sin(a/180);
      setcolor(BLACK);
    circle(x,y2+100,1);
    circle(x,y2+200,1);
    circle(x,y2+300,1);
    circle(x,y2+400,1);
    delay(1);
  }
 c++;
 }while(c<7);
 closegraph();
}

class data
 {
 int score;
// char name[50];
 public:
 char name[50];

void insert(int a)
  {
  score=a;
  setbkcolor(RED);
  setcolor(YELLOW);
  rectangle(170,140,460,200);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
  outtextxy(180,150,"ENTER YOUR NAME");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
  outtextxy(180,215,"-->");
  gets(name);
  //strcpy(name1,name);
  }
 int rank()
  {
   return score;
  }
};


void highscore()
{
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\Turboc3\\bgi");

 int x=getmaxx();
 int y=getmaxy();
 data player[50];
 fstream file;
 file.open("try1.dat",ios::binary|ios::in|ios::ate);

 cleardevice();
 setcolor(MAGENTA);
 setlinestyle(DOTTED_LINE,1,3);
 rectangle(20,y/4,x-20,y-20);
 rectangle(25,y/4+5,x-25,y-25);
 line(20,y/3,x-20,y/3);
 line(x/3,y/4,x/3,y-25);
 line(2*x/3,y/4,2*x/3,y-25);

 setlinestyle(SOLID_LINE,0,1);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
 setcolor(YELLOW);
 outtextxy(x/5,30,"HIGHSCORES");
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
 setcolor(BLUE);
 outtextxy(65,y/4+5,"RANKING     SCORE       NAME");
 setcolor(WHITE);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
 char rank[10],disp[60];
 for(int i=y/3+5,j=1;i<y-40;i+=20,j++)
 {
  if(j<10)
   sprintf(rank," 0%d )",j);
  else
   sprintf(rank," %d ) ",j);

 outtextxy(x/6,i,rank);
 }
 i=1;
 file.seekp(0);
 file.seekg(0);
 while(!file.eof())
 { file.read((char*)&player[i],sizeof(player[i]));
 i++; }

 int already=i-1;

 for(i=y/3+5,j=1;j<=14 && j<=already;i+=20)
 {
   sprintf(disp,"%d points    \t\t\t\t %s",player[j].rank(),player[j].name);
   outtextxy(x/3+50,i,disp);
   j++;
 }
 file.close();
 while(!kbhit())
 {}getch();
 closegraph();
 intro();
}

void newscore()
{  closegraph();
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\Turboc3\\bgi");
 fstream file1,file2;
 file1.open("try1.dat",ios::binary|ios::out|ios::in|ios::ate);
 file2.open("try2.dat",ios::binary|ios::out|ios::in|ios::ate);
 data play[50];
 int i=1,pos[1][20],already;
 file1.seekg(0);
 while(!file1.eof())
 {
 file1.read((char*)&play[i],sizeof(play[i]));
 i++;
 }
 already=i-1;

 play[already].insert(food_count);
 file1.seekp((already)*sizeof(play[1]),ios::beg);
 file1.write((char*)&play[already],sizeof(play[already]));

 for(int b=0,c=1;b<=(already-1);b++,c++)
 {
    pos[0][b]=play[b+1].rank();
    pos[1][b]=c;

 }

 int x,y;

 for(int j=0;j<already;j++)
 {
  for(i=0;i<=(already-2);i++)
  {
     if(pos[0][i]<pos[0][i+1])
       {
	x=pos[0][i];
	pos[0][i]=pos[0][i+1];
	pos[0][i+1]=x;

	y=pos[1][i];
	pos[1][i]=pos[1][i+1];
	pos[1][i+1]=y;
	}

    }
 }


 i=0;
 while(i<=(already-1) && i<15)
 {
  int a=pos[1][i];
  file2.write((char*)&play[a],sizeof(play[a]));
  i++;
 }

 file1.close();
 file2.close();
 remove("try1.dat");
 rename("try2.dat","try1.dat");
 closegraph();
 intro();
}
