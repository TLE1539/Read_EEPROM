#include <EEPROM.h>

int c_addr = 0;
bool led_state = false;

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  if(digitalRead(3) && c_addr <= 1015){
    
    // Change status LEDs to "reading" mode
    led_state = ((c_addr/25)%2 == 0) ? true : false; // blink timing
    digitalWrite(7, led_state);
    digitalWrite(12, LOW);
    
    // Print EEPROM data to Serial to be read by the Serial Plotter
    Serial.print(EEPROM.read(c_addr)); // ax
    Serial.print(" ");
    Serial.print(EEPROM.read(c_addr + 1)); // gx
    Serial.print(" ");
    Serial.print(EEPROM.read(c_addr + 2)); // Temperature
    Serial.print(" ");
    Serial.print(EEPROM.read(c_addr + 3)); // Pressure
    Serial.print(" ");
    Serial.print(EEPROM.read(c_addr + 4)); // Altitude
    Serial.println();

    c_addr += 5;
  }
  else{
    // Change status LEDs to "idle" mode
    digitalWrite(7, LOW);
    digitalWrite(12, HIGH);
  }
  
  delay(50);
}
