#include <BetterServo.h>

#define SERVOS 2   // het aantal servos dat je gebruikt

int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen

BetterServo vingers[SERVOS];

int s[2] = {150, 100};
int e[2] = {30, 70};

void setup() { 
	Serial.begin(9600);
	for(int x = 0; x < SERVOS; x++){
		vingers[x].setLimits(MINTURN, MAXTURN);
		vingers[x].attach(pin[x]);
		vingers[x].turn(MINTURN);
	}
}

void loop() {
	BetterServo::turnAsOne(vingers, s, 2);
	BetterServo::turnAsOne(vingers, e, 2); 
}