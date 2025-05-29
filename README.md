# ❤️  Heart Rate Calc (Consistent BPM Averaging)

This Arduino-based project uses the **MAX30102** pulse oximeter sensor to measure heart rate (in BPM). It collects a fixed number of valid BPM readings and prints the average once complete. It also draws a **real-time heart rate graph** using the Arduino Serial Plotter.

---

## 🛠 Hardware Requirements

* **MAX30102** sensor module
* **Arduino Uno**, Nano, or compatible microcontroller
* Jumper wires

### ✅ Wiring (Arduino Uno Example)

| MAX30102 Pin | Arduino Uno Pin |
| ------------ | --------------- |
| VIN          | 3.3V or 5V      |
| GND          | GND             |
| SDA          | A4              |
| SCL          | A5              |

> 🔎 Use 3.3V if unsure—some boards are not 5V tolerant.

---

## 📦 Libraries Used

Install these via the Arduino Library Manager:

* [SparkFun MAX3010x Sensor Library](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library)
* `Wire` (built-in with Arduino)
* `heartRate.h` (included in the SparkFun library)

---

## 🚀 Code Behavior

This project reads IR signals from your finger and calculates **heart beats per minute (BPM)** using the MAX30102. It collects **20 valid readings** (between 40–180 BPM) and then prints the **final average BPM**.

It also sends the BPM values continuously to the Serial Monitor, which can be visualized as a **real-time BPM graph** using the Arduino Serial Plotter.

### ▶️ How it Works:

1. Place your finger on the sensor.
2. Valid beats are detected and BPM is calculated.
3. After 20 valid readings, it computes the average.
4. Final result is printed, and the system halts further readings.

---

## 💻 Example Serial Output

```
Initializing...
Place your finger on the sensor...
72.1

74.0

75.3

...
Final Average BPM (from 20 readings):

73
```

---

## ⚠️ I²C Pull-Up Resistors

### Why are they needed?

The MAX30102 communicates using **I²C**, which is an **open-drain** protocol. This means devices on the I²C bus can pull the line **low**, but not **high**. **Pull-up resistors** are needed to ensure signal levels return to HIGH properly.

### Do you need to add them manually?

* ✅ **Most MAX30102 breakout boards include 4.7kΩ pull-ups** on the SDA and SCL lines.
* ❌ If you’re using a raw sensor or a custom PCB, **you must add them manually** (typically 4.7kΩ–10kΩ between SDA/SCL and VCC).

---

## 🧠 Tips for Reliable Readings

* Ensure consistent pressure of the finger—too light or too hard will cause noise.
* Avoid motion during measurement.
* Use the Serial Plotter in Arduino IDE to observe the IR signal and fine-tune detection.

---

## 📄 License

This project is open-source under the MIT License.

---

## 👤 Author

📌 **Ahmed Attay**
🔗 [LinkedIn Profile](https://www.linkedin.com/in/ahmedattay/)

## 🙌 Credits

* [SparkFun MAX3010x Library](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library)
