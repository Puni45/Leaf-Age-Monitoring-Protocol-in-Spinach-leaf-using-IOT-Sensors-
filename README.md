# Leaf-Age-Monitoring-Protocol-in-Spinach-leaf-using-IOT-Sensors

# 🌱 Spinach Leaf Age & Chlorophyll Prediction System



---

## 📖 Overview
This project measures **chlorophyll content** and predicts **spinach leaf age** using a combination of:
- **Red & Blue LED light reflection sensors**
- **DHT11 Temperature & Humidity sensor**
- A **trained linear regression model** embedded in Arduino code

The system uses the differences in LED light reflection, environmental conditions, and regression coefficients to estimate both the **chlorophyll level** and **leaf age** in real-time.

---

## 🎯 Features
- 🌡 **Temperature & Humidity Monitoring** (DHT11 sensor)
- 🔴🔵 **LED-based Optical Sensing** (red & blue reflection values)
- 📊 **Chlorophyll Content Estimation** (calculated from regression model)
- ⏳ **Leaf Age Prediction** (based on environmental & optical data)
- 🖥 **Serial Monitor Output** for live data logging & debugging
- ⚡ **Low-Cost Hardware Implementation**

---

## 🛠 Hardware Components
- **Arduino Uno / Nano**
- **DHT11 Temperature & Humidity Sensor**
- **Red LED** + **Blue LED**
- **Photoresistor / LDR sensor** (analog light measurement)
- **Resistors** for LEDs & LDR
- **Breadboard & jumper wires**


---

## 🔍 How It Works
1. **Red LED ON** → Measure light reflection using LDR → Store value.
2. **Blue LED ON** → Measure reflection → Store value.
3. **Calculate Difference** between red & blue reflections.
4. **Read Temperature & Humidity** from DHT11 sensor.
5. **Apply Linear Regression Equations**:
   - Chlorophyll Content = `coefRed * redValue + coefBlue * blueValue + intercept1`
   - Leaf Age = `(coefTemp * temp) + (coefHum * humidity) + (coefChloro * chlorophyll) + intercept`
6. **Display Results** on Serial Monitor.

---

## 🖥 Sample Output
```
Red: 512, Blue: 345, Difference: 167
Humidity: 48.0, Temperature: 26.5
Calculated chlorophyll content: 78.32
Temperature Coefficient Contribution: 18.35
Humidity Coefficient Contribution: -2.01
Chlorophyll Coefficient Contribution: 19.02
Intercept Contribution: -4.04
Leaf Age: 31.32 days
```

---

## 📦 Installation & Setup
1. Install **Arduino IDE** ([Download here](https://www.arduino.cc/en/software))
2. Install the **DHT Sensor Library** by Rob Tillaart or Adafruit.
3. Connect components as per circuit diagram.
4. Open `.ino` file in Arduino IDE.
5. Upload to Arduino board.
6. Open Serial Monitor at **9600 baud** to view results.

---

## ⚠️ Notes
- The regression coefficients (`coefRed`, `coefBlue`, etc.) are from a trained model — you can retrain using your own dataset.
- Sensor readings may vary depending on environmental conditions; calibrate for best accuracy.



---

## 🌟 Future Improvements
- 📡 Send data to a cloud dashboard (ThingsBoard, Blynk, etc.)
- 📱 Develop a mobile app for real-time monitoring
- 🔋 Optimize power consumption for field deployment

## ✍️ Author
Puneeth Kumar B C

GitHub: @Puni45


