   //////////////////////////////////////////////
  //        HALL EFFECT SENSOR DEMO           //
 //          Author: Nick Koumaris           //
//           http://www.educ8s.tv           //
/////////////////////////////////////////////
int hallSensorPin = 13;     
int ledPin =  8;    
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(hallSensorPin, INPUT);     
}

void loop(){
  
  state = digitalRead(hallSensorPin);
  if (state == LOW) {        
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
}
