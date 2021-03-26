#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>

#include "player.h"
#include "layout.h"

float playerPosX = 0.0, playerPosY = 0.0;

void playerTimer(int)
{
	if (value != 0 && value != 4){
	    glutPostRedisplay();
	    if (playerPosY > -97)
	        playerPosY -= 1;
    }
        
    glutTimerFunc(1000 / 60, playerTimer, 0);
}

void drawPlayer()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(playerPosX - 4, playerPosY + 4);
    glVertex2f(playerPosX - 4, playerPosY - 4);
    glVertex2f(playerPosX + 4, playerPosY - 4);
    glVertex2f(playerPosX + 4, playerPosY);
    glVertex2f(playerPosX + 1, playerPosY + 4);
    glEnd();
}
