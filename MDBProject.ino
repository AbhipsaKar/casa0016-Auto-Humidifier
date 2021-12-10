#include <DHT.h>

#define motorPin 3 //Digital pin to drive the DC motor
#define humiPin 4 //Digital pin to measure humidity
#define pirPin 2  //Digital pin to detect PIR
#define waterChgPin 7  //Analog pin to detect moisture
#define DHTPIN 6  //Digital Pin 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

uint8_t waterPin = 0; //Analog Sensor for water level detection
int prevDistance =0;
long distInterval = 20000;  //Interval between 2 PIR reading check
long moistureChkInterval = 10000; //Interval between 2 water level readings
long prevTime =0;
long currTime =0;
bool detectChg =false; //State to remember the presence detected in the last interval

void setup() {
  
  Serial.begin(115200);
  pinMode(pirPin, INPUT); 
  pinMode(humiPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(waterChgPin, OUTPUT);
  //Initialise the DHT sensor
  dht.begin();
}

void loop() {

  delay(1000);
  currTime = millis();
  float humidity = dht.readHumidity(false); //Take the humidity readings
  Serial.println("Reading humidity");
  Serial.println(humidity);
  if((currTime - prevTime) > distInterval)
  {
    int moisture = analogRead(waterPin); //Take the moisture readings
    Serial.println("Moisture is ");
    Serial.println(moisture);
    if(moisture <200)
    {
      digitalWrite(waterChgPin, HIGH); //Water refill alert on
    }
    else
    {
      digitalWrite(waterChgPin, LOW); //Water refill alert off
    }
  }
  if (digitalRead(pirPin) == HIGH) //Check reading from PIR sensor in every cycle
    {
      Serial.println("Presence detected");
      detectChg = true; //Presence detected
    }
  if((currTime - prevTime) > distInterval && detectChg == true && humidity < 45 ){ //Start fan and humidifier after elapsed time if presence has been detected
      Serial.println("Humidifier on");
      digitalWrite(humiPin, HIGH);
      
      Serial.println("Motor on");
      digitalWrite(motorPin, HIGH);
      delay(8000);
      digitalWrite(motorPin, LOW);
      Serial.println("Motor off");
      digitalWrite(humiPin, LOW);
      Serial.println("Humidifier off");
      detectChg = false;  //reset presence detected
      prevTime = currTime;
      
  }
}
