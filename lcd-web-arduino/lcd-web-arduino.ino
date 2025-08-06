#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables pour le défilement
unsigned long previousMillis = 0;
const long scrollInterval = 300;  // Intervalle de défilement en ms
int scrollPosition = 0;
String currentMessage = "";
bool needsScrolling = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Waiting...");
  Serial.println("LCD ready...");
}

void loop() {
  // Gestion de la réception des messages
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    message.trim();  // Supprime les espaces et retours chariots
    
    Serial.print("Received: ");
    Serial.println(message);
    
    currentMessage = message;
    needsScrolling = (currentMessage.length() > 16);
    scrollPosition = 0;
    
    updateDisplay();
  }

  // Gestion du défilement si nécessaire
  if (needsScrolling) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= scrollInterval) {
      previousMillis = currentMillis;
      scrollText();
    }
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  
  if (!needsScrolling) {
    // Affiche le message normalement s'il tient sur une ligne
    lcd.print(currentMessage);
  } else {
    // Affiche la partie visible du message
    String visiblePart = currentMessage.substring(scrollPosition, scrollPosition + 16);
    lcd.print(visiblePart);
  }
}

void scrollText() {
  scrollPosition++;
  
  // Si on a atteint la fin du message, revenir au début
  if (scrollPosition > currentMessage.length()) {
    scrollPosition = 0;
    // Petit délai avant de recommencer le défilement
    delay(1000);
  }
  
  updateDisplay();
}