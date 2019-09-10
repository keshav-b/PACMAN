#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <process.h>
#include <iomanip.h>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream.h>


#define right 77
#define left 75
#define down 80
#define up 72
#define enter 13
#define esc 27

int gscore;
char name[40];

void gameover();

void pacman_down(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4);

void pacman_up(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4);

void pacman_left(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4);

void pacman_right(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4);

void pacman_move(int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4);

void maze(char n[]);

void mainpage();

void letsplay();

void about();

void game_over();

void help(char n[]);

void menu(char n[]);

void details(char n[]);

void fscore (int x,int y);

void food();

void inky_down();

void pinky_down();

void binky_down();

void clyde_down();

void pinky_move(int &x,int &y,int &t);

void inky_move(int &x,int &y,int &t);

void blinky_move(int &x,int &y,int &t);

void clyde_move(int &x,int &y,int &t);

void ghost_collide_up(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5);

void ghost_collide_down(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5);

void ghost_collide_left(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5);

void ghost_collide_right(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5);


/* GHOST 1 */

void pinky_move(int &xg1,int &yg1,int &t)
{
	if(t>=0 && t<285)
	{
		setcolor(13);
		setfillstyle(1,13);
		sector(xg1,yg1,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg1-5,yg1-15,1,3);
		fillellipse(xg1+5,yg1-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg1,yg1,0,180,12,25);

		xg1++;

		setcolor(13);
		setfillstyle(1,13);
		sector(xg1,yg1,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg1-5,yg1-15,1,3);
		fillellipse(xg1+5,yg1-15,1,3);

	}

	else if(t>=285 && t<465)
	{
		setcolor(13);
		setfillstyle(1,13);
		sector(xg1,yg1,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg1-5,yg1-15,1,3);
		fillellipse(xg1+5,yg1-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg1,yg1,0,180,12,25);

		yg1++;
	}

	else if(t>=465 && t<645)
	{
		setcolor(13);
		setfillstyle(1,13);
		sector(xg1,yg1,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg1-5,yg1-15,1,3);
		fillellipse(xg1+5,yg1-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg1,yg1,0,180,12,25);

		yg1--;
	}

	else if(t>=645 && t<730)
	{
		setcolor(13);
		setfillstyle(1,13);
		sector(xg1,yg1,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg1-5,yg1-15,1,3);
		fillellipse(xg1+5,yg1-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg1,yg1,0,180,12,25);

		xg1++;
	}
	else if(t>=730 && t<1100)
	{
		setcolor(13);
		setfillstyle(1,13);
		sector(xg1,yg1,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg1-5,yg1-15,1,3);
		fillellipse(xg1+5,yg1-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg1,yg1,0,180,12,25);

		xg1--;
	}

	else if(t==1100 )
	{
		t=-1;

	}

	setcolor(13);
	setfillstyle(1,13);
	sector(xg1,yg1,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(xg1-5,yg1-15,1,3);
	fillellipse(xg1+5,yg1-15,1,3);

	t++;

}

/* GHOST 2 */

void clyde_move(int &xg2,int &yg2,int &t)
{


	if( t>0 && t<190 )
	{
		setcolor(4);
		setfillstyle(1,4);
		sector(xg2,yg2,0,180,12,25);
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg2-5,yg2-15,1,3);
		fillellipse(xg2+5,yg2-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg2,yg2,0,180,12,25);
		yg2--;
	}

	else if( t>=190 && t<230 )
	{
		setcolor(4);
		setfillstyle(1,4);
		sector(xg2,yg2,0,180,12,25);
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg2-5,yg2-15,1,3);
		fillellipse(xg2+5,yg2-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg2,yg2,0,180,12,25);
		xg2--;
	}

	else if( t>=230 && t<350 )
	{
		setcolor(4);
		setfillstyle(1,4);
		sector(xg2,yg2,0,180,12,25);
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg2-5,yg2-15,1,3);
		fillellipse(xg2+5,yg2-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg2,yg2,0,180,12,25);
		yg2--;
	}

	else if( t>=350 && t<470 )
	{
		setcolor(4);
		setfillstyle(1,4);
		sector(xg2,yg2,0,180,12,25);
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg2-5,yg2-15,1,3);
		fillellipse(xg2+5,yg2-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg2,yg2,0,180,12,25);
		yg2++;
	}

	else if( t>=470 && t<510 )
	{
		setcolor(4);
		setfillstyle(1,4);
		sector(xg2,yg2,0,180,12,25);
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg2-5,yg2-15,1,3);
		fillellipse(xg2+5,yg2-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg2,yg2,0,180,12,25);
		xg2++;
	}

	else if( t>=510 && t<699 )
	{
		setcolor(4);
		setfillstyle(1,4);
		sector(xg2,yg2,0,180,12,25);
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg2-5,yg2-15,1,3);
		fillellipse(xg2+5,yg2-15,1,3);

		setcolor(0);
		setfillstyle(1,	0);
		sector(xg2,yg2,0,180,12,25);
		yg2++;
	}

	else if( t==699 )
	{
		t=0;

	}

	setcolor(4);
	setfillstyle(1,4);
	sector(xg2,yg2,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(xg2-5,yg2-15,1,3);
	fillellipse(xg2+5,yg2-15,1,3);

	t++;

}

/* GHOST 3 */

void inky_move(int &xg3,int &yg3,int &t)
{
	if( t>=0 && t<140 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg3,yg3,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg3-5,yg3-15,1,3);
		fillellipse(xg3+5,yg3-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg3,yg3,0,180,12,25);

		yg3--;

	}

	else if( t>=140 && t<355 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg3,yg3,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg3-5,yg3-15,1,3);
		fillellipse(xg3+5,yg3-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg3,yg3,0,180,12,25);

		xg3++;
	}

	else if( t>=355 && t<570 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg3,yg3,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg3-5,yg3-15,1,3);
		fillellipse(xg3+5,yg3-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg3,yg3,0,180,12,25);

		xg3--;
	}

	else if( t>=570 && t<710 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg3,yg3,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg3-5,yg3-15,1,3);
		fillellipse(xg3+5,yg3-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg3,yg3,0,180,12,25);

		yg3++;
	}

	else if( t==710 )
		t=-1;

	t++;

	setcolor(1);
	setfillstyle(1,1);
	sector(xg3,yg3,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(xg3-5,yg3-15,1,3);
	fillellipse(xg3+5,yg3-15,1,3);

}

/* GHOST 4 */

void blinky_move(int &xg4,int &yg4,int &t)
{
	if( t>=0 && t<170 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		xg4--;
	}

	else if( t>=170 && t<280 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		yg4--;
	}

	else if( t>=280 && t<415 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		xg4--;
	}

	else if( t>=415 && t<465 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		yg4++;
	}

	else if( t>=465 && t< 555 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		yg4--;
	}

	else if( t>=555 && t<650 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		xg4++;
	}

	else if( t>=650 && t<690 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		yg4++;
	}

	else if( t>=690 && t<730 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		xg4++;
	}

	else if( t>=730 && t<840 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		yg4++;
	}

	else if( t>=840 && t<1010 )
	{
		setcolor(1);
		setfillstyle(1,1);
		sector(xg4,yg4,0,180,12,25);

		setcolor(0);
		setfillstyle(1,0);
		fillellipse(xg4-5,yg4-15,1,3);
		fillellipse(xg4+5,yg4-15,1,3);

		setcolor(0);
		setfillstyle(1,0);
		sector(xg4,yg4,0,180,12,25);

		xg4++;
	}

	else if( t==1010 )
		t=-1;

	t++;

	setcolor(12);
	setfillstyle(1,12);
	sector(xg4,yg4,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(xg4-5,yg4-15,1,3);
	fillellipse(xg4+5,yg4-15,1,3);


}

void ghost_collide_down(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5)
{
	if ( ( y+15 ) == ( y2-24 ) && ( x==445 && x2==445 ) )
	{

		game_over();

	}

	else if( ( ( y+14 ) == ( y3-24 ) ) && ( ( x==490 && x3==490 ) || ( x==530 && x3==530 ) ) )
	{

		game_over();

		delay(1000);
	}

	else if( ( ( y+14 ) == ( y4-24 ) ) && ( x==145 && x4==145 ) )
	{
		game_over();

		delay(1000);
	}

	else if( ( y+14 ) == ( y5-24 ) && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{
		game_over();

		delay(1000);
	}


}


void pacman_down(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4)
{

	if ( ( y-14 ) == y2-1 && ( x2==445 && x==445 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14) == y3-1 && ( ( x3==490 && x==490 ) || ( x3==530 && x==530 ) ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == ( y4-1 ) && ( x4==145 && x==145 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == ( y5-1 ) && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{

		game_over();

	}



	else if(  x-15==x2+11 && ( y==70 && y2==80 ) )
	{


		game_over();

	}

	else if( ( x-15 ) == ( x3+11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) ||( y==110 && y3==120 ) ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x4+11 ) && ( y==240 && y4==250 ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x5+11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	{

		game_over();

	}



	else if( ( x+16 ) == ( x2-11 ) && ( y==70 && y2==80 ) )
	{
		game_over();
	}

	else if( ( x+16 ) == ( x3-11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) ||( y==110 && y3==120 ) ) )
	{

		game_over();
	}

	else if( ( x+16 ) == ( x4-11 ) && ( y==240 && y4==250 ) )
	{

		game_over();
	}

	else if( ( x+16 ) == ( x5-11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	{

		game_over();
	}

	//PACMAN MOVE

	 if( x==120 && y!=160 && y!=240 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==160 && y!=120 && y!=160 && y!=200 && y!=240 && y!=430 )
	 {
		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==180 && y!=200 )
	  {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==440 && y!=350 && y!=430 && y!=270 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==400 && y!=110 && y!=430 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==220 && y!=280 && y!=200 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==185 && y!=390 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x== 320 && y!=430 && y!=200 && y!=240 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==280 && y!=320 && y!=390 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==360 && y!=320 && y!=390 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==445 && y!=270 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==230 && y!=430)
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==485 && y!=430 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==530 && y!=430 && y!=190 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==490 && y!=230 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==485 && y!=430 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==145 && y!=390)
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }
	 else if( x==230 && y!=430 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);

		setcolor(0);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
		ghost_collide_down(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		y++;
	 }

	 if( y==160 || y==200 )
	 {
		setcolor(14);
		setfillstyle(1,14);
		fillellipse(x,y,15,15);
		setfillstyle(1,0);
		setcolor(0);
		pieslice(x,y,315,235,15);
	}



	pinky_move(x2,y2,t1);

	clyde_move(x3,y3,t2);

	inky_move(x4,y4,t3);

	blinky_move(x5,y5,t4);



	fscore(x,y);

}

void ghost_collide_up(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5)
{
	if ( ( y-14 ) == y2-1 && ( x2==445 && x==445 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14) == y3-1 && ( ( x3==490 && x==490 ) || ( x3==530 && x==530 ) ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == y4-1 && ( x4==145 && x==145 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == y5-1 && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{

		game_over();

	}

}
void pacman_up(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4)
{

	if ( ( y+15 ) == ( y2-24 ) && ( x==445 && x2==445 ) )
	{

		game_over();

	}

	else if( ( ( y+14 ) == ( y3-24 ) ) && ( ( x==490 && x3==490 ) || ( x==530 && x3==530 ) ) )
	{

		game_over();

		delay(1000);
	}

	else if( ( ( y+14 ) == ( y4-24 ) ) && ( x==145 && x4==145 ) )
	{
		game_over();

		delay(1000);
	}

	else if( ( y+14 ) == ( y5-24 ) && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{
		game_over();

		delay(1000);
	}



	else if(  x-15==x2+11 && ( y==70 && y2==80 ) )
	{


		game_over();

	}

	else if( ( x-15 ) == ( x3+11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) ||( y==110 && y3==120 ) ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x4+11 ) && ( y==240 && y4==250 ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x5+11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	{

		game_over();

	}




	 else if( ( x+16 ) == ( x2-11 ) && ( y==70 && y2==80 ) )
	 {
		game_over();
	 }

	 else if( ( x+16 ) == ( x3-11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) ||( y==110 && y3==120 ) ) )
	 {

		game_over();
	 }

	 else if( ( x+16 ) == ( x4-11 ) && ( y==240 && y4==250 ) )
	 {

		game_over();
	 }

	 else if( ( x+16 ) == ( x5-11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	 {

		game_over();
	 }

	//PACMAN MOVE


	if(  x==120 && y!=70 && y!=200 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==160 && y!=430 && y!=240 && y!=200 && y!=160 && y!=70 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==180 && y!=160 )
	 {


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==400 && y!=70 && y!=200 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==220 && y!=70 && y!=240 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==185 && y!=280 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==320 && y!=320 && y!=70 && y!=240 && y!=280)
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==280 && y!=280 && y!=360 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==360 && y!=360 && y!=280)
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==440 && y!=390 && y!=310 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==445 && y!=70 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==485 && y!=350 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==530 && y!=230 && y!=70 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==490 && y!=110 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}
	else if( x==145 && y!=240)
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}

	else if( x==230 && y!=390 )
	{


		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);

		 setcolor(0);
		 setfillstyle(1,0);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,55,135,15);
		 ghost_collide_up(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 y--;
	}

	setcolor(14);
	setfillstyle(1,14);
	fillellipse(x,y,15,15);
	setfillstyle(1,0);
	setcolor(0);
	pieslice(x,y,55,135,15);

	//GHOST MOVE

	pinky_move(x2,y2,t1);

	clyde_move(x3,y3,t2);

	inky_move(x4,y4,t3);

	blinky_move(x5,y5,t4);

	fscore(x,y);

}

void ghost_collide_left(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5)
{

	if(  x-15==x2+11 && ( y==70 && y2==80 ) )
	{


		game_over();


	}

	else if( ( x-16 ) == ( x3+11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) || ( y==110 && y3==120 ) ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x4+11 ) && ( y==240 && y4==250 ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x5+11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	{

		game_over();

	}

}
void pacman_left(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4)
{

	if ( ( y+15 ) == ( y2-24 ) && ( x==445 && x2==445 ) )
	{

		game_over();

	}

	else if( ( ( y+14 ) == ( y3-24 ) ) && ( ( x==490 && x3==490 ) || ( x==530 && x3==530 ) ) )
	{

		game_over();

		delay(1000);
	}

	else if( ( ( y+14 ) == ( y4-24 ) ) && ( x==145 && x4==145 ) )
	{
		game_over();

		delay(1000);
	}

	else if( ( y+14 ) == ( y5-24 ) && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{
		game_over();

		delay(1000);
	}

	else if ( ( y+14 ) == ( y2-24 ) && ( x==440 && x2==440 ) )
	{

		game_over();

	}

	else if( ( ( y+14 ) == ( y3-24 ) ) && ( ( x==490 && x3==490 ) || ( x==530 && x3==530 ) ) )
	{

		game_over();

		delay(1000);
	}

	else if( ( ( y+14 ) == ( y4-24 ) ) && ( x==145 && x4==145 ) )
	{
		game_over();

		delay(1000);
	}

	else if( ( y+14 ) == ( y5-24 ) && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{
		game_over();

		delay(1000);
	}




	else if ( ( y-14 ) == y2-1 && ( x2==445 && x==445 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14) == y3-1 && ( ( x3==490 && x==490 ) || ( x3==530 && x==530 ) ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == y4-1 && ( x4==145 && x==145 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == y5-1 && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{

		game_over();

	}



	else if(  x-15==x2+11 && ( y==70 && y2==80 ) )
	{


		game_over();

	}

	else if( ( x-15 ) == ( x3+11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) ||( y==110 && y3==120 ) ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x4+11 ) && ( y==240 && y4==250 ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x5+11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	{

		game_over();

	}

	//PACMAN MOVE


	if(  x!=120 && y==200 )
	{
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	 }
	 else if( x!=320 && y==155 )
	 {
	       setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	 }
	 else if( x!=120 && y==160 )
	 {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=160 && x!=120 && y==70 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=360 && x!=445 && y==110 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=185 && x!=320 && x!=120 && y==280 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }

	  else if( x!=185 && x!=360 && y==320 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if(x!=120 &&  y==240 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=320 && x!=120 && y==360 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=185 && x!=320 && y==390 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=120 && x!=320 && y==430 )
	  {

		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=440 && y==350 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=440 && y==310 )
	  {
		setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=490 && y==230 )
	  {
		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	  else if( x!=400 && y==270 )
	  {
		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(x,y,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(x,y,225,135,15);
		 ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		 x--;

	  }
	setcolor(0);
	setfillstyle(1,14);
	fillellipse(x,y,15,15);

	setfillstyle(1,0);
	setcolor(0);
	pieslice(x,y,225,135,15);


	pinky_move(x2,y2,t1);

	clyde_move(x3,y3,t2);

	inky_move(x4,y4,t3);

	blinky_move(x5,y5,t4);

	fscore(x,y);

}

void ghost_collide_right(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5)
{

	if( ( x+16 ) == ( x2-11 ) && ( y==70 && y2==80 ) )
	 {
		game_over();
	 }

	 else if( ( x+15 ) == ( x3-11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) ||( y==110 && y3==120 ) ) )
	 {

		game_over();
	 }

	 else if( ( x+16 ) == ( x4-11 ) && ( y==240 && y4==250 ) )
	 {

		game_over();
	 }

	 else if( ( x+16 ) == ( x5-11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	 {

		game_over();
	 }

}



void pacman_right(int &x,int &y,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4)
{

	if ( ( y+15 ) == ( y2-24 ) && ( x==445 && x2==445 ) )
	{

		game_over();

	}

	else if( ( ( y+14 ) == ( y3-24 ) ) && ( ( x==490 && x3==490 ) || ( x==530 && x3==530 ) ) )
	{

		game_over();

		delay(1000);
	}

	else if( ( ( y+14 ) == ( y4-24 ) ) && ( x==145 && x4==145 ) )
	{
		game_over();

		delay(1000);
	}

	else if( ( y+14 ) == ( y5-24 ) && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{
		game_over();
		delay(1000);
	}




	else if ( ( y-14 ) == y2-1 && ( x2==445 && x==445 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14) == y3-1 && ( ( x3==490 && x==490 ) || ( x3==530 && x==530 ) ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == y4-1 && ( x4==145 && x==145 ) )
	{

		game_over();
		delay(1000);
	}

	else if( ( y-14 ) == y5-1 && ( ( x5==320 && x==320 ) || ( x5==185 && x==185 ) || ( x5==280 && x==280 ) ) )
	{

		game_over();

	}



	else if(  x-15==x2+11 && ( y==70 && y2==80 ) )
	{


		game_over();

	}

	else if( ( x-15 ) == ( x3+11 ) && ( ( y==230 && y3==241 ) || ( y==310 && y3==320 ) ||( y==110 && y3==120 ) ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x4+11 ) && ( y==240 && y4==250 ) )
	{

		game_over();

	}

	else if( ( x-15 ) == ( x5+11 ) && ( ( y==320 && y5==330 ) || ( y==280 && y5==290 ) || ( y==430 && y5==440 ) ) )
	{

		game_over();

	}

	//PACMAN MOVE

	 if( x!=180 && y==160 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=400 && y==155 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=400 && y==200 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=120 && x!=530 && y==70 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	else if( x!=490 && x!=400 && y==110 )
	{


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=400 && y==240 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=280 && x!=360 && x!=145 && y==280 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=320 && x!=400 && y==320 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=185 && x!=360 && y==360 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=280 && x!=360 && y==390 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=485 && x!=260 && y==430 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	else if( x!=485 && y==350 )
	{


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=530 && y==310 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=530 && y==230 )
	 {


		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;

	 }
	 else if( x!=490 && y==270 )
	 {

		setcolor(14);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		setcolor(0);
		setfillstyle(1,14);
		pieslice(x,y,315,45,15);
		ghost_collide_left(x,y,x2,x3,x4,x5,y2,y3,y4,y5);
		x++;
	 }


	 setcolor(0);
	 setfillstyle(1,0);
	 fillellipse(x,y,15,15);

	 setcolor(0);
	 setfillstyle(1,14);
	 pieslice(x,y,315,45,15);



	 pinky_move(x2,y2,t1);

	 clyde_move(x3,y3,t2);

	 inky_move(x4,y4,t3);

	 blinky_move(x5,y5,t4);


	 fscore(x,y);

}

void fscore(int x,int y)
{

	static int score=0;
	static int a[100]={0};

	if( x==120 && y==120 && a[0]!=1 )
	{
		score+=100;
		a[0]=1;
	}

	else if ( x==120 && y==160 && a[1]!=1 )
	{
		score+=100;
		a[1]=1;
	}

	else if ( x==120 && y==240 && a[2]!=1 )
	{
		score+=100;
		a[2]=1;
	}

	else if ( x==120 && y==200 && a[3]!=1 )
	{
		score+=100;
		a[3]=1;
	}

	else if ( x==120 && y==280 && a[4]!=1 )
	{
		score+=100;
		a[4]=1;
	}

	else if ( x==120 && y==360 && a[5]!=1 )
	{
		score+=100;
		a[5]=1;
	}

	else if ( x==120 && y==430 && a[6]!=1 )
	{
		score+=100;
		a[6]=1;
	}

	else if ( x==160 && y==200 && a[7]!=1 )
	{
		score+=100;
		a[7]=1;
	}

	else if ( x==200 && y==200 && a[8]!=1 )
	{
		score+=100;
		a[8]=1;
	}

	else if ( x==240 && y==200 && a[9]!=1 )
	{
		score+=100;
		a[9]=1;
	}

	else if ( x==320 && y==200 && a[10]!=1 )
	{
		score+=100;
		a[10]=1;
	}

	else if ( x==360 && y==200 && a[11]!=1 )
	{
		score+=100;
		a[11]=1;
	}

	else if ( x==400 && y==200 && a[12]!=1 )
	{
		score+=100;
		a[12]=1;
	}

	else if ( x==160 && y==430 && a[13]!=1 )
	{
		score+=100;
		a[13]=1;
	}

	else if ( x==200 && y==430 && a[14]!=1 )
	{
		score+=100;
		a[14]=1;
	}

	else if ( x==240 && y==430 && a[15]!=1 )
	{
		score+=100;
		a[15]=1;
	}

	else if ( x==280 && y==430 && a[16]!=1 )
	{
		score+=100;
		a[16]=1;
	}

	else if ( x==160 && y==430 && a[17]!=1 )
	{
		score+=100;
		a[17]=1;
	}

	else if ( x==400 && y==240 && a[18]!=1 )
	{
		score+=100;
		a[18]=1;
	}

	else if ( x==400 && y==280 && a[19]!=1 )
	{
		score+=100;
		a[19]=1;
	}

	else if ( x==400 && y==320 && a[20]!=1 )
	{
		score+=100;
		a[20]=1;
	}

	else if ( x==400 && y==360 && a[21]!=1 )
	{
		score+=100;
		a[21]=1;
	}

	else if ( x==400 && y==400 && a[22]!=1 )
	{
		score+=100;
		a[22]=1;
	}

	else if ( x==400 && y==240 && a[23]!=1 )
	{
		score+=100;
		a[23]=1;
	}

	else if ( x==185 && y==390 && a[24]!=1 )
	{
		score+=100;
		a[24]=1;
	}

	else if ( x==280 && y==390 && a[25]!=1 )
	{
		score+=100;
		a[25]=1;
	}

	else if ( x==320 && y==120 && a[26]!=1 )
	{
		score+=100;
		a[26]=1;
	}

	else if ( x==320 && y==160 && a[27]!=1 )
	{
		score+=100;
		a[27]=1;
	}

	else if ( x==360 && y==155 && a[28]!=1 )
	{
		score+=100;
		a[28]=1;
	}

	else if ( x==400 && y==155 && a[29]!=1 )
	{
		score+=100;
		a[29]=1;
	}

	else if ( x==440 && y==270 && a[30]!=1 )
	{
		score+=100;
		a[30]=1;
	}

	else if ( x==480 && y==270 && a[31]!=1 )
	{
		score+=100;
		a[31]=1;
	}

	else if ( x==160 && y==115 && a[32]!=1 )
	{
		score+=100;
		a[32]=1;
	}

	else if ( x==220 && y==100 && a[33]!=1 )
	{
		score+=100;
		a[33]=1;
	}

	else if ( x==220 && y==140 && a[34]!=1 )
	{
		score+=100;
		a[34]=1;
	}

	else if ( x==220 && y==180 && a[35]!=1 )
	{
		score+=100;
		a[35]=1;
	}

	else if ( x==230 && y==390 && a[36]!=1 )
	{
		score+=100;
		a[36]=1;
	}

	else if ( x==280 && y==360 && a[37]!=1 )
	{
		score+=100;
		a[37]=1;
	}

	else if ( x==440 && y==390 && a[38]!=1 )
	{
		score+=100;

	}

	else if ( x==485 && y==390 && a[39]!=1 )
	{
		score+=100;
		a[39]=1;
	}

	else if ( x==485 && y==390 && a[40]!=1 )
	{
		score+=100;
		a[40]=1;
	}

	else if ( x==440 && y==350 && a[41]!=1 )
	{
		score+=100;
		a[41]=1;
	}

	else if ( x==440 && y==310 && a[42]!=1 )
	{
		score+=100;
		a[42]=1;
	}

	else if ( x==485 && y==310 && a[43]!=1 )
	{
		score+=100;
		a[43]=1;
	}

	else if ( x==530 && y==100 && a[44]!=1 )
	{
		score+=100;
		a[44]=1;
	}

	else if ( x==530 && y==140 && a[45]!=1 )
	{
		score+=100;
		a[45]=1;
	}

	else if ( x==530 && y==180 && a[46]!=1 )
	{
		score+=100;
		a[46]=1;
	}

	else if ( x==360 && y==110 && a[47]!=1 )
	{
		score+=100;
		a[47]=1;
	}

	else if ( x==400 && y==110 && a[48]!=1 )
	{
		score+=100;
		a[48]=1;
	}

	else if ( x==320 && y==280 && a[49]!=1 )
	{
		score+=100;
		a[49]=1;
	}

	else if ( x==360 && y==280 && a[50]!=1 )
	{
		score+=100;
		a[50]=1;
	}

	else if ( x==360 && y==320 && a[51]!=1 )
	{
		score+=100;
		a[51]=1;
	}

	else if ( x==485 && y==350 && a[52]!=1 )
	{
		score+=100;
		a[52]=1;
	}

	char sc[5];
	itoa(score,sc,10);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(600,0,30,30);

	setcolor(14);
	settextstyle(3,0,1);
	outtextxy(525,0,"Score:");
	outtextxy(580,0,sc);

	if( sc=="30000 ")
		game_over();
	gscore=score;


}

void food()
{

	setcolor(3);
	setfillstyle(1,3);

	pieslice(120,120,0,360,3);
	pieslice(120,160,0,360,3);
	pieslice(120,240,0,360,3);
	pieslice(120,200,0,360,3);
	pieslice(120,280,0,360,3);
	pieslice(120,360,0,360,3);
	pieslice(120,430,0,360,3);

	pieslice(160,200,0,360,3);
	pieslice(200,200,0,360,3);
	pieslice(240,200,0,360,3);
	pieslice(280,200,0,360,3);
	pieslice(320,200,0,360,3);
	pieslice(360,200,0,360,3);
	pieslice(400,200,0,360,3);

	pieslice(160,430,0,360,3);
	pieslice(200,430,0,360,3);
	pieslice(240,430,0,360,3);

	pieslice(400,240,0,360,3);
	pieslice(400,280,0,360,3);
	pieslice(400,320,0,360,3);
	pieslice(400,360,0,360,3);
	pieslice(400,400,0,360,3);

       pieslice(185,390,0,360,3);
       pieslice(280,390,0,360,3);

       pieslice(320,120,0,360,3);
       pieslice(320,160,0,360,3);

       pieslice(360,155,0,360,3);
       pieslice(400,155,0,360,3);

       pieslice(440,270,0,360,3);
       pieslice(480,270,0,360,3);

       //ADDED NOW

       pieslice(160,115,0,360,3);

       pieslice(220,100,0,360,3);
       pieslice(220,140,0,360,3);
       pieslice(220,180,0,360,3);

       pieslice(230,390,0,360,3);
       pieslice(280,360,0,360,3);

       pieslice(485,350,0,360,3);
       pieslice(485,390,0,360,3);

       pieslice(440,350,0,360,3);
       pieslice(440,310,0,360,3);
       pieslice(485,310,0,360,3);

       pieslice(530,100,0,360,3);
       pieslice(530,140,0,360,3);
       pieslice(530,180,0,360,3);

       pieslice(360,110,0,360,3);
       pieslice(400,110,0,360,3);

       pieslice(320,280,0,360,3);
       pieslice(360,280,0,360,3);
       pieslice(360,320,0,360,3);

}

struct highscore
{
	int cscore;
	char cname[40];

	void accept()
	{
		cscore=gscore;
		strcpy(cname,name);
	}
	void display(int i)
	{
		char csc[5];
		itoa(cscore,csc,10);

		settextstyle(SMALL_FONT,0,6);
		outtextxy(80,i,cname);
		outtextxy(200,i,csc);

	}

};

void game_over()
{

	cleardevice();

	setcolor(4);
	settextstyle(0, HORIZ_DIR, 5);
	outtextxy(150,180,"GAME OVER");

	int r=4;

	setcolor(15);
	settextstyle(1, HORIZ_DIR, 1);

	int i=random(r);
	if(i==0)
	{
		outtextxy(155,250,"The lannisters send their regards");

	}
	else if(i==1)
	{
		outtextxy(155,250,"When you play the Game of Thrones, you win ");
		outtextxy(155,270,"or you die");


	}
	else if(i==2)
	{
		outtextxy(155,250,"For the night is dark and full of terrors");


	}
	else if(i==3)
	{
		outtextxy(155,250,"A man who fears losing has already lost");

	}

	fstream f1("hs.dat",ios::in|ios::binary);
	fstream f2("hsbkp.dat",ios::out|ios::trunc|ios::binary);

	highscore h,t;

	t.accept();

	int tp=0;

	while( f1.read((char *)&h,sizeof(h)))
	{
		if( ( t.cscore>=h.cscore ) && tp==0 )
		{
			f2.write((char *)&t,sizeof(t));
			f2.write((char *)&h,sizeof(h));
			tp=1;
		}
		else
			f2.write((char *)&h,sizeof(h));
	}

	f1.close();
	f2.close();

	remove("hs.dat");
	rename("hsbkp.dat","hs.dat");

	delay(2000);

	cleardevice();

	outtextxy(80,135,"To Play Again Press Y");

	char ch1;
	ch1=getch();

	if( ch1=='Y' || ch1=='y' )
		details(name);
	else
		exit(0);

}

void maze(char n[])
{

	 cleardevice();

	 setlinestyle(0,0,0);
	 setcolor(15);

	 rectangle(100,450,550,50);

	 line(140,140,140,50);

	 line(200,140,140,140);

	 line(200,180,200,90);

	 line(200,90,180,90);

	 line(180,140,180,90);

	 line(160,180,100,180);

	 line(240,140,240,90);

	 line(300,90,240,90);

	 line(300,180,300,90);

	 line(240,140,300,140);

	 line(300,180,240,180);

	 line(100,410,210,410);

	 line(300,340,205,340);

	 line(300,340,300,450);

	 line(300,410,250,410);

	 line(205,300,260,300);

	 line(240,260,380,260);

	 line(165,340,165,260);

	 line(165,260,200,260);

	 line(100,260,125,260);

	 line(100,300,125,300);

	 line(140,220,350,220);

	 line(340,90,340,130);

	 line(380,90,340,90);

	 line(340,130,420,130);

	 line(420,90,420,250);

	 line(510,90,470,90);

	 line(510,90,510,210);

	 line(510,210,550,210);

	 line(470,130,470,250);

	 line(510,250,470,250);

	 line(510,290,510,250);

	 line(420,290,510,290);

	 line(420,290,420,410);

	 line(420,370,460,370);

	 line(460,410,460,370);

	 line(460,330,510,330);

	 line(510,450,510,330);

	 line(340,410,380,410);

	 line(380,340,380,410);

	 line(380,340,340,340);

	 line(340,300,340,340);

	 line(300,300,340,300);

	 line(380,300,380,260);

	 line(340,180,420,180);

	 line(300,300,300,260);

	 line(380,220,350,220);

	 line(125,300,125,340);

	 line(420,410,460,410);

	 line(125,380,125,410);

	 line(165,410,165,380);

	 line(125,340,100,340);

	 line(125,380,100,380);

	 line(205,340,205,370);

	 line(205,370,260,370);

	 line(260,370,260,340);

	 setcolor(14);

	 settextstyle(3,0,1);

	 outtextxy(0,0,"Player Name :");

	 outtextxy(140,0,n);

	 food();

	 int x1=145,y1=260;

	 int x2=160,y2=80;

	 int x3=530,y3=430;

	 int x4=145,y4=390;

	 int x5=490,y5=440;

	 int t1=0,t2=1,t3=0,t4=0;

	 pacman_move(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,t1,t2,t3,t4);

}

void pacman_move(int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4,int &x5,int &y5,int &t1,int &t2,int &t3,int &t4)
{
	 char ch;
	 ch=getch();
	 while(ch!=1)
	 {
		if(ch==80)
			pacman_down(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,t1,t2,t3,t4);
		else if(ch==77)
			pacman_right(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,t1,t2,t3,t4);
		else if(ch==75)
			pacman_left(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,t1,t2,t3,t4);
		else if(ch==72)
			pacman_up(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,t1,t2,t3,t4);
		else if(ch==27)
			game_over();
		ch=getch();
	}
}

void pinky_down()
{
	setcolor(13);
	setfillstyle(1,13);
	sector(420,435,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(415,419,1,3);
	fillellipse(425,419,1,3);

}
void inky_down()
{
	setcolor(3);
	setfillstyle(1,3);
	sector(460,435,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(455,419,1,3);
	fillellipse(465,419,1,3);

}

void blinky_down()
{
	setcolor(4);
	setfillstyle(1,4);
	sector(500,435,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(495,419,1,3);
	fillellipse(505,419,1,3);

}

void clyde_down()
{
	setcolor(12);
	setfillstyle(1,12);
	sector(540,435,0,180,12,25);

	setcolor(0);
	setfillstyle(1,0);
	fillellipse(535,419,1,3);
	fillellipse(545,419,1,3);

}

void mainpage()
{
	setbkcolor(0);
	delay(500);

	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");

	settextstyle(0,0,4);

	setcolor(14);
	setfillstyle(1,14);
	outtextxy(220,122,"PACMAN");

	pieslice(450,135,0,360,17);

	setcolor(0);
	line(440,131,460,131);
	line(440,130,460,130);

	setfillstyle(9,14);
	pieslice(444,132,180,360,4);
	pieslice(456,132,180,360,4);
	arc(450,140,270,360,10);

	setcolor(15);
	arc(454,112,280,360,5);
	arc(457,112,280,360,5);
	delay(500);

	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	outtextxy(520,314,"LOADING ...");

	setcolor(3);
	pieslice(200,422,0,360,3);
	pieslice(400,422,0,360,3);

	for(int i=0;i<350;i++)                  //LOADING EFFECT START
	{
		delay(3);
		setfillstyle(1,14);
		setcolor(14);
		pieslice(i,425,315,45,15);

		setcolor(0);
		pieslice(i,425,315,45,15);

		delay(2);

	}

	inky_down();
	pinky_down();
	blinky_down();
	clyde_down();

	for(i=350;i>0;i--)
	{
		 delay(3);
		 setcolor(14);
		 setfillstyle(1,14);
		 fillellipse(i,425,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(i,425,225,135,15);

		 setcolor(0);
		 setfillstyle(1,14);
		 fillellipse(i,425,15,15);
		 setfillstyle(1,0);
		 setcolor(0);
		 pieslice(i,425,225,135,15);
		 delay(2);
	}

	outtextxy(420,410,"LOADING...");        //LOADING EFFECT END
	cleardevice();

}

void letsplay()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");

	settextstyle(0,0,4);
	setcolor(14);
	setfillstyle(1,14);
	outtextxy(220,122,"PACMAN");

	pieslice(450,135,0,360,17);
	setcolor(0);
	line(440,131,460,131);
	line(440,130,460,130);

	setfillstyle(9,14);
	pieslice(444,132,180,360,4);
	pieslice(456,132,180,360,4);

	setcolor(0);
	arc(450,140,270,360,10);

	settextstyle(DEFAULT_FONT,0,1);
	setcolor(3);
	outtextxy(460,160,"Lets Play(^_^)");

	setcolor(15);
	arc(454,112,280,360,5);
	arc(457,112,280,360,5);

	settextstyle(SANS_SERIF_FONT,0,3);

	while(!kbhit())                           //BLINKING TEXT
	{
		setcolor(12);
		outtextxy(180,400,"Press any key to Continue...");

		setcolor(0);
		delay(500);

		outtextxy(180,400,"Press any key to Continue...");
		delay(500);
	}

	getch();
	cleardevice();

}

void help(char n[])
{
	cleardevice();
	char ch;

	setcolor(14);
	settextstyle(0, HORIZ_DIR, 5);
	outtextxy(250,50,"HELP");
	setcolor(15);

	settextstyle(SMALL_FONT,0,8);
	outtextxy(80,100,"CONTROLS");

	settextstyle(SMALL_FONT,0,6);

	outtextxy(80,135,"Press up arrow to go up");
	outtextxy(80,160,"Press down arrow to go down");
	outtextxy(80,185,"Press left arrow to go left");
	outtextxy(80,210,"Press right arrow to go right");
	outtextxy(80,235,"Press esc to quit at any time");
	outtextxy(80,260,"Press enter to return to the previous screen");
	outtextxy(80,285,"Wait till the pacman reaches near the line to change ");
	outtextxy(80,310,"direction");

	int a=236;
	char t[10];
	t[0]=char(a);
	t[1]='\0';
	outtextxy(425,335,t);
	outtextxy(80,335,"There is a place where you can get   points");

	outtextxy(80,410,"CAUTION : BE AWARE DURING THE GAME");

	settextstyle(2,0,4);
	outtextxy(420,430,"Press Esc to Exit the Game ");
	outtextxy(420,440,"Press Enter to go back");

	line(80,420,410,420);
	line(80,421,410,421);

	ch=getch();
	cleardevice();

	if(ch==13)
		menu(n);
	else if(ch==27)
		exit(0);

}

void about(char n[])
{
	cleardevice();
	char ch;

	setcolor(14);
	settextstyle(0, HORIZ_DIR, 5);
	outtextxy(250,50,"ABOUT");
	setcolor(15);

	settextstyle(SANS_SERIF_FONT,0,3);
	outtextxy(80,135,"Created by:");
	outtextxy(80,160,"Kesav Ravichandran ");
	outtextxy(80,185,"and");
	outtextxy(80,210,"Keshav Balachandar");
	outtextxy(80,235,"Class 12 Annual project");
	outtextxy(80,260,"2016-17");

	settextstyle(2,0,4);
	outtextxy(420,430,"Press Esc to Exit the Game ");
	outtextxy(420,440,"Press Enter to go back");

	ch=getch();
	cleardevice();

	if(ch==13)
		menu(n);
	else if(ch==27)
		exit(0);

}

void high_score(char n[])
{
	cleardevice();
	char ch;

	setcolor(14);
	settextstyle(0, HORIZ_DIR, 5);
	outtextxy(150,80,"HIGHSCORES");
	setcolor(15);

	fstream f("hs.dat",ios::in|ios::binary);
	highscore h;
	int i=155;
	while(f.read((char *)&h,sizeof(h)))
	{
		if( i<400 )
			h.display(i);

		i+=20;

	}

	f.close();

	settextstyle(2,0,4);
	outtextxy(420,430,"Press Esc to Exit the Game ");
	outtextxy(420,440,"Press Enter to go back");

	ch=getch();
	cleardevice();

	if(ch==13)
		menu(n);
	else if(ch==27)
		exit(0);

}

void menu(char n[])
{
	cleardevice();
	char ch[10];

	settextstyle(SANS_SERIF_FONT,0,3);
	outtextxy(105,105,"Press 1 to Start the Game");
	outtextxy(105,125,"Press 2 For Help");
	outtextxy(105,145,"Press 3 To see highscores");
	outtextxy(105,165,"Press 4 To get inspired");
	outtextxy(105,187,"Press 5 to Exit ");

	outtextxy(105,312,"Enter your choice :");      //GET CHOICE FOR MENU

	ch[0]=getch();                                 //ACCEPTING USER ENTRY
	ch[1]='\0';

	outtextxy(320,312,ch);
	delay(300);

	if(ch[0]=='1')
		maze(n);
	else if(ch[0]=='2')
		help(n);

	else if(ch[0]=='3')
		high_score(n);

	else if(ch[0]=='4')
		about(n);

	else if(ch[0]=='5')
		game_over();

}

void details(char n[])
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

	settextstyle(SANS_SERIF_FONT,0,1);

	for(int t=0;t<73;t++)
		cout<<'\t';
	for(t=0;t<12;t++)
		cout<<" ";

	outtextxy(110,105,"ENTER YOUR NAME :");
	gets(n); 					//GET PLAYER NAME
	strcpy(name,n);

	for(int i=0;i<12;i++)
		for(t=0;t<80;t++)
			cout<<" ";
	for(t=0;t<35;t++)
		cout<<" ";

	menu(n);
}

void main()
{
	randomize();
	clrscr();
	char n[100];

	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

	cleardevice();
	setbkcolor(0);
	setcolor(4);
	mainpage();                        //CALLING MAIN FUNCTIONS
	letsplay();
	details(n);
	getch();
}
