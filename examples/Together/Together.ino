#include <BetterServo.h>

#define SERVOS 2   // het aantal servos dat je gebruikt

int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen

BetterServo vingers[SERVOS];

int s[2] = {50, 50};
int e[2] = {120, 120};

void setup() { 
	Serial.begin(9600);
	for(int x = 0; x < SERVOS; x++){
		vingers[x].setLimits(0, 150);
		vingers[x].attach(pin[x]);
		vingers[x].turn(0);
	}
}

void loop() {    
	turnAsOne(vingers, s, 2, 2000);
	turnAsOne(vingers, e, 2, 2000); 
}
