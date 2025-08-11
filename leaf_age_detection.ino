#include <dht.h>

// Define DHT sensor type and pin
#define DHTTYPE DHT11
#define DHTPIN A2

dht DHT;

int redLedPin = 9;
int blueLedPin = 10;
int sensorPin = A0;

// Linear regression coefficients (replace with values from your trained model)
float coefRed = -1.01797235;
float coefBlue = -0.14746544;
float intercept1 = 318.77926267281106;
float coefTemp = 0.6922697813669882;
float coefHum = -0.04193836581762048;
float coefChloro = 0.2431709228881338;
float intercept = -4.0432193228460065;

void setup() {
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.println("DHT11 Humidity and temperature sensor\n");
}

void loop() {
  // Read red LED reflection
  digitalWrite(redLedPin, HIGH);
  delay(1000); // Allow time for stabilization
  int redValue = analogRead(sensorPin);
  digitalWrite(redLedPin, LOW);

  // Read blue LED reflection
  digitalWrite(blueLedPin, HIGH);
  delay(1000);
  int blueValue = analogRead(sensorPin);
  digitalWrite(blueLedPin, LOW);

  // Calculate the difference
  int difference = redValue - blueValue;

  // Output the result
  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print(" Blue: ");
  Serial.print(blueValue);
  Serial.print(" Difference: ");
  Serial.println(difference);

  // Read data from DHT sensor
  int chk = DHT.read11(DHTPIN);
  float humidity = DHT.humidity;
  float temperature = DHT.temperature;

  // Debugging prints
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", Temperature: ");
  Serial.println(temperature);

  // Calculate chlorophyll content using the linear regression model
  float chlorophyllContent = coefRed * redValue + coefBlue * blueValue + intercept1;

  // Debugging prints
  Serial.print("Calculated chlorophyll content: ");
  Serial.println(chlorophyllContent);

  // Predict spinach leaf age using the trained regression model
  float leafAge = coefTemp * temperature + coefHum * humidity + coefChloro * chlorophyllContent + intercept;

  // Additional debug prints for leaf age calculation
  Serial.print("Temperature Coefficient Contribution: ");
  Serial.println(coefTemp * temperature);
  Serial.print("Humidity Coefficient Contribution: ");
  Serial.println(coefHum * humidity);
  Serial.print("Chlorophyll Coefficient Contribution: ");
  Serial.println(coefChloro * chlorophyllContent);
  Serial.print("Intercept Contribution: ");
  Serial.println(intercept);

  // Send data over serial
  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print(", Blue: ");
  Serial.print(blueValue);
  Serial.print(", Chlorophyll: ");
  Serial.print(chlorophyllContent);
  Serial.print(", Temp: ");
  Serial.print(temperature);
  Serial.print(", Hum: ");
  Serial.print(humidity);
  Serial.print(", Leaf Age: ");
  Serial.println(leafAge);

  delay(10000); // Delay between readings
}
