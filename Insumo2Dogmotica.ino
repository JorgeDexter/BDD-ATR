#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

const char* WIFI_SSID = "a";
const char* WIFI_PASSWORD = "12345678";

const char* API_KEY = "AIzaSyABAvj13tO6mdZZYd79EIy3mKqj0RrHNaI";
const char* DATABASE_URL = "https://bdd-atr-default-rtdb.firebaseio.com/";
const char* USER_EMAIL = "jorgecalderon20062411@gmail.com";
const char* USER_PASSWORD = "JORGELUIS";

const int POTENCIOMETRO_PIN = 34; 

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");

  Firebase.begin(&config, &auth);

  pinMode(POTENCIOMETRO_PIN, INPUT);
}

void loop() {
  int valorPot = analogRead(POTENCIOMETRO_PIN);  // Leer el valor del potenciómetro

  // Establecer estados basados en rangos del potenciómetro
  Firebase.RTDB.setBool(&fbdo, "/casa/Baño", valorPot >= 0 && valorPot < 1024);
  Firebase.RTDB.setBool(&fbdo, "/casa/Cocina", valorPot >= 1024 && valorPot < 2048);
  Firebase.RTDB.setBool(&fbdo, "/casa/Comedor", valorPot >= 2048 && valorPot < 3072);
  Firebase.RTDB.setBool(&fbdo, "/casa/Dormitorio", valorPot >= 3072 && valorPot <= 4095);

  // Imprimir el estado en la consola serial
  Serial.print("Baño: ");
  Serial.println((valorPot >= 0 && valorPot < 1024) ? "true" : "false");
  Serial.print("Cocina: ");
  Serial.println((valorPot >= 1024 && valorPot < 2048) ? "true" : "false");
  Serial.print("Comedor: ");
  Serial.println((valorPot >= 2048 && valorPot < 3072) ? "true" : "false");
  Serial.print("Dormitorio: ");
  Serial.println((valorPot >= 3072 && valorPot <= 4095) ? "true" : "false");

  delay(2000);  // Pausa para estabilidad de lectura
}