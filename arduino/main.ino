
#include "ThingSpeak.h"
#include "secrets.h"
#include "setup.h"
#include <ESP8266WiFi.h>
#include <time.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;
char ssid[] = SECRET_SSID;   
char pass[] = SECRET_PASS;   
int keyIndex = 0;  // your network key index number (needed only for WEP)
float timezone = 6.5 * 3600; //6.5 refers to IST
int dst = 0;

#include "alarms.h"
#include "conf.h"
#include "decrypt.h"

WiFiClient  client;
LiquidCrystal_I2C lcd(0x27,16,2);

int statusCode = 0; 

const int FieldNumber1 = 1;
const int FieldNumber2 = 2;
const int FieldNumber3 = 3;
const int FieldNumber4 = 4;
const int FieldNumber5 = 5;

  void not_taken(){ 
    
  }

void error(){
  
  Serial.println("Unable to read");
  Serial.println("or No internet!");
  lcd.clear();
  lcd.print("Unable to read");
  
}

void data() {}

void setup() {
  
  Serial.begin(115200);
  delay(100);
  
  Wire.begin(D4,D3);
  lcd.begin();
  lcd.backlight();
  lcd.home();
  
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  conf_time();
   
  Serial.println("\nTime response....OK"); 
  
  //compartment 1
  pinMode (5,INPUT);
  pinMode (16,OUTPUT);
  //compartment 2
  pinMode (14,INPUT);
  pinMode (4,OUTPUT);
  //compartment 3
  pinMode (12,INPUT);
  pinMode (13,OUTPUT);
  
  //digitalWrite(16,HIGH);
  //digitalWrite(4,HIGH);
  //digitalWrite(13,HIGH);
}

void loop() {
  int x = 0;
  conf_wifi();
  lcd.clear();
  lcd.print("Welcome To MEDBO");
    //***********************************************************************************************//
    long med_temp1 = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber1, SECRET_READ_APIKEY);
    statusCode = ThingSpeak.getLastReadStatus();

    char buffer [50] ;

    long a = 68738380827378;
    int n = sprintf (buffer, "%lu", a);

    for(int i = 1; i < n; i +=2 ){

        int first = buffer[i-1] - 48;
        int second = buffer[i]- 48;
    
        char asciCode = first*10 + second;
        Serial.print(asciCode);
        lcd.clear();
        lcd.print(asciCode);
    
    }
  
    if (statusCode == 200) {
      Serial.println("Medcine Name1 :");
      Serial.println(med_temp1);
      //lcd.clear()
      //lcd.print(med_temp1);
    }
    
    else {error();}
    
    delay(100);
  //***********************************************************************************************//
    /*long med_temp2 = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber2, SECRET_READ_APIKEY);
    statusCode = ThingSpeak.getLastReadStatus();
  
    if (statusCode == 200) {
      Serial.println("Medcine Name2 :");
      Serial.println(med_temp2);
      
    }
    else {error();}
    
    delay(100);*/
  //***********************************************************************************************//
    long hour = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber3, SECRET_READ_APIKEY);
    statusCode = ThingSpeak.getLastReadStatus();
    
    if (statusCode == 200) {
      Serial.println("Hour:");
      Serial.println(hour);
      //lcd.clear();
      //lcd.print(hour);
    }
    else {error();}
    
    delay(100);
  //***********************************************************************************************//
    long minute = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber4, SECRET_READ_APIKEY);
    statusCode = ThingSpeak.getLastReadStatus();
    
    if (statusCode == 200) {
      Serial.println("Minute:");
      Serial.println(minute);
      //lcd.clear();
      //lcd.print(minute);
    }
    else {error();}
  
    delay(100);
  //***********************************************************************************************//
    long compno = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber5, SECRET_READ_APIKEY);
    statusCode = ThingSpeak.getLastReadStatus();
    
    if (statusCode == 200) {
      Serial.println("Compartment No. :");
      Serial.println(compno);
      //lcd.clear();
      // lcd.print(compno);
    }
    else {error();}
    
    delay(3000);
 
  
  
  String alarm_hour_1;
  //a = String("0");
  int alarm_minute_1 = minute;
  alarm_hour_1 = hour;
  
  String alarm_hour_2;
  //b = String("0");
  int alarm_minute_2 = minute;
  alarm_hour_2 = hour;
  
  String alarm_hour_3;
  //c = String("0");
  int alarm_minute_3 = minute;
  alarm_hour_3 = hour;
  
  int valueA0 = 1;

  display_time();
  
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  int mini = (p_tm->tm_min);
  int hr = (p_tm->tm_hour);

  int comp_input_1 = digitalRead(5);
  Serial.println(comp_input_1);

  int comp_input_2 = digitalRead(14);
  Serial.println(comp_input_2);

  int comp_input_3 = digitalRead(12);
  Serial.println(comp_input_3);
  
//******************************************************************************* 
  if ((String(hr) == alarm_hour_1) && (mini == alarm_minute_1) && (compno == 1)){
      digitalWrite(16,HIGH);
      Serial.println("its high");
      Serial.println(alarm_minute_1+2);
      if (comp_input_1 == 1){
          digitalWrite(16,LOW);
          delay(60000);
        }
      if (mini == alarm_minute_1+2) {
        int valueA0 = 1;
        int httpCode = ThingSpeak.writeField(myChannelNumber, 1, valueA0, myWriteAPIKey);
        if (httpCode == 200) {
          Serial.println("Channel write successful.");
          }
        else {
          Serial.println("Problem writing to channel. HTTP error code " + String(httpCode));
          }
        }
      }
  else {
      digitalWrite(16,LOW);
      Serial.println("its low");
  }

//*******************************************************************************
  if ((String(hr) == alarm_hour_2) && (mini == alarm_minute_2)&& (compno == 2)){
      digitalWrite(4,HIGH);
      lcd.clear();
      lcd.print("Take Your Pill");
      lcd.setCursor(0,1);
      lcd.print("Disprin");
      lcd.setCursor(0,0);
      delay(10000);
      Serial.println("its high");
      if (comp_input_2 == 1){
          digitalWrite(4,LOW);
          lcd.clear();
        lcd.print("Take Your Pill");
      lcd.setCursor(0,1);
      lcd.print("Disprin");
      lcd.setCursor(0,0);
          delay(60000);
        }
      else {
        
        }
  }
  else {
      digitalWrite(4,LOW);
      Serial.println("its low");
  }
//*******************************************************************************
 if ((String(hr) == alarm_hour_3) && (mini == alarm_minute_3)&& (compno == 3)){
      digitalWrite(13,HIGH);
      Serial.println("its high");
      if (comp_input_3 == 1){
          digitalWrite(13,LOW);
          delay(60000);
        }
      else {
        }
  }
  else {
      digitalWrite(13,LOW);
      Serial.println("its low");
  }
  
  //decrypt_data();
  lcd.clear();
  lcd.print("Medicine Added");
//*******************************************************************************
  delay(5000);
}
