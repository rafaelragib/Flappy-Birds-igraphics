# include "iGraphics.h"
#include<string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int menu = 0;
int pillergap=300;
int dx = 400, pd1y = 0, dx2 = 600, pd2y = 0, dx3 = 800, pd3y = 0;
int brickcountd1 = 0, brickcountd2 = 0, brickcountd3 = 0;
int scrnwe = 600;
int scrnhe = 400;
int score = 0;
//int pillerpass = 20;
void change();
void moveBird();
void bricks();
void res();
char bckground[20][80] = { "Changed photos//1.bmp", "Changed photos//2.bmp", "Changed photos//3.bmp", "Changed photos//4.bmp", "Changed photos//5.bmp", "Changed photos//6.bmp", "Changed photos//7.bmp", "Changed photos//8.bmp", "Changed photos//9.bmp", "Changed photos//10.bmp", "Changed photos//11.bmp", "Changed photos//12.bmp", "Changed photos//13.bmp", "Changed photos//14.bmp", "Changed photos//15.bmp", "Changed photos//16.bmp", "Changed photos//17.bmp", "Changed photos//18.bmp", "Changed photos//19.bmp", "Changed photos//20.bmp" };
int BirdY = 200;
int BirdX = 100;
void collision();
void highscore();
void scr();
void showhighscore();
struct background
{
	int x;
};
background land[20];

char str[80];
void iDraw()
{


	iClear();
	if(menu==0)
	iShowBMP(0, 0, "menu.bmp");
	if(menu==2){
	showhighscore();
	
	}
	if (menu == 1)
	{

		for (int i = 0; i < 20; i++)
		{
			iShowBMP(land[i].x, 0, bckground[i]);
			iShowBMP2(BirdX, BirdY, "birdy.bmp", 0);

		}
		bricks();
		collision();
		
		iShowBMP(0,0,"sidepanel.bmp");
		iSetColor(255, 255, 0);
		_itoa_s(score, str, 10);
		iText(10, 350, "Score",  GLUT_BITMAP_HELVETICA_18);
		iText(65, 350, str,  GLUT_BITMAP_HELVETICA_18);
		iText(10,250,"q to go ", GLUT_BITMAP_HELVETICA_18);
		iText(10,200,"back",GLUT_BITMAP_HELVETICA_18);
	}
}

int random1 = 3;
int random2 = 2;
int random3 = 4;
void bricks()
{
	if (menu == 1)
	{
	
		int height1 = 0;
		if (brickcountd1 == 1){
			random1 = 2 + rand() % 9;
		}
		for (int i = 0; i<random1; i++){
			iShowBMP(dx, height1, "brick4.bmp");
			height1 += 23;
		}
		iShowBMP(dx, height1, "pillerdowntop.bmp");
		iShowBMP(dx, random1 * 25 + 85, "pillerup.bmp");
		int height2 = 0;
		if (brickcountd2 == 1){
			random2 = 2 + rand() % 10;
		}
		for (int i = 0; i<random2; i++){
			iShowBMP(dx2, height2, "brick4.bmp");
			height2 += 23;
		}
		iShowBMP(dx2, height2, "pillerdowntop.bmp");
		iShowBMP(dx2, random2 * 25 + 85, "pillerup.bmp");
		
		int height3 = 0;
		if (brickcountd3 == 1){
			random3 = 2 + rand() % 9;
		}
		for (int i = 0; i<random3; i++){
			iShowBMP(dx3, height3, "brick4.bmp");
			height3 += 23;
		}
		iShowBMP(dx3, height3, "pillerdowntop.bmp");
		iShowBMP(dx3, random3 * 25 + 85, "pillerup.bmp"); 
	}
		
}

void pillarmove()
{
	if (menu==1)
	{
		dx -= 2;
		dx2 -= 2 ;
		dx3 -= 2;
		if (dx <= 0){
			dx = 600;
			brickcountd1 = 1;
		}
		if (dx == 596){
			brickcountd1 = 0;
		}
		if (dx2 <= 0){
			dx2 = 600;
			brickcountd2 = 1;
		}
		if (dx2 == 596){
			brickcountd2 = 0;
		}
		if (dx3 <= 0){
			dx3 = 600;
			brickcountd3 = 1;
		}
		if (dx3 == 596){
			brickcountd3 = 0;
		}
		if (BirdX == dx + 38 || BirdX == dx2 + 38|| BirdX==dx3+38)
			score++;
	}
}
void res()
{
	 BirdY = 200;
	 BirdX = 100;
	 dx = 400, pd1y = 0, dx2 = 600, pd2y = 0, dx3 = 800, pd3y = 0;
	 score = 0;
	brickcountd1 = 0, brickcountd2 = 0, brickcountd3 = 0;
}
void collision()
{
	
	
	if(BirdX+32==dx && BirdY<=(random1+1)*23||BirdX+32==dx && BirdY>=(random1+1)*23+62  || BirdX+32==dx2 && BirdY<=(random2+1)*23 || BirdX+32==dx2 && BirdY>=(random2+1)*23+62||BirdX+32==dx3 && BirdY<=(random3+1)*23 ||BirdX+32==dx3 && BirdY>(random3+1)*23+62){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(100, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
     if((BirdY <= (random1+1)*21) && (BirdX+20>=dx) && (BirdX<=dx+24)){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(100, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
	 else if((BirdY <= (random2+1)*21) && (BirdX+20>=dx2) && (BirdX<=dx2+24)){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(100, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
	else if((BirdY <= (random3+1)*21) && (BirdX+20>=dx3) && (BirdX<=dx3+24)){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(150, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
	else if((BirdY+25 >= (random1+1)*23+62) && (BirdX+32>=dx) && (BirdX<=dx+35)){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(100, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);

	}
	else if((BirdY+25 >= (random2+1)*23+62) && (BirdX+32>=dx2) && (BirdX<=dx2+35)){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(100, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
	else if((BirdY+25 >= (random3+1)*23+62) && (BirdX+32>=dx3) && (BirdX<=dx3+35)){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(150, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
	else if(BirdY<=0||BirdY+28>=scrnhe || BirdX<=0 || BirdX+32>=scrnwe){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		//iShowBMP2(150, 150, "Game_Over_Screen.bmp", 0);
		highscore();
		res();
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here



 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == '1')
	{
		menu = 1;
	}
	if(key == 'q')
	{
		menu =0;
		highscore();
		res();
	}
	if(key=='2')
	{
		menu=2;
		showhighscore();
	}
	if(key == '3')
		exit(0);
	//place your codes for other keys here
}
void showhighscore()
{
	char str[4];
	char str1[4];
	char str2[4];
	char str3[4];
	FILE *fp;
	fp=fopen("scorelist.txt","r");
	int scoreli[4];
	for(int i=0;i<4;i++)
	fscanf(fp,"%d",&scoreli[i]);
	iShowBMP(0,0,"highscore.bmp");
	itoa(scoreli[0], str, 10);
	itoa(scoreli[1], str1, 10);
	itoa(scoreli[2], str2, 10);
	itoa(scoreli[3], str3, 10);
	iText(200,300,str,GLUT_BITMAP_HELVETICA_18);
	iText(200,250,str1,GLUT_BITMAP_HELVETICA_18);
	iText(200,200,str2,GLUT_BITMAP_HELVETICA_18);
	iText(200,150,str3,GLUT_BITMAP_HELVETICA_18);
	fclose(fp);

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_UP)
	{
		moveBird();
	}
	//place your codes for other keys here
}


void highscore()
{
	FILE *fp;
	fp = fopen("scorelist.txt", "r");
	int scoreli[4];
	for(int i=0;i<4;i++)
	fscanf(fp,"%d",&scoreli[i]);
	fclose(fp);
	if(score>scoreli[3])
		scoreli[3]=score;
	for (int c = 0 ; c <  (4 - 1) ; c++)
  {
    for (int d = 0 ; d < 4 - c - 1; d++)
    {
      if (scoreli[d] < scoreli[d+1]) 
      {
        int swap       = scoreli[d];
        scoreli[d]   = scoreli[d+1];
        scoreli[d+1] = swap;
}
	}
	}
	fp=fopen("scorelist.txt","w");
	for(int i=0;i<4;i++)
	fprintf(fp,"%d\n",scoreli[i]);
	fclose(fp);
}
void changebg()
{
	int sum;
	sum = 0;
	for (int i = 0; i < 20; i++)
	{

		land[i].x = sum;
		sum += 30;
	}
}
void moveBird()
{
	if (menu = 1)
	{

		BirdY += 20;
	}
}

void bgrend()
{
	for (int i = 0; i < 20; i++)
	{

		land[i].x -= 30;
		if (land[i].x <= 0)
			land[i].x = 570;
	}
	
}
void birdgravity()
{
	if (menu == 1)
	{
		BirdY -= 2;
		if(score>5)
			BirdY-=2;
		
	}
}
int main()
{
	iSetTimer(300, bgrend);
	iSetTimer(10, pillarmove);
	iSetTimer(25, birdgravity);
	changebg();
	iInitialize(600,400, "Flappy Birds");
	return 0;
}
