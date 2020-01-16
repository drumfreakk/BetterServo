#ifndef BetterServo_H
#define BetterServo_H

#include <Servo.h>

#include "Arduino.h"

class BetterServo : private Servo
{
protected:
	int _position = 0;
	int _minPos, _maxPos;
	
	void _turnFor(int deg, int step = 1, int wait = 15);
	void _turnBack(int deg, int step = 1, int wait = 15);
	
public:

	BetterServo() : _minPos(0), _maxPos(150){}
	BetterServo(int min, int max) : _minPos(min), _maxPos(max){}

	using Servo::attach;

	void turn(int deg, int step = 1, int wait = 15);

	int getMin();
	int getMax();	

	int getPosition();

	int setLimits(int min, int max);
};

void turnAsOne(BetterServo *servos, int amount, int deg, int step = 1);

#endif
