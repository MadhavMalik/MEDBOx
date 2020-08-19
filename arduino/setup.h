/*
#include "secrets.h"

int statusCode = 0; 

const int FieldNumber1 = 1;
const int FieldNumber2 = 2;
const int FieldNumber3 = 3;
const int FieldNumber4 = 4;
const int FieldNumber5 = 5;


void error(){
  Serial.println("Unable to read");
  Serial.println("or No internet!");
}

void data() {
 
  long med_temp1 = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber1, SECRET_READ_APIKEY);
  statusCode = ThingSpeak.getLastReadStatus();

  if (statusCode == 200) {
    Serial.println("Medcine Name1 :");
    Serial.println(med_temp1);
  }
  else {error();}
  
  delay(100);

  long med_temp2 = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber2, SECRET_READ_APIKEY);
  statusCode = ThingSpeak.getLastReadStatus();

  if (statusCode == 200) {
    Serial.println("Medcine Name2 :");
    Serial.println(med_temp2);
  }
  else {error();}
  
  delay(100);

  long hour = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber3, SECRET_READ_APIKEY);
  statusCode = ThingSpeak.getLastReadStatus();
  
  if (statusCode == 200) {
    Serial.println("Hour:");
    Serial.println(hour);
  }
  else {error();}
  
  long minute = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber4, SECRET_READ_APIKEY);
  statusCode = ThingSpeak.getLastReadStatus();
  
  if (statusCode == 200) {
    Serial.println("Minute:");
    Serial.println(minute);
  }
  else {error();}
  
  long compno = ThingSpeak.readLongField(SECRET_CH_ID, FieldNumber5, SECRET_READ_APIKEY);
  statusCode = ThingSpeak.getLastReadStatus();
  
  if (statusCode == 200) {
    Serial.println("Compartment No. :");
    Serial.println(compno);
  }
  else {error();}

 
  /*
  int half_name = med_temp1;
  int other_half = med_temp2;
  String mystr;
  String mystr1;
  String l1;
  String l2;
  String l3;
  String l4;
  String l5;
  String l6;
  String l7;
  String l8;
  //String z;
  
  char array1[14];
  char array2[14];
  char array3[2];
  
  mystr += half_name;
  mystr1 += other_half;
  
  mystr.toCharArray(array1,14);
  mystr1.toCharArray(array2,14);

  l1 = String(array1[0]) + String(array1[1]);
  l1.toCharArray(array3,2);
#define z array3;
  l2 = String(array1[2]) + String(array1[3]);
  l3 = String(array1[4]) + String(array1[5]);
  l4 = String(array1[6]) + String(array1[7]);
  
  l5 = String(array2[0]) + String(array2[1]);
  l6 = String(array2[2]) + String(array2[3]);
  l7 = String(array2[4]) + String(array2[5]);
  l8 = String(array2[6]) + String(array2[7]);

  //c = char(z);
  #define v typeof(z);
  Serial.println(v);
  Serial.println(array1[2]);
  Serial.println(array1[3]);
  Serial.println(array1[4]);
  Serial.println(array1[5]);
  Serial.println(array1[6]);
  Serial.println(array1[7]);
  
  Serial.println("    ");
  
  Serial.println(array2[0]);
  Serial.println(array2[1]);
  Serial.println(array2[2]);
  Serial.println(array2[3]);
  Serial.println(array2[4]);
  Serial.println(array2[5]);
  Serial.println(array2[6]);
  Serial.pri ntln(array2[7]);
  
  //delay(1000);  */
  //delay(3000);
  
//}*/
