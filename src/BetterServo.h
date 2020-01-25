#ifndef BetterServo_H
#define BetterServo_H

#include <Servo.h>

#include "Arduino.h"

#ifndef SERVOS
#define SERVOS 5
#endif

struct Position{
	int positions[SERVOS];
	int amount;
	Position(){
		amount = SERVOS;
	}
};


class BetterServo : private Servo
{
protected:
	int _minPos, _maxPos;
	
public:

	/// Initialize the servo
	BetterServo() : _minPos(0), _maxPos(180){}

	/// Functions from the original Servo library
	using Servo::attach;
	using Servo::attached;
	using Servo::detach;

	/// Turn the servo to position <deg> and wait <wait> ms (default: 500)
	void turn(int deg, int wait = 500);


	/// Get the minimum and maximum that the servo can turn, set by setLimits()
	int getMin();
	int getMax();	

	/// Get the current position of the servo
	int getPosition();

	/// Set the limits of the servo
	int setLimits(int min, int max);
};


/// Turn <amount> servos in the list <servos> to their respective position in <endPositions> position and will then wait <wait> ms (default: 1500)
void turnAsOne(BetterServo *servos, int endPositions[], int amount, int wait = 1000);

/// Turn <amount> servos in the list <servos> to their respective position in <endPositions> position and will then wait <wait> ms (default: 1500)
//void turnAsOneA(BetterServo *servos, Position *endPositions, int wait = 1000);

#endif
