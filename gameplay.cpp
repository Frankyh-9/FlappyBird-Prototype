#include <iostream>

#include "player.h"
#include "layout.h"
#include "gameplay.h"

int score = 0;

bool gameChecker(){
	if (value != 0){
		//tinggi atau rendah
		if (playerPosY+4 >= 100 || playerPosY-4 <= -96) {
			value = 0;
			return false;
		}
		
		//pilar atas atau bawah
		for (int i = 0; i < 4; i++){
			if ( (playerPosX+4 >= xPos[i] - 4 && playerPosX+4 <= xPos[i] + 5) &&  (playerPosY+4 >= yPos[i] || playerPosY-4 <= yPos[i]-spaceP-1) ) {
				delay(2);
				value = 0;
				return false;
			}
		}
	}
	
	for (int i = 0; i < 4; i++){
		if ( (playerPosX-4 == xPos[i] + 5) ) score++;
	}
	
	return true;	
}
