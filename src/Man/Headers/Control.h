#pragma once
#define aThreshold 5
#define rotationTime 2077
#define maxPow 127

void reset() {
	motor[LMot] = 0;
	motor[RMot] = 0;
	motor[clawMot] = 0;
	motor[armMotA] = 0;
	motor[armMotB] = 0;
}

int sonarValue(){	//Returns sonar in cm
	return(SensorValue(sonar));
}

//For moving the robot
void move(int lPower, int rPower, int msTime){
	motor[LMot] = lPower;
	motor[RMot] = rPower;

	wait1Msec(msTime);

	motor[LMot] = 0;
	motor[RMot] = 0;
}

void move(int power, int msTime){
	move(power, power, msTime);
}

void turn(char dir, int degree){
	if(dir == 'l' || dir == 'L') //l = left
		move(-maxPow, maxPow, (int)((rotationTime * degree / 360) + .5));
	else	//else, go right
		move(maxPow, -maxPow, (int)((rotationTime * degree / 360) + .5));
}

task raiseArm(){
	motor[armMotA] = 127;
	motor[armMotB] = 127;

	wait10Msec(100);

	motor[armMotA] = 0;
	motor[armMotB] = 0;
	stopTask(raiseArm);
}

int findCone(){
	startTask(raiseArm);
	while(true){
		motor[LMot] = -maxPow;
		motor[RMot] = maxPow;
		if(sonarValue() > 0){
			wait10Msec(14);
			reset();					//14
			while(sonarValue() > 14){
				move(maxPow, 1);
			}
			reset();
			return 1;
		}
	}

}

//Manual Code------------------------------------------------------

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
			motor[armMotA] = 127;
			motor[armMotB] = 127;
			} else if (vexRT[Btn5D] == 1) {
			motor[armMotA] = -127;
			motor[armMotB] = -127;
			} else {
			motor[armMotA] = 15;
			motor[armMotB] = 0;
		}
	}
}

task checkBMot(){
	while(true) {
		if(vexRT[Btn7U] == 1) {
			motor[BMot] = 127;
			} else if (vexRT[Btn7D] == 1) {
			motor[BMot] = -127;
			} else {
			motor[BMot] = 0;
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

task checkMove() {
	while(true) {
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
	}
} //Vars are deleted by end of scope
