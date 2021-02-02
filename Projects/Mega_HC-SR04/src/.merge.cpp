#include <Arduino.h>
#include "DHT.h"
#define DHTPIN 7          // Hier die Pin Nummer eintragen wo der Sensor angeschlossen ist
#define DHTTYPE DHT11     // Hier wird definiert was für ein Sensor ausgelesen wird. In 

/**( Definieren der Objekte )**/
DHT dht(DHTPIN, DHTTYPE);

// HC-SR04 begin
int trigger=3;                               // set Trigger Pin
int echo=4;                                  // set Echo Pin
long dauer=0;                                // return time Ultraschallwelle
long entfernung=0;                           // distance
// HC-SR04 end

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 & HC-SR04 Testprogramm");
  dht.begin();
// HC-SR04 begin
  pinMode(trigger, OUTPUT);                // Trigger Pin als Ausgang definieren
  pinMode(echo, INPUT);                    // Echo Pin als Eingang defnieren
// HC-SR04 end

}
void loop() {
  digitalWrite(trigger, LOW);              // set Trigger to LOW -> static minimization 
  delay(5);                                // give it time (millisek) 
  digitalWrite(trigger, HIGH);             // set Trigger to HIGH to send Ultraschallwelle
  delay(10);                               // give it time (millisek)
  digitalWrite(trigger, LOW);              // set Trigger to LOW to finish measurement
  dauer = pulseIn(echo, HIGH);             // taking return time of Ultraschallwelle
  entfernung = (dauer/2) / 29.1;           // conversion to Zentimeter
  delay(30000);                     // wait time for both measurements
  float h = dht.readHumidity();    // read Luftfeuchtigkeit in h
  float t = dht.readTemperature(); // read Temperatur in t


  if (isnan(h) || isnan(t)) {   //( Überprüfen ob alles richtig Ausgelesen wurde ) 
    Serial.println("Fehler beim auslesen des Sensors!");
    return;
  }

  // print to Seriellem Monitor
  Serial.print("Ultraschallmessung: ");
  Serial.print(entfernung);            // Den Weg in Zentimeter ausgeben
  Serial.println(" cm"); 

  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(h);                  // Ausgeben der Luftfeuchtigkeit
  Serial.print("%\t");              // Tabulator
  Serial.print("Temperatur: ");
  Serial.print(t);                  // Ausgeben der Temperatur
  Serial.write("°");                // Schreiben des ° Zeichen
  Serial.println("C");
}