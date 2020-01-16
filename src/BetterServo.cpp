#include "BetterServo.h"

void BetterServo::_turnFor(int deg, int step, int wait){
  int &pos = BetterServo::_position;
  
  for (pos; pos <= deg; pos += step) {
    BetterServo::Servo::write(pos);
    delay(15);
  }
}

void BetterServo::_turnBack(int deg, int step, int wait){
  int &pos = BetterServo::_position;

  for (pos; pos >= deg; pos -= step) {
    BetterServo::Servo::write(pos);
    delay(15);
  }
}

void BetterServo::turn(int deg, int step, int wait){
  if(deg > BetterServo::_position){
    BetterServo::_turnFor(deg, step);
  }
  else if(deg < BetterServo::_position){
    BetterServo::_turnBack(deg, step);
  }
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
	return BetterServo::_position;
}

void turnAsOne(BetterServo *servos, int amount, int deg, int step){
	int pos = servos[0].getPosition();
	if(pos <= deg){
		for(int i = pos; i <= deg; i++){
			for(int j = 0; j < amount; j++){
				servos[j].turn(i, 1, 0);
			}
		}
	}
	if(pos >= deg){
		for(int i = pos; i >= deg; i--){
			for(int j = 0; j < amount; j++){
				servos[j].turn(i, 1, 0);
			}
		}
	}
}


