#pragma once

bool isActivated(int &mot){
	if(mot < -10 || mot > 10)
		return true;
	return false;
}

task checkClaw(){
	while(true){
		if(vexRT[Btn6U] == 1){
			motor[clawMot] = 64;

			} else if (vexRT[Btn6D] == 1) {
			motor[clawMot] = -127;

			} else {
			motor[clawMot] = 0;
		}
	}
}

task checkArm(){
	while(true){
		if(vexRT[Btn5U] == 1){
			motor[armMot] = 127;

			} else if (vexRT[Btn5D] == 1) {
			motor[armMot] = -127;

			} else {
			motor[armMot] = 0;

		}
	}
}

void checkMoveX(const int &x){
	motor[LMot] = x;
	motor[RMot] = -x;
}

void checkMoveY(const int &y){
	if(y != 0){
		motor[LMot] = y;
		motor[RMot] = y;
	}
}

void checkBoth(const int &x, const int &y){
	if(y != 0){
		motor[LMot]  = (y + x)/2;  // (y + x)/2
		motor[RMot] = (y - x)/2;  // (y - x)/2
	}
}

void checkMove(){
	int x = vexRT[Ch1];
	int y = -vexRT[Ch3];

	if(vexRT[Btn7D] == 1 || vexRT[Btn8D] == 1){
		x /= 2;
		y /= 2;
	}

	if(!isActivated(x)){ //If not turning, move full speed!
		checkMoveY(y);
		} else if(!isActivated(y)) { //If not moving, turn full speed!
		checkMoveX(x);
		} else { // if both
		checkBoth(x, y);
	}
}

/*
void reset(){
	motor[LMot] = 0;
	motor[RMot] = 0;
	motor[clawMot] = 0;
	motor[armMot] = 0;
}
*/
