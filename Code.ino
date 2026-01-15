#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define IR_SENSOR D2

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  pinMode(IR_SENSOR, INPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  int motion = digitalRead(IR_SENSOR);

  if (motion == HIGH) {
    Blynk.logEvent("theft_alert", "🚨 Motion Detected! Possible Theft");
    delay(3000);  // prevent repeated notifications
  }
}
