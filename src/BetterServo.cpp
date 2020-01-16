#include "BetterServo.h"

void BetterServo::turnFor(int deg, int step){
  int &pos = BetterServo::position;
  
  for (pos; pos <= deg; pos += step) {
    BetterServo::Servo::write(pos);
    delay(15);
  }
}

void BetterServo::turnBack(int deg, int step){
  int &pos = BetterServo::position;

  for (pos; pos >= deg; pos -= step) {
    BetterServo::Servo::write(pos);
    delay(15);
  }
}

void BetterServo::turn(int deg, int step){
  if(deg > BetterServo::position){
    BetterServo::turnFor(deg, step);
  }
  else if(deg < BetterServo::position){
    BetterServo::turnBack(deg, step);
  }
}

int BetterServo::getMin(){
	return BetterServo::minPos;
}
int BetterServo::getMax(){
	return BetterServo::maxPos;
}

int BetterServo::setLimits(int min, int max){
	BetterServo::minPos = min;
	BetterServo::maxPos = max;
}

