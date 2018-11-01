#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorVal = 0;
int count = 0;

void setup() {
    lcd.begin(16, 2);
    // pinMode(A0, INPUT);
    // for(int i = 170; i<190; i++){
    //     lcd.setCursor(0,0);
    //     lcd.print(i);
    //     lcd.print(" ");
    //     lcd.print((char)i);
    //     delay(1000);
    // }
    Serial.begin(9600);
}

void loop() {
    
    if (count == 9){
        sensorVal = sensorVal / 10;
        Serial.print("SensoreVal: "); Serial.print(sensorVal);
        float voltage = (sensorVal/1024.0) * 5.0;
        Serial.print("      SensorVoltage: "); Serial.print(voltage);
        float temp = (voltage - 0.5) * 100;
        Serial.print("      Temp: " ); Serial.print(temp);
        Serial.println();
        lcd.setCursor(0,0);
        lcd.print("Temp: ");
        
        lcd.print(temp);
        lcd.print(" C");
        lcd.print((char)178);
        sensorVal = analogRead(A0);
        count = 0;
    }
    Serial.print("Sensor: ");
    Serial.println(sensorVal);
    sensorVal = sensorVal + analogRead(A0);
    count++;
    delay(100);
    
    // put your main code here, to run repeatedly:
}