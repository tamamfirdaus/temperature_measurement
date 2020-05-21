// Program Tugas Besar Sistem Instrumentasi 
// Kelompok   : D
// Kelas      : K-02 (Pak Pronoto)
// Anggota    : 
//    - Akmal Narendra S.    (13217034)
//    - Fauzan Rozin         (13217040)
//    - Moh. Tamamul Firdaus (13217062)
//    - Athar Fadhlan        (13217090)

// Library
#include <LiquidCrystal_I2C.h>

// Object Declaration
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// Pin Declaration
int pinLM35  = A0;
int ledMerah = 12;
int ledHijau = 10;

// Constant
const float high_temp = 35.0f;
const float low_temp  = 25.0f;

// Variables
float temperature     = 0.0f;
int temperature_data  = 0;
 
void setup(){
  pinMode(ledMerah, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  // initilize serial pc
  Serial.begin(9600);
  // initialize the lcd  
  lcd.init();                      
  lcd.backlight();
  // print a message to the lcd
  lcd.setCursor(0,0);
  lcd.print("Tubes Sisin");
  lcd.setCursor(0,1);
  lcd.print("Sensor LM35");
  delay(2000);
  lcd.clear();
}
 
void loop(){
  // read temperature data
  temperature_data = analogRead(pinLM35);
  // calculate temperature
  temperature = temperature_data / 2.0479;
  // debug using serial
  Serial.print("data sebeleum diolah:\t");
  Serial.print(temperature_data);
  Serial.print("\t data setelah diolah:\t");
  Serial.println(temperature);
  // conditional with led
  if(temperature>=high_temp){
    // high temperature
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);
  }else if(temperature<=low_temp){
    // low temperature
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, HIGH);
  }else{
    // 
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, LOW);
  }
  // display in LCD
  lcd.setCursor(0,0);
  lcd.print("Tubes Sisin");
  lcd.setCursor(00,1);
  lcd.print("Suhu:");
  lcd.setCursor(5,1);
  lcd.print(temperature);
  lcd.setCursor(10,1);
  lcd.print("C");
  delay(1);
}
