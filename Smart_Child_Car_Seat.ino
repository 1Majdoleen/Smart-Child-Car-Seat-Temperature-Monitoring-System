// C++ code
//
const int tempPin = A0;

const int blueLED = 2;
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;

const int motorPin = 6;



void setup(){
 Serial.begin(9600); 
  
 pinMode(blueLED, OUTPUT);
 pinMode(greenLED, OUTPUT);
 pinMode(yellowLED, OUTPUT);
 pinMode(redLED, OUTPUT);
 
 pinMode(motorPin, OUTPUT);

  
}
void loop(){  
 int sensorValue = analogRead(tempPin);
  
 float voltage = sensorValue*(5.0/1023.0);
  
 float temperature = (voltage-0.5)*100;
  
 Serial.print("Temperature:"); 
 Serial.print(temperature,2);
 Serial.println("C"); 

 if (temperature < 19){
   setLED(blueLED);
   digitalWrite(motorPin, LOW);
 }
 else if(temperature < 25){
   setLED(greenLED);
    digitalWrite(motorPin, LOW);

 }
  else if(temperature <30){
    setLED(yellowLED);  
    digitalWrite(motorPin, LOW);
  }
  else{
    setLED(redLED);
    digitalWrite(motorPin, HIGH);
 
  }
}

void setLED(int activeLED){
digitalWrite(blueLED, LOW);
digitalWrite(greenLED, LOW); 
digitalWrite(yellowLED, LOW);
digitalWrite(redLED, LOW);
  
digitalWrite(activeLED, HIGH);
}
