#pragma once

#define aThreshold 5

bool isActivated(int &mot) {
	if(mot < -aThreshold || mot > aThreshold)
		return true;
	return false;
}

task checkClaw() {
	while(true) {
		if(vexRT[Btn6U] == 1) {
			motor[clawMot] = 127;
			} else if (vexRT[Btn6D] == 1) {
			motor[clawMot] = -127;
			} else {
			motor[clawMot] = 0;
		}
	}
}

task checkArm() {
	while(true) {
		if(vexRT[Btn5U] == 1) {
			motor[armMot] = 127;
			} else if (vexRT[Btn5D] == 1) {
			motor[armMot] = -127;
			} else {
			motor[armMot] = 15;
		}
	}
}

void checkMoveX(const int &x) {
	motor[LMot] = x;
	motor[RMot] = -x;
}

void checkMoveY(const int &y) {
	motor[LMot] = y;
	motor[RMot] = y;
}

void checkXY(const int &x, const int &y) {
	motor[LMot]  = (y + x) / 2;
	motor[RMot] = (y - x) / 2;
}

void checkMove() {
	//Set Vars
	int x = vexRT[Ch1];
	int y = -vexRT[Ch3];

	if(vexRT[Btn7D] == 1 || vexRT[Btn8D] == 1) {
		x /= 2;
		y /= 2;
	}

	if(isActivated(y)){// y + both required y != 0

		if(!isActivated(x)) {checkMoveY(y);
		}	else {checkXY(x, y);}

	} else {checkMoveX(x);}

} //Vars are deleted by end of scope


/*
void reset() {
motor[LMot] = 0;
motor[RMot] = 0;
motor[clawMot] = 0;
motor[armMot] = 0;
}
*/
