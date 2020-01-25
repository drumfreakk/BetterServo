#include "BetterServo.h"

void BetterServo::turn(int deg, int wait){
	BetterServo::Servo::write(deg);
	delay(wait);
}

int BetterServo::getMin(){
	return BetterServo::_minPos;
}
int BetterServo::getMax(){
	return BetterServo::_maxPos;
}

int BetterServo::setLimits(int min, int max){
	BetterServo::_minPos = min;
	BetterServo::_maxPos = max;
}

int BetterServo::getPosition(){
	return Servo::read();
}


void turnAsOne(BetterServo *servos, int endPositions[], int amount, int wait){
	for(int i = 0; i < amount; i++){
		servos[i].turn(endPositions[i], 0);
	}
	delay(wait);
}

