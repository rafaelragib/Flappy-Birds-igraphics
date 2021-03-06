# include "iGraphics.h"
# include <stdio.h>

int page = 0; 
int Length = 0; 
int i = 0;
double BallPosX = 400;
double BallPosY = 400; 
int m = 0, n = 0;
bool ballMovingRight = false;
bool ActivateBox = false;
char score1[5];
FILE *fp;

bool ScoreOnceChecked = true;

char scorePrint[5];
char scorePrint1[5];
char scorePrint2[5];
char scorePrint3[5];
char scorePrint4[5];

struct player{
	char name[100];
	int score;
}player, saved[100],temp;

int PlayerNumber = 0;

void ScoreCheck()
{

	if(ScoreOnceChecked) 
		// I couldn't find out why this function is being called twice.
		// so to stop this, I have used a boolean variable that is true by default 
		//and is false after the function is called once.
	{
		player.score = rand() % 10;
		// Generating a random number and storing it in Player score.
		// polayer score is different. It is the score of the current player who is playing the game at the moment.

		printf("%d \n" , player.score); // printing it just for debugging purpose.

		for(int j = 0; j<5 ;j++)
		{
			if(player.score > saved[j].score)
			{
				for(int k = 4 ; k>j ; k--)
				{
					saved[k] = saved[k-1];
				}
				saved[j] = player;
				PlayerNumber = j; 
				// There were five scores in the Text file. What I'm doing here is trying to find out
				// the rank of the current player's score. Also Storing the postion in a variable.
				
				// high score.txt
				// example:		name		score    
				//			 Player1		200
				//			 Player2		150
				//			 player3		130
				//			 player4		100
				//			 player5		70

				// ##       Current Player 160

				// Now, let the current player has scored 160. So in this block i'll find out 
				//which position current player is holding. 


				// PlayerNumber = 2; // this variable holds the position to take the name input for this particular position.


				break;  // I just need the position. So breaking the search If I get one.
			}
		}
	}

	for(int j = 0; player.name[j] != NULL ; j++)
				{
					saved[PlayerNumber].name[j] = player.name[j];
				}
					// Now Placing the name of current player in the particular position as mentioned above.

	ScoreOnceChecked = false;
}




void ballmovement()
{
	if (ballMovingRight)
	{
		if (BallPosX <= 40)
			ballMovingRight = false;
		else
			BallPosX = BallPosX -= 10;
	}
	if (!ballMovingRight)
	{
		if (BallPosX >= 500 - 40)
			ballMovingRight = true;
		else
			BallPosX += 10;
	}
}

void mainPage(){
		iRectangle(200, 270, 100, 60);
		iText(210, 295, ":Insert name:");
		iRectangle(200, 200, 100, 60);
		iText(215, 225, ":Play Game:");
		iRectangle(200, 130, 100, 60);
		iText(210, 155, ":High Score:");
}

void namePage(){
		iRectangle(160, 270, 150, 60);
		iText(170, 295, "Enter your name");
		iRectangle(160, 200, 150, 60);
		iText(170, 225, player.name);
		iRectangle(300, 50, 100, 60);
		iText(335, 75, "Exit");
}

void gamePage(){
		iFilledCircle(BallPosX, BallPosY, 40);
		iRectangle(300, 50, 100, 60);
		iText(335, 75, "Exit");
}

void highScorePage(){

	// Using sprintf to print the number into a character array. and then using that character array in iText.


		iText(200, 350, "--High Score--");
		iSetColor(255,0,0);
		iText(95,330, saved[0].name);
		iText(250,330, scorePrint4 );
			sprintf(scorePrint4 , "%d" , saved[0].score);

		iSetColor(255,0,0);
		iText(95,290, saved[1].name);
		iText(250,290, scorePrint3 );	
			sprintf(scorePrint3 , "%d" , saved[1].score);

		iSetColor(255,0,0);
		iText(95,250, saved[2].name);
		iText(250,250, scorePrint2 );
			sprintf(scorePrint2 , "%d" , saved[2].score);
		
		iSetColor(255,0,0);
		iText(95,210, saved[3].name);
		iText(250,210, scorePrint1);
			sprintf(scorePrint1 , "%d" , saved[3].score);
		
		iSetColor(255,0,0);
		iText(95,170, saved[4].name);
		iText(250,170, scorePrint);
			sprintf(scorePrint , "%d" , saved[4].score);
		iText(335, 75, "Exit");
}

void iDraw()
{
	iClear();

	if (page == 0)
		mainPage();
	else if (page == 1)
		namePage();
	else if (page == 2)
		gamePage();
	else if (page == 3)
		highScorePage();
}

void iMouseMove(int mx, int my){}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if ( page == 0 ){
			if (mx >= 200 && mx <= 300 && my >= 270 && my <= 330)
			{
				page = 1;
				ScoreOnceChecked = true;  // this mouse click means that player wants to insert his name.
										// as he can insert his name, that means he will have a score. 
										// so score checking will take place again.
			}
			else if (mx >= 200 && mx <= 300 && my >= 200 && my <= 260)
				page = 2;
			else if (mx >= 200 && mx <= 300 && my >= 130 && my <= 190)
				page = 3;
		}
		if (page == 1){
			if (mx >= 160 && mx <= 310 && my >= 200 && my <= 260)
				ActivateBox = true;
			else if (mx >= 300 && mx <= 400 && my >= 50 && my <= 110)
				page = 0;
		}
		if(page == 2)
			if (mx >= 300 && mx <= 400 && my >= 50 && my <= 110)
				page = 0;

		if(page == 3)
			if (mx >= 300 && mx <= 400 && my >= 50 && my <= 110)
				page = 0;
	}
}

void iPassiveMouseMove(int mx,int my){}


void iKeyboard(unsigned char key)
{
	if (ActivateBox){
		if (key == '\r')
		{
			ScoreCheck();	// Called the score check funtion. This function check if the current player has scored amongst five others(saved).
							// This function is called everytime a name is entered. 

				fp = fopen("High Scores.txt" , "w");   
				
				for(int j = 0 ; j < 5 ; j++)    /// printing in the file.
				{
					fputs(saved[j].name , fp);
					fprintf(fp, " %d\n", saved[j].score);
				}



				for (int j = 0; j < Length; j++)
				{
					player.name[j] = NULL;
					Length = 0;
				}

				fclose(fp);
			
		}

		else
		{
			player.name[Length] = key;
			Length++;
		}
	}
}

void iSpecialKeyboard(unsigned char key){}
int main()
{
	fp = fopen("High Scores.txt", "r+" );
	i = 0;
	while (fscanf(fp, "%s %d", &saved[i].name, &saved[i].score) != EOF)
		i++;
	fclose(fp);    // opening the file. and reading names and score from it.

	for(int j = 0; j<4 ; j++)  // Sorting the data of the file for further use.
		for(int k = j+1 ; k < 5 ; k++)
			if(saved[j].score < saved[k].score)
			{
				temp = saved[j];
				saved[j] = saved[k];
				saved[k] = temp;
			}

	iSetTimer(10, ballmovement);
	iInitialize(500, 500, "Assignment!");
	return 0;
}	