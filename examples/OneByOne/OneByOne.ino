#include <BetterServo.h>

#define MAXTURN 150  // het max aantal graden dat het draait, dit is ongeveer het max met deze servos
#define MINTURN 30    // het min aantal graden dat het draait, dit is ongeveer het max met deze servos

#define SERVOS 2   // het aantal servos dat je gebruikt

int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen

BetterServo vingers[SERVOS];

void setup() { 
	Serial.begin(9600);
	for(int x = 0; x < SERVOS; x++){
		vingers[x].setLimits(MINTURN, MAXTURN);
		vingers[x].attach(pin[x]);
		vingers[x].turn(MINTURN);
	}
}

void loop() {
	for(BetterServo &toTurn : vingers){ 
		toTurn.turn(toTurn.getMax());
		toTurn.turn(toTurn.getMin());
	}
}