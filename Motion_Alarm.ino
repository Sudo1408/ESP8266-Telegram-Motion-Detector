#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <UniversalTelegramBot.h>

// Telegram credentials
char telegramToken[64];
char telegramChatId[32];

// Initialize Telegram bot
WiFiClientSecure client;
UniversalTelegramBot* bot;

// Define the pin numbers for the PIR sensor, LED, and buzzer
const int pirPin = D1;    // PIR sensor connected to GPIO pin 2
const int buzzerPin = D2; // Buzzer connected to GPIO pin 4
const int ledPin = D3;    // LED connected to GPIO pin 5

// Define variables for period and timers
unsigned long previousMillis = 0;
const long period = 6000; // Period in milliseconds (e.g., 6 seconds)

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Set the PIR pin as an input
  pinMode(pirPin, INPUT);
  // Set the LED and buzzer pins as outputs
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize WiFi connection
  WiFiManager wifiManager;

  // Add custom parameters
  WiFiManagerParameter customTelegramToken("telegramToken", "Telegram Bot Token", telegramToken, 64);
  WiFiManagerParameter customTelegramChatId("telegramChatId", "Telegram Chat ID", telegramChatId, 32);

  // Add parameters to WiFiManager
  wifiManager.addParameter(&customTelegramToken);
  wifiManager.addParameter(&customTelegramChatId);

  // Connect to WiFi and retrieve parameters
  wifiManager.resetSettings();
  wifiManager.autoConnect("ESP8266-Telegram-Bot");
  
  // Retrieve Telegram credentials from parameters
  strcpy(telegramToken, customTelegramToken.getValue());
  strcpy(telegramChatId, customTelegramChatId.getValue());

  // Initialize Telegram bot after retrieving credentials
  client.setInsecure();
  bot = new UniversalTelegramBot(telegramToken, client);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if period has passed
  if (currentMillis - previousMillis >= period) {

    // Save the last time motion was detected
    previousMillis = currentMillis;
    
    // Read the state of the PIR sensor
    int pirState = digitalRead(pirPin);
  
    if (pirState == HIGH) {
      Serial.println("Motion Detected!");
      // If motion is detected, turn on the LED and activate the buzzer
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW); // Turn off the LED
      sendMessage("[+] Alert!! [+]");
      sendMessage("[+] Motion Detected [+]");
    } else {
      // If no motion is detected, turn off the LED and buzzer
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      Serial.println("No motion detected.");
    }
  }
}

void sendMessage(String message) {
  // Send message via Telegram
  bot->sendMessage(telegramChatId, message, "");
  Serial.println(telegramChatId);
}
