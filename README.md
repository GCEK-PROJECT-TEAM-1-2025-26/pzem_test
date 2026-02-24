# PZEM-004T Power Monitor

This project reads data from a PZEM-004T power monitoring sensor using an ESP32 microcontroller.

## Features

The program monitors and displays:
- **Voltage** (V)
- **Current** (A)
- **Power** (W)
- **Energy** (kWh)
- **Frequency** (Hz)
- **Power Factor**

Readings are displayed on the Serial Monitor every 2 seconds.

## Hardware Required

- ESP32 Development Board
- PZEM-004T Sensor Module
- Jumper wires
- USB cable for programming

## Wiring Connections

Connect the PZEM-004T to ESP32 as follows:

| PZEM-004T | ESP32        |
|-----------|--------------|
| 5V        | 5V           |
| GND       | GND          |
| RX        | GPIO17 (TX2) |
| TX        | GPIO16 (RX2) |

**Note:** The PZEM RX connects to ESP32 TX, and PZEM TX connects to ESP32 RX.

## Software Setup

### Prerequisites
- [PlatformIO](https://platformio.org/) installed in VS Code
- Python with `intelhex` module (if build errors occur)

### Installation

1. **Clone or open this project** in VS Code with PlatformIO

2. **Install Python dependencies** (if needed):
   ```bash
   pip install intelhex
   ```

3. **Build the project**:
   ```bash
   pio run
   ```

4. **Upload to ESP32**:
   ```bash
   pio run --target upload
   ```

5. **Open Serial Monitor**:
   ```bash
   pio device monitor
   ```
   Or use the Serial Monitor button in VS Code (115200 baud)

## Usage

1. Connect the PZEM-004T sensor to AC power line (mains voltage)
2. Wire the PZEM-004T to ESP32 as shown above
3. Upload the program to ESP32
4. Open Serial Monitor at 115200 baud
5. View real-time power readings

### Expected Output

```
PZEM-004T Power Monitor
========================

--- Power Readings ---
Voltage:      230.5 V
Current:      1.250 A
Power:        285.6 W
Energy:       12.345 kWh
Frequency:    50.0 Hz
Power Factor: 0.99
---------------------
```

## Configuration

### Change GPIO Pins

Edit [src/main.cpp](src/main.cpp) and modify these lines:

```cpp
#define PZEM_RX_PIN 16  // Change to your RX pin
#define PZEM_TX_PIN 17  // Change to your TX pin
```

### Change Reading Interval

Modify the delay at the end of `loop()`:

```cpp
delay(2000);  // Change 2000 to desired milliseconds
```

### Reset Energy Counter

Add this line in `setup()` or call it when needed:

```cpp
pzem.resetEnergy();
```

## Troubleshooting

### "Error reading from PZEM-004T sensor!"

**Possible causes:**
- Incorrect wiring (check RX/TX connections)
- Sensor not powered (needs 5V)
- Sensor not connected to AC load
- Bad jumper wires or loose connections
- Wrong GPIO pins configured

**Solutions:**
1. Double-check wiring connections
2. Verify sensor has power (LED should light up)
3. Try swapping RX/TX connections if still not working
4. Test with a different Serial port (e.g., Serial1 with different pins)

### Build Error: "No module named 'intelhex'"

Install the Python module:
```bash
pip install intelhex
```

### No Serial Output

- Check Serial Monitor baud rate is set to 115200
- Press the ESP32 reset button
- Verify USB cable supports data transfer (not just power)

## Library Information

This project uses the [PZEM-004T-v30](https://github.com/mandulaj/PZEM-004Tv30) library by mandulaj.

## Safety Warning

⚠️ **WARNING:** The PZEM-004T connects to mains voltage (AC power). Always:
- Use proper insulation
- Never touch exposed AC terminals
- Disconnect power before wiring
- Follow local electrical codes
- Use a qualified electrician if unsure

## License

This project is provided as-is for educational purposes.
