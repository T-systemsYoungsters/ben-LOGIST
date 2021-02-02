#include <LiquidCrystal.h>                // Die Bibliothek für deinen Display
#include <wire.h>

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

  

   lcd.begin(Spalte,Zeile);               // Leg die LCD mit 16 Spalten und 2 Zeilen fest

   lcd.print(" $GME GO BRRRR ");            // Der Text für die erste Zeile

   
   lcd.setCursor(0,1);                    // Springe in die nächste Zeile

   lcd.print("  Back to Ape!");           // Schreibe den Text in die zweite Zeile
   
 

}

 

void loop() {

 

   // Deine loop- Methode bleibt leer.

 

}