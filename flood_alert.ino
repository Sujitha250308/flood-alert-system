#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

const int sensorPin = A0;    // Water level sensor
const int buzzerPin = D5;    // Buzzer
const int ledPin = D6;       // Alert LED
const int threshold = 500;   // Danger level (adjust after testing)

ESP8266WebServer server(80);
int waterLevel = 0;
bool floodAlert = false;

void handleRoot() {
  String status = floodAlert ? "FLOOD ALERT! Water level HIGH" : "Safe";
  String page = "<html><head><meta http-equiv='refresh' content='3'>"
                "<meta name='viewport' content='width=device-width, initial-scale=1'></head>"
                "<body style='font-family:Arial;text-align:center'>"
                "<h1>Flood Alert System</h1>"
                "<h2>Water level: " + String(waterLevel) + "</h2>"
                "<h2>Status: " + status + "</h2></body></html>";
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Open this IP in your browser: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  waterLevel = analogRead(sensorPin);
  floodAlert = (waterLevel > threshold);

  digitalWrite(buzzerPin, floodAlert ? HIGH : LOW);
  digitalWrite(ledPin, floodAlert ? HIGH : LOW);

  Serial.print("Water level: ");
  Serial.println(waterLevel);

  server.handleClient();
  delay(500);
}
