#include <LiquidCrystal.h>                // Die Bibliothek für deinen Display

 

int RS = 12;                              //

int E = 11;                               //

int D4 = 5;                               //

int D5 = 4;                               //

int D6 = 3;                               //Variablen für die Arduino Pins

int D7 = 2;                               //

int Spalte = 16;                          //

int Zeile = 2;                            //

 

LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // Hier wird das Objekt lcd vom Typ 

                                          // LiquidCrystal erzeugt

 

void setup() {

  

   lcd.begin(Spalte,Zeile);               // Leg die LCD mit 16 Spalten und 2 Zeilen fest

   lcd.print(" Viel Spass mit ");         // Der Text für die erste Zeile

   lcd.setCursor(0,1);                    // Springe in die nächste Zeile

   lcd.print("  Mymakerstuff");           // Schreibe den Text in die zweite Zeile

 

}

 

void loop() {

 

   // Deine loop- Methode bleibt leer.

 

}