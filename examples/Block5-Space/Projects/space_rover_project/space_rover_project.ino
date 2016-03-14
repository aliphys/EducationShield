#include <EducationShield.h>

BLEuart uart=BLEuart(TYPE_LOGOROBOT);

Wheels wheels=Wheels(6, 9);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  uart.setName("LogoRobot");
  uart.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(uart.searchCentral()){
    Serial.println("Connected to central ");
    while(uart.connected()){
      if(uart.dataReceived()){
        uart.fetchData();
        
        Serial.print("Received number of commands: ");
        Serial.println(uart.getReceivedLength());
        
        for(int i=0;i<uart.getReceivedLength();i++){
          unsigned char n=uart.getValueAt(i);
          
          Serial.print(n);
          
          logoMove(n);
        }
        Serial.println();
      }
    }
    Serial.println(F("Disconnected from central "));

  }
}

void logoMove(unsigned char direction){
  switch(direction){
    case 1:	
      wheels.goForward();
      delay(3000);
      break;
    case 2:	
      wheels.goBackwards();
      delay(3000);
      break;
    case 3:	
      wheels.turnLeft();
      delay(1500);
      break;
    case 4:	
      wheels.turnRight();
      delay(1500);
      break;
  }
  wheels.standStill();
  delay(300);
}

