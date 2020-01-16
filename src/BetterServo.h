#ifndef BetterServo_H
#define BetterServo_H

#include <Servo.h>

#include "Arduino.h"

class BetterServo : private Servo
{
protected:
	int _position = 0;
	int _minPos, _maxPos;
	
	/// Turn the servo forwards or backwards to position <deg>, with a step size of <step> (default: 1) amd a de;ay between every step of <wait> ms (default: 15)
	void _turnForward(int deg, int step = 1, int wait = 15);
	void _turnBack(int deg, int step = 1, int wait = 15);
	
public:

	/// Initialize the servo
	BetterServo() : _minPos(0), _maxPos(180){}

	/// Functions from the original Servo library
	using Servo::attach;
	using Servo::attached;
	using Servo::detach;

	/// Turn the servo to position <deg>, with a step size of <step> (default: 1) and a delay between every step of <wait> ms (default: 15)
	void turn(int deg, int step = 1, int wait = 15);


	/// Get the minimum and maximum that the servo can turn, set by setLimits()
	int getMin();
	int getMax();	

	/// Get the current position of the servo
	int getPosition();

	/// Set the limits of the servo
	int setLimits(int min, int max);
};

/// Turn <amount> servos in the list <servos> from the same start to end (<deg>) position with an optional step size <step> (default: 1)
void turnAsOne(BetterServo *servos, int amount, int deg, int step = 1);

#endif
