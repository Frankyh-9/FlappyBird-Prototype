#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>

#include "layout.h"
#include "player.h"
#include "gameplay.h"

void resetGame(){
	xPos[0] = 50.0; xPos[1] = 150.0; xPos[2] = 250.0; xPos[3] = 350.0;
    yPos[0] = 20.0; yPos[1] = 0.0; yPos[2] = 0.0; yPos[3] = 0.0;
    playerPosX = playerPosY = 0.0;
    score = 0;
}

void display(void)
{  	
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (value == 0){
		resetGame();
		homeLayout();
		glColor3f(1.0, 1.0, 1.0);
		drawBitmapText((char*)"Hello!!", -3.0, 0.0, 0.0);
		glutPostRedisplay();
	}
	else if (value == 1){
	  spaceP = 70.0;
	  speed = 0.5;
	  showScore();	
	  if (!gameChecker()){
	  	value == 0;
	  	resetGame();
	  }else{
		  drawPlayer();
		  for (int i = 0; i < 4; i++)
		  {	
		    block(xPos[i], yPos[i]);
		  }
	  }
	}
	else if (value == 2){
	  spaceP = 50.0;
	  speed = 0.5;
	  showScore();	
	  if (!gameChecker()){
	  	value == 0;
	  	resetGame();
	  }else{
	  	drawPlayer();
	  	for (int i = 0; i < 4; i++)
	  	{	
	    	block(xPos[i], yPos[i]);
	  	}	
	  }
	}
	else if (value == 3){
	  spaceP = 35.0;
	  speed = 0.5;
	  showScore();	
	  if (!gameChecker()) {
	  	value == 0;
	  	resetGame();
	  }else{
	  	drawPlayer();
	  	for (int i = 0; i < 4; i++)
	  	{	
	    	block(xPos[i], yPos[i]);
	  	}	
	  }
	}
	glFlush();
  	glPushMatrix();
 	glPopMatrix();
  	glutSwapBuffers();
}

void init(void) //clear graphic device
{
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  //glShadeModel (GL_FLAT);
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

#pragma argsused
void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27: /*  Escape key  */
    exit(0);
    break;
  case 'f':
  case 'F':
    glutFullScreen();
    break;
  case 'w':
    playerPosY += 20;
    break;
    /* break;
  default:
   break;*/
  }
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x >= 732 && x<=809 && y>=428 && y<=451){
		createMenu();	
	}else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x >= 732 && x<=809 && y>=470 && y<=490){
//		delay(2);
		exit(0);
	}else{}
}

int main(int argc, char **argv)
{
  
  glutInit(&argc, argv);                       //Initialize window Title
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //Initial display type 24 bit RGB and double buffer
  glutInitWindowSize(1800, 800);               //Initialize window resolution
  glutCreateWindow(argv[0]);                   //Create an animation window
  init();                                      //clear graphic device
  glutReshapeFunc(reshape);                    //Initialize refresh frame function
  glutKeyboardFunc(keyboard);                  //Initialize keyboard response function
  glutMouseFunc       ( mouse    );    //Initialize mouse response function
//  createMenu();
  glutDisplayFunc(display); //Initialize the animation function
  glutTimerFunc(0, timer, 0);
  glutTimerFunc(0, playerTimer, 0);
  glutMainLoop(); //Looping the animation
  return 0;
}
