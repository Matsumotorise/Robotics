#pragma once

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

			} else if (vexRT[Btn5D] == 1) {
			motor[armMotA] = -127;

			} else {
			motor[armMotA] = 15;

		}
	}
}

task checkRack(){
		while(true) {
			if(1 == vexRT[Btn7U])
				motor[armMotB] = -127;
			else if ( 1 == vexRT[Btn7D])
				motor[armMotB] = 127;
			else
				motor[armMotB] = 0;
		}
}
void checkMoveL(int x) {
	motor[LMot] = x;
}
task leftMotor(){
	while(true){
			checkMoveL(vexRT[Ch3]);
	}
}

void checkMoveR(int y) {
	motor[RMot] = y;
}


//Vars are deleted by end of scope


/*
void reset() {
motor[LMot] = 0;
motor[RMot] = 0;
motor[clawMot] = 0;
motor[armMot] = 0;
}
*/
