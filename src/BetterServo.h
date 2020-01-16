#ifndef BetterServo_H
#define BetterServo_H

#include <Servo.h>

#include "Arduino.h"

class BetterServo : private Servo
{
private:
	int position = 0;

	int minPos, maxPos;
	
	void turnFor(int deg, int step = 1);
	void turnBack(int deg, int step = 1);

public:

	BetterServo() : minPos(0), maxPos(150){}
	BetterServo(int min, int max) : minPos(min), maxPos(max){}

	using Servo::attach;

	void turn(int deg, int step = 1);

	int getMin();
	int getMax();	

	int setLimits(int min, int max);
};

#endif
