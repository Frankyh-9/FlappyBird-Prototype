#pragma once

extern float xPos[4], yPos[6];

extern int currentBlock;

extern int value;

extern float speed;

extern float spaceP;


void delay(float secs);
void createMenu(void);
void drawBitmapText(char *string, float xa, float yb, float zc);
void timer(int);
void block(float pilarPosX, float pilarPosY);
void showScore();
void homeLayout();
