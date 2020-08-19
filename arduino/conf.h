
void conf_time() {
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");
  while(!time(nullptr)){
      Serial.print("*");
      delay(1000);
  }
}

void conf_wifi() {
  if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(SECRET_SSID);
      while (WiFi.status() != WL_CONNECTED) {
          WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
          Serial.print(".");
          delay(5000);
    }
    Serial.println("\nConnected.");
  }
}
void display_time(){
  
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  Serial.print(p_tm->tm_mday);
  Serial.print("/");
  Serial.print(p_tm->tm_mon + 1);
  Serial.print("/");
  Serial.print(p_tm->tm_year + 1900);
  
  Serial.print(" ");
  
  Serial.print(p_tm->tm_hour);
  Serial.print(":");
  Serial.print(p_tm->tm_min);
  Serial.print(":");
  Serial.println(p_tm->tm_sec);
  
}
