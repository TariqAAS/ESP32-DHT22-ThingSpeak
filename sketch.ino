#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// DHT22 Sensor
DHT senorDHT(15, DHT22);

// LED
const int ledPin = 23;

// WiFi Settings
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ThingSpeak Settings
unsigned long channelNumber = 3551365;
const char* writeAPIKey = "6TE3AO1X4HQ5JI88";

WiFiClient client;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  senorDHT.begin();

  // University ID
  Serial.println("University ID: 12217122");

  // Connect to WiFi
  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, password, 6);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  // Start ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read sensor values
  float temperature = senorDHT.readTemperature();
  float humidity = senorDHT.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22!");
    delay(30000);
    return;
  }

  // Print readings
  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  // Control LED
  if (temperature > 30) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Send readings to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int stat = ThingSpeak.writeFields(
    channelNumber, writeAPIKey
  );

  if (stat == 200) {
    Serial.println("Data sent successfully!");
  } else {
    Serial.print("Error sending data: ");
    Serial.println(stat);
  }

  // Wait 30 seconds
  delay(30000);
}
