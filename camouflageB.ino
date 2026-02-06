
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPL3GxwsczJW"
#define BLYNK_TEMPLATE_NAME "Camouflage"
#define BLYNK_AUTH_TOKEN "qVXDxxvyJ0nOGcPn36dHEHNLWEMtvdTD"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Airel_9008001602";
char pass[] = "air21028";

const int m1[] = {D1, D2};
const int m2[] = {D3, D4};
void setup()
{
  // Debug console
  Serial.begin(9600);
  for (int i = 0; i < 2; i++) {
    pinMode(m1[i], OUTPUT);
    pinMode(m2[i], OUTPUT);
  }
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  if (Serial.available()) {
    //Serial.write(Serial.read());
    String myString = Serial.readStringUntil('\n');
    String t = getValue(myString, ',', 0);
    String ostat = getValue(myString, ',', 1);
    String gstat = getValue(myString, ',', 3);
    String mstat =  getValue(myString, ',', 2);
    Blynk.virtualWrite(V1, t);
    //Blynk.virtualWrite(V0, p);
    Blynk.virtualWrite(V5, ostat);
    Blynk.virtualWrite(V7, gstat);
    Blynk.virtualWrite(V8, mstat);
  }
}

BLYNK_WRITE(V11) {
  int val = param.asInt();
  if (val) {
    Blynk.virtualWrite(V15, "Forward");
    digitalWrite(m1[0], HIGH);
    digitalWrite(m2[0], HIGH);
  }
  else {
    Blynk.virtualWrite(V15, ".......");
    digitalWrite(m1[0], LOW);
    digitalWrite(m2[0], LOW);
  }
}



BLYNK_WRITE(V12) {
  int val = param.asInt();
  if (val) {
    Blynk.virtualWrite(V15, "Backward");
    digitalWrite(m1[1], HIGH);
    digitalWrite(m2[1], HIGH);
  }
  else {
    Blynk.virtualWrite(V15, ".......");
    digitalWrite(m1[1], LOW);
    digitalWrite(m2[1], LOW);
  }
}

BLYNK_WRITE(V13) {
  int val = param.asInt();
  if (val) {
    Blynk.virtualWrite(V15, "Right");
    digitalWrite(m1[1], HIGH);
    digitalWrite(m2[0], HIGH);
  }
  else {
    Blynk.virtualWrite(V15, ".......");
    digitalWrite(m1[1], LOW);
    digitalWrite(m2[0], LOW);
  }
}

BLYNK_WRITE(V14) {
  int val = param.asInt();
  if (val) {
    Blynk.virtualWrite(V15, "Left");
    digitalWrite(m1[0], HIGH);
    digitalWrite(m2[1], HIGH);
  }
  else {
    Blynk.virtualWrite(V15, ".......");
    digitalWrite(m1[0], LOW);
    digitalWrite(m2[1], LOW);
  }
}


String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}