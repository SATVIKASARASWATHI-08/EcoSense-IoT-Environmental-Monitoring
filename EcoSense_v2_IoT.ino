#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <WiFi.h>
#include <ThingSpeak.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);



#define MQ2_PIN 34



#define RED_LED 25
#define GREEN_LED 26
#define BLUE_LED 27


#define BUZZER 13




float temperature = 0;
float humidity = 0;
int gasValue = 0;

String systemStatus = "";


const char* ssid = "Wokwi-GUEST";
const char* password = "";


unsigned long channelID = 3441536;
const char* writeAPIKey = "YOUR_WRITE_API_KEY";
WiFiClient client;


unsigned long lastUploadTime = 0;
const unsigned long uploadInterval = 20000;



void setup() {

  Serial.begin(115200);

  dht.begin();


  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  pinMode(MQ2_PIN, INPUT);



  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {

    Serial.println("OLED initialization failed!");

    while (true);

  }


  display.clearDisplay();
  display.display();




  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }


  Serial.println();

  Serial.println("WiFi Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());





  ThingSpeak.begin(client);

}



void loop() {


  readSensors();


  updateOutputs();


  updateDisplay();


  printSerial();




  if (millis() - lastUploadTime >= uploadInterval) {

    uploadToThingSpeak();

    lastUploadTime = millis();

  }



  delay(1000);

}





void readSensors() {


  temperature = dht.readTemperature();

  humidity = dht.readHumidity();


  gasValue = analogRead(MQ2_PIN);


}






void updateOutputs() {



  if (gasValue > 3000 || temperature > 35) {


    systemStatus = "DANGER";


    digitalWrite(RED_LED, HIGH);

    digitalWrite(GREEN_LED, LOW);

    digitalWrite(BLUE_LED, LOW);


    digitalWrite(BUZZER, HIGH);



  }



  else if (gasValue > 1500 || temperature > 30) {



    systemStatus = "WARNING";


    digitalWrite(RED_LED, LOW);

    digitalWrite(GREEN_LED, LOW);

    digitalWrite(BLUE_LED, HIGH);


    digitalWrite(BUZZER, LOW);



  }



  else {



    systemStatus = "NORMAL";


    digitalWrite(RED_LED, LOW);

    digitalWrite(GREEN_LED, HIGH);

    digitalWrite(BLUE_LED, LOW);


    digitalWrite(BUZZER, LOW);



  }



}







void updateDisplay() {



  display.clearDisplay();


  display.setTextSize(1);

  display.setTextColor(SSD1306_WHITE);



  display.setCursor(0, 0);

  display.println("EcoSense IoT");



  display.setCursor(0, 16);

  display.print("Temp : ");

  display.print(temperature, 1);

  display.println(" C");



  display.print("Hum  : ");

  display.print(humidity, 1);

  display.println(" %");



  display.print("Gas  : ");

  display.println(gasValue);



  display.println();



  display.print("Status: ");

  display.println(systemStatus);



  display.display();



}







void uploadToThingSpeak() {



  Serial.println("Uploading data to ThingSpeak...");


  ThingSpeak.setField(1, temperature);

  ThingSpeak.setField(2, humidity);

  ThingSpeak.setField(3, gasValue);



 
  int statusValue;



  if (systemStatus == "NORMAL")

    statusValue = 0;


  else if (systemStatus == "WARNING")

    statusValue = 1;


  else

    statusValue = 2;



  ThingSpeak.setField(4, statusValue);



  int response = ThingSpeak.writeFields(channelID, writeAPIKey);



  if (response == 200) {


    Serial.println("ThingSpeak update successful!");

  }


  else {


    Serial.print("ThingSpeak error: ");

    Serial.println(response);

  }



}







void printSerial() {


  Serial.println("--------------------------------");


  Serial.print("Temperature : ");

  Serial.print(temperature);

  Serial.println(" C");



  Serial.print("Humidity    : ");

  Serial.print(humidity);

  Serial.println(" %");



  Serial.print("Gas Value   : ");

  Serial.println(gasValue);



  Serial.print("Status      : ");

  Serial.println(systemStatus);



} 
