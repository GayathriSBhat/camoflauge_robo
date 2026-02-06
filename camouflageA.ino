#define MQ2pin 7
float sensorValue;
float t;
int tempPin = A1;
int obstaclePin = 2;
int hasObstacle = LOW;
String ostat;
String mstat;
String gstat;
int pirPin1 = 4;
int pirStat1 = 0;
int buzzer =5;
String str;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(obstaclePin, INPUT);
  pinMode(pirPin1, INPUT);
  pinMode(MQ2pin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
get_temperature();
  obstacle_status();
  pir_status();
  gas_status();
  str = String(t) + ","  + String(ostat) + "," + String(mstat) + "," + String(gstat);
  Serial.println(str);
  delay(1000);
}

void get_temperature() {
  t = analogRead(tempPin);
  t = t * 0.48828125;

}

void obstacle_status() {
  hasObstacle = digitalRead(obstaclePin);

  if (hasObstacle == HIGH) {
    ostat = "Stop something is ahead!!";
    digitalWrite(buzzer,HIGH);
    
  }
  else {
    ostat = "Path is clear";
    digitalWrite(buzzer,LOW);
    
    
  }
}

void pir_status() {
  pirStat1 = digitalRead(pirPin1);
  if (pirStat1 == 1) {            // if motion detected
    mstat = "Motion Detected";
  }
  else {
    mstat = "No Motion";
  }
}

void gas_status() {
  sensorValue = digitalRead(MQ2pin); // read analog input pin 0
  if (sensorValue == LOW)
  {
    gstat = "GAS Detected!!!!";
  }
  else {

    gstat = "---------------";
  }
}