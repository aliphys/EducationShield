#include "EducationShield.h"

CapacitiveSwitch::CapacitiveSwitch(int pin_in,int pin):Button(pin,HIGH),sensor(pin_in,pin){

}

void CapacitiveSwitch::config(int threshold){
	this->threshold=threshold;
}
void CapacitiveSwitch::test(){
	Serial.println(getValue());
}
long CapacitiveSwitch::getValue(int min){
	int val=sensor.capacitiveSensor(30);
	if(val<min)
		val=0;
	return val;
}
bool CapacitiveSwitch::getState(){
	return getValue()>threshold;
}
