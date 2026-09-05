#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting...");
    }

    Serial.println("WiFi connected!");

    HTTPClient http;

    // Use your PC's IP here
    http.begin("http://192.168.1.100:5000/data");

    http.addHeader("Content-Type", "application/json");

    String json = R"({
        "temperature": 28.5,
        "humidity": 72
    })";

    int responseCode = http.POST(json);

    Serial.print("Response: ");
    Serial.println(responseCode);

    Serial.println(http.getString());

    http.end();
}

void loop() {
}