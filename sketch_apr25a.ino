#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

String lcdCode ;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address and dimensions
const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
uint8_t colPins[COLS] = { 9, 8, 7, 5 }; // Pins connected to C1, C2, C3, C4
uint8_t rowPins[ROWS] = { 13, 12, 11, 10 }; // Pins connected to R1, R2, R3, R4
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String enteredCode = ""; // String to store the entered code
bool isCodeAvailable = false;

const int pinLED1 = A0; // Numéro de broche pour la première LED


void setup() {
  Serial.begin(9600);
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0, 0); // Set the cursor to the top-left corner
  lcd.print("En attente"); // Display "Indisponible" by default
  pinMode(pinLED1, OUTPUT); // Configure la broche de la première LED en sortie
  
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    if (key == 'D') {
      lcdCode = enteredCode; // Enregistrer le code entré
      lcd.clear(); // Effacer l'affichage LCD
      lcd.print("Envoi..."); // Afficher "Envoi..." pendant l'envoi
      delay(500); // Délai pour la stabilité
      Serial.println(enteredCode); // Envoyer le code entré via le port série
      enteredCode = ""; // Réinitialiser le code entré
      isCodeAvailable = false; // Réinitialiser le drapeau de disponibilité du code
    } else {
      // Ajouter la touche pressée au code entré
      enteredCode += key;
      lcd.setCursor(0, 1); // Positionner le curseur à la deuxième ligne
      lcd.print(enteredCode); // Afficher le code entré
    }
  }

  // Vérifier s'il y a des données disponibles depuis le port série
  while (Serial.available() > 0) {
    char data = Serial.read(); // Lire les données entrantes depuis le port série
    if (data == '1') {
      lcd.clear(); // Effacer l'affichage LCD
      lcd.print("Disponible");
      lcd.print(lcdCode);
      //delay(2000);
      /*lcd.clear();
      lcd.print("indisponible");*/
      // Afficher "Disponible" si le code est disponible
      digitalWrite(pinLED1, HIGH); // Allume la première LED
  
  delay(1000); // Attend 1 seconde (1000 millisecondes)
  digitalWrite(pinLED1, LOW); // Éteint la première LED
  
    }
    else if (data == '0') {
      lcd.clear();
      lcd.print("faux code");
      delay(1000);
      lcd.clear();
      lcd.print("Indisponible"); 
      delay(1000);
      lcd.clear();
      lcd.print("ecrit de nouveau"); 
      delay(1000);
    }
    else if (data == '2') {
      lcd.clear();
      lcd.print("En attente");
    }
  }
}
