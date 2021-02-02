#include <Arduino.h>
#include <LiquidCrystal.h>                // Die Bibliothek für deinen Display
#include <wire.h>
#include "DHT.h"
#define DHTPIN 13          // Hier die Pin Nummer eintragen wo der Sensor angeschlossen ist
#define DHTTYPE DHT11     // Hier wird definiert was für ein Sensor ausgelesen wird. In 

// DHT begin
DHT dht(DHTPIN, DHTTYPE);
// DHT end

// HC-SR04 begin
int trigger=8;                               // set Trigger Pin
int echo=9;                                  // set Echo Pin
long dauer=0;                                // return time Ultraschallwelle
long entfernung=0;                           // distance
// HC-SR04 end

int RS = 11;                              //
int E = 12;                               //
int D4 = 2;                               //
int D5 = 3;                               //
int D6 = 4;                               //Variablen für die Arduino Pins
int D7 = 5;                               //
int Spalte = 16;                          //
int Zeile = 2;                            //

LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // Hier wird das Objekt lcd vom Typ 
                                          // LiquidCrystal erzeugt

void setup() {
  // DHT begin
  dht.begin();
  // DHT end

  // HC-SR04 begin
  pinMode(trigger, OUTPUT);                // Trigger Pin als Ausgang definieren
  pinMode(echo, INPUT);                    // Echo Pin als Eingang defnieren
  // HC-SR04 end
  

   lcd.begin(Spalte,Zeile);               // Leg die LCD mit 16 Spalten und 2 Zeilen fest

   lcd.print("DHT11 & HC-SR04 Testprogramm");            // Der Text für die erste Zeile

   
   lcd.setCursor(0,1);                    // Springe in die nächste Zeile

   lcd.print("  ");           // Schreibe den Text in die zweite Zeile
   
 

}

 

void loop() {

  lcd.clear();

  digitalWrite(trigger, LOW);              // set Trigger to LOW -> static minimization 
  delay(5);                                // give it time (millisek) 
  digitalWrite(trigger, HIGH);             // set Trigger to HIGH to send Ultraschallwelle
  delay(10);                               // give it time (millisek)
  digitalWrite(trigger, LOW);              // set Trigger to LOW to finish measurement
  dauer = pulseIn(echo, HIGH);             // taking return time of Ultraschallwelle
  entfernung = (dauer/2) / 29.1;           // conversion to Zentimeter
  delay(10000);                     // wait time for both measurements
  float h = dht.readHumidity();    // read Luftfeuchtigkeit in h
  float t = dht.readTemperature(); // read Temperatur in t


  if (isnan(h) || isnan(t)) {   //( Überprüfen ob alles richtig Ausgelesen wurde ) 
    Serial.println("Fehler beim auslesen des Sensors!");
    return;
  }

  // print to lcd
  lcd.begin(Spalte,Zeile);
  lcd.print("DHT11 & HC-SR04 Testprogramm");  
  lcd.clear();
  delay(2000);

  lcd.begin(Spalte,Zeile);               // Leg die LCD mit 16 Spalten und 2 Zeilen fest
   lcd.print("Ultraschallmessung:"); 
   lcd.setCursor(0,1); 
  lcd.print(entfernung);            // Den Weg in Zentimeter ausgeben
  lcd.println(" cm"); 
  delay(2000);
  lcd.clear(); 

  lcd.begin(Spalte,Zeile);
  lcd.print("Luftfeuchtigkeit: ");
  lcd.print(h);  
  delay(2000);
  lcd.clear();                // Ausgeben der Luftfeuchtigkeit
  
  lcd.print("Temperatur: ");
  lcd.print(t);                  // Ausgeben der Temperatur
  lcd.write("°");                // Schreiben des ° Zeichen
  lcd.println("C");

 

}