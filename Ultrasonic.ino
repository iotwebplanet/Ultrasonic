// ---------------------------------------------------------------------------
//  How to find distance using HC-SR04 and I2C LCD
// ---------------------------------------------------------------------------
#include <LiquidCrystal_I2C.h>

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.



// Set the LCD address to 0x27 for a 16 chars and 2 line display 0x3F
//UNO SDA PIN to LCD SDA
//UNO SDA PIN to LCD SDA
//UNO GND GND to LCD GND
//UNO 5v PIN to LCD VCC

LiquidCrystal_I2C lcd(0x3F, 16, 2);

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
float distance=0.0;
void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
// initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
 // lcd.print("Hi! IoTwebplanet.com");
// lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print("HC-SR04 Demo");
   lcd.setCursor ( 0, 1 ); 
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
     

  distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
     lcd.setCursor ( 0, 1 ); 
      lcd.print("Out of range/close ");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    lcd.setCursor ( 0, 1 ); 
    lcd.print("Dist:(cm):");
    lcd.setCursor ( 10, 1 ); 
    lcd.print(distance);
    delay(500);
    
  }
  delay(500);
  //lcd.clear();
  


}
