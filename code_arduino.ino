#include "model.h" 
Eloquent::ML:: Port:: Random Forest classifier; 
float features [2]; 
const float slope = (5.00.0) / (1023.00.0); 
int valueRead; 
float Vout; 
float temperatureC; 
float temperatureF; 
const int fan_control_pin = 3; 
int count = 0; 
unsigned long start_time; 
int rpm; 
float rpmP; 
void setup() { 
pinMode(fan_control_pin, OUTPUT); 
analogWrite(fan_control_pin, 0); 
Serial.begin(9600); 
attachInterrupt (digitalPinToInterrupt (2), counter, RISING); 
} 
void loop() { 
readInputValues(); 
String prediction: Class = classifier.predictLabel(features); 
delay(2000); 
Serial.print("Prediction = "); 
Serial.println(predictionClass); 
} 
void counter() { 
count++; 
}
void readInputValues() { 
valueRead = analogRead(A0); 
Vout = valueRead * slope; 
temperatureC = Vout * 100; 
temperatureF = (temperatureC * 9/5) + 32; 
analogWrite(fan_control_pin, 126); 
delay (5000); 
start_time = millis(); 
count = 0; 
while((millis() start_time) < 1000) { 
} 
rpm = count/2; 
rpmP = (rpm 100)/2200; 
rpm=rpm*(1.5); 
Serial.print(temperatureF); 
Serial.print("F, Speed = "); 
Serial.print(rpm); 
Serial.print("%, "); 
features [0] = temperatureF; 
features [1] = rpm; 
Récupérer les valeur de la vitesse et température 
}
