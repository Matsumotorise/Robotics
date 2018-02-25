#pragma once
#define rotationTime 2077

//I'm not sure if our model's maxPower is 127, so
//TODO: Double check and reserach maxPower for our clawBot.
#define maxPow 127

//For moving the robot
void move(int lPower, int rPower, int msTime){

	/*Checking in case an someone goes overboard with a value;
	however, it shouldn't be needed in the final code.*/
	if (lPower > maxPow){
		move(maxPow, rPower, msTime);
		return;
	} else if (rPower > maxPow) {
		move(lPower, maxPow, msTime);
		return;
	} else if (lPower < -maxPow) {
		move(-maxPow, rPower, msTime);
		return;
	} else if (rPower < -maxPow) {
		move(lPower, -maxPow, msTime);
		return;
	}
	////////////overValue check end///////////////

	motor[LMot] = lPower;
	motor[RMot] = rPower;

	wait1Msec(msTime);

	motor[LMot] = 0;
	motor[RMot] = 0;
}

//For simple forward motion.
void move(int power, int msTime){
	move(power, power, msTime);
}

/*///////////////////////////////////////
|rotationTime == time for one rotation on max power. (#defined above)
|Mathematical derivation to find rotationTime using proportions (SAT method):
|			(360 : rotationTime)
|			-------------------
|		 (degree : mSecWanted)
|Thus, mSecWanted = rotationTime * degree / 360.
|_____________________________________________________________
|TODO: Reserach alternatives with sensors for more accurate results.
|			 Though, personally, I don't think we'll need them since it's just 15 seconds.
|TODO: Change rotationTime to what it is in the real world.
|	Hint: rotationTime ~= 360 * timeTested / degreeItTurned.
|			Feed values into the function below until degreeItTurned ~= 360.
|	Hint: Use competition surface, not the school's floor since F(friction) will be different.
///////////////////////////////////////*/
void turn(char dir, int degree){
	if(dir == 'l' || dir == 'L') //l = left
		move(-maxPow, maxPow, (int)((rotationTime * degree / 360) + .5));
	else	//else, go right
		move(maxPow, -maxPow, (int)((rotationTime * degree / 360) + .5));
}



/*
TODO: Implement Claw Motion.

TODO: Implement circular/eliptical motion function for stability, optimization, and flexibility.
	NOTE: I'm think it's implementable with vectors and graphs, but I need data, (and I feel the physics problem agony).
		Or ... Get Mr.Conley, Sam Nall and Garret Smith to derive this ... somehow.
		Maybe it's faster for stationary turns, then forward motion?
*/
