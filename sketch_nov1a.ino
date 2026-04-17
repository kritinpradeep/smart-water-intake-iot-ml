#define BUZZER_PIN D5

float waterLevel = 10.0;     // Full bottle at start
float lastWaterLevel = 10.0;
unsigned long startTime = 0;
unsigned long lastChangeTime = 0;
bool hasDrunk = false;
bool reminderDone = false;   
bool secondDrinkDone = false;

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.println("Smart Water Intake Reminder (Controlled Demo)");
  startTime = millis();
  lastChangeTime = millis();
}

void loop() {
  unsigned long now = millis();
  unsigned long elapsed = (now - startTime) / 1000; 

  // After second drink → lock water level at 5 cm (or your final level)
  if (secondDrinkDone) {
    waterLevel = 5.0;
  }
  else {

    // Initial full bottle
    if (elapsed < 20) {
      waterLevel = 10.0;
    }
    
    // First drink event
    else if (elapsed >= 20 && !hasDrunk) {
      waterLevel = 7.0;
      hasDrunk = true;
      Serial.println("User drank water 💧");
      lastWaterLevel = waterLevel;
      lastChangeTime = now;
    }
    
    // After first drink → water stays at 7 cm for demo
    else {
      waterLevel = 7.0;
    }
  }

  // Print reading
  Serial.print("Water Level: ");
  Serial.print(waterLevel, 2);
  Serial.println(" cm");

  // Reminder only once
  if (!reminderDone && (now - lastChangeTime > 30000)) {
    Serial.println("⚠️ Reminder: You haven’t drunk water for a while!");

    // Beep exactly 10 times
    for (int i = 0; i < 10; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(500);
      digitalWrite(BUZZER_PIN, LOW);
      delay(500);
    }

    // Simulate second drink
    waterLevel = 5.0;
    secondDrinkDone = true;
    Serial.println("User drank again 💧 (Water Level dropped to 5 cm)");

    lastWaterLevel = waterLevel;
    lastChangeTime = millis();
    reminderDone = true;
  }

  delay(1000);
}
