#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <ctime>
#include <stdlib.h>
#include <string>

#include "layout.h"
#include "gameplay.h"

// float x_pos = 0.0, y_pos = 0.0;
int i = 0, j = 0, submenu_id, menu_id, value = 0;
float x = 100.0, y = 10.0, speed, spaceP;
float xPos[4] = {50.0, 150.0, 250.0, 350.0},
      yPos[6] = {20.0, 0.0, 0.0, 0.0};
      
void menu(int num){
	value=num;
	glutPostRedisplay();
}

void delay(float secs)
{
	float end = clock() / CLOCKS_PER_SEC + secs;
	while ((clock() / CLOCKS_PER_SEC) < end);
}

void drawButton(float x, float y){
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
    glVertex2f(x - 5.0, y + 3.0);
    glVertex2f(x - 5.0, y - 3.0);
    glVertex2f(x + 5.0, y - 3.0);
    glVertex2f(x + 5.0, y + 3.0);
  glEnd();
}

void homeLayout(){
  glColor3f(1.0, 1.0, 1.0);
  drawBitmapText((char*)"Play", -3.0, -12.0, 0);
  drawButton(0.0, -10);
  glColor3f(1.0, 1.0, 1.0);
  drawBitmapText((char*)"Exit", -3.0, -22.0, 0);
  drawButton(0.0, -20);
}


void createMenu(void){
    submenu_id=glutCreateMenu(menu);
	glutAddMenuEntry("LEVEL 1 (EASY)", 1);
	glutAddMenuEntry("LEVEL 2 (MEDIUM)", 2);
	glutAddMenuEntry("LEVEL 3 (HARD)", 3);
	menu_id=glutCreateMenu(menu);
	glutAddSubMenu("PLAY GAME",submenu_id);
//    glutAddMenuEntry("QUIT", 4);     
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

void drawBitmapText(char *string, float xa, float yb, float zc)
{
  char *c;
  glRasterPos3f(xa, yb, zc);

  for (c = string; *c != '\0'; c++)
  {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
  }
}

void timer(int)
{
	if (value != 0 && value != 4){
	  glutPostRedisplay();
	  srand(time(0));
	  for (i = 0; i < 4; i++)
	  {
	    if (xPos[i] == -250)
	    {
	      	xPos[i] = 150.0;
	      	yPos[i] = rand() % 50 + 1;
	    }
	  }
	  xPos[0] -= speed;
	  xPos[1] -= speed;
	  xPos[2] -= speed;
	  xPos[3] -= speed;
	}
	  
	  
	  glutTimerFunc(1000 / 144, timer, 0);
}

void block(float pilarPosX, float pilarPosY)
{
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_QUADS);
  
  //pilar atas
  glVertex2f(pilarPosX - 5, pilarPosY);
  glVertex2f(pilarPosX - 5, 100.0);
  glVertex2f(pilarPosX, 100.0);
  glVertex2f(pilarPosX, pilarPosY);

  //pilar bawah
  glVertex2f(pilarPosX - 5, pilarPosY - spaceP);
  glVertex2f(pilarPosX - 5, -100.0);
  glVertex2f(pilarPosX, -100.0);
  glVertex2f(pilarPosX, pilarPosY - spaceP);
  glEnd();
}

void showScore()
{
  char text[50] = "Your Score: ";
  char _score[100];
  itoa(score, _score, 10);
  strcat(text, _score);
  glColor3f(1.0, 1.0, 1.0);
  drawBitmapText((char *)text, -99, 95, 0);
}
