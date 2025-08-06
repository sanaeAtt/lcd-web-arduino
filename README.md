# 💬 LCD Web Message Sender with Arduino

This project allows you to send messages from a **web interface** directly to an **Arduino LCD screen** using **Flask** (Python) and **Serial communication**.

It’s perfect for small displays, IoT dashboards, or just a fun learning project.

---

## ✨ Features

- 💻 Beautiful web interface built with HTML/CSS
- 🚀 Real-time message sending to Arduino via USB serial
- 📟 LCD automatically scrolls messages longer than 16 characters
- 🔁 Support for dynamic message updates
- 🌐 Works locally or over the internet using #Ngrok

---

## 📦 Requirements

- Python 3.8+
- Arduino MEGA/UNO (or compatible)
- 16x2 LCD screen (connected via `LiquidCrystal`)
- USB cable
- pip (Python package manager)

---

## 🛠 Project Structure

lcd-web-arduino/
├── arduino/
│ └── lcd_display.ino # Arduino sketch for LCD scrolling
├── static/
│ └── index.html # Web interface
├── server.py # Flask backend for serial messaging
├── requirements.txt # Python dependencies
├── .gitignore
└── README.md # This file

---

## ⚙️ Hardware Setup

### 🔌 LCD to Arduino Wiring

| LCD Pin  | Arduino Pin |
|----------|-------------|
| RS       | 12          |
| EN       | 11          |
| D4       | 5           |
| D5       | 4           |
| D6       | 3           |
| D7       | 2           |
| VSS      | GND         |
| VDD      | 5V          |
| V0       | Potentiometer (for contrast) |
| RW       | GND         |
| A        | 5V (for backlight) |
| K        | GND         |

---

## 🚀 How to Run It

### ✅ 1. Upload the Arduino Code

1. Open `arduino/lcd_display.ino` in the Arduino IDE.
2. Connect your Arduino via USB.
3. Upload the sketch.
4. Keep the Arduino connected.

---

### ✅ 2. Set Up Python Backend

In your terminal (PowerShell or Bash):

```bash
# Clone the repository
git clone https://github.com/sanaeAtt/lcd-web-arduino.git
cd lcd-web-arduino

# Create a virtual environment (optional but recommended)
```bash
    python -m venv .venv
    .\.venv\Scripts\activate  # On Windows
# source .venv/bin/activate  # On macOS/Linux

# Install required packages
```bash
  pip install -r requirements.txt

# Run the Flask server
python server.py

📌 Make sure the Arduino is connected to the correct COM port. Update this line in server.py if necessary:

```bash
    arduino = serial.Serial('COM3', 9600)

Use mode (on Windows) or check the Arduino IDE to find the right port.

---

### ✅ 3. Run the Web Interface

After running the Flask server, open your browser and go to:

```bash
 http://localhost:5000

From there:

- Type your message (max 32 characters)

- Click Send to LCD

- It will instantly show on the LCD screen via USB

---

### ✅ 4. (Optional) Use Ngrok to Access Remotely

To share your interface over the internet:

```bash
ngrok http 5000

You’ll get a public URL like:

```bash
https://abcd1234.ngrok-free.app

Open this link on any device and send messages to your Arduino!

# 📜 License
MIT License — use, modify, and share freely.

# 🙌 Author
Made with ❤️ by Sanae Aatik

GitHub: @sanaeAtt




