# Bare-Metal Water Level Alarm on ATmega328P

This project is a highly efficient, multi-stage water level alarm system built for the ATmega328P microcontroller (found on the Arduino Uno/Nano). It demonstrates the significant performance and memory benefits of "bare-metal" programming by directly manipulating hardware registers instead of using the standard Arduino libraries.

The system monitors a water level sensor and provides visual and audible feedback across three distinct states: Safe, Warning, and Alarm.

## Key Features

*   **Three-Stage Alarm:**
    *   **Safe Level (Low Water):** Green LED is on.
    *   **Warning Level (Medium Water):** Yellow LED is on, and a buzzer sounds with a variable tone.
    *   **Alarm Level (High Water):** Red LED is on, and the buzzer sounds at a high intensity.
*   **Extreme Efficiency:** Written in C++ with direct register manipulation, resulting in a tiny memory footprint.
*   **Hardware PWM Control:** Uses the ATmega328P's Timer1 to generate a precise PWM signal for the buzzer, ensuring non-blocking and efficient sound generation.
*   **Custom ADC Driver:** A minimal, custom driver for reading the analog sensor value.

## Hardware Required

*   Arduino Uno/Nano (or a standalone ATmega328P)
*   1x Water Level Sensor Module
*   1x Red LED
*   1x Yellow LED
*   1x Green LED
*   3x 220Ω Resistors (for the LEDs)
*   1x Active Buzzer
*   Breadboard and Jumper Wires

## Wiring Diagram

This wiring is derived directly from the `enum diagram_pins` defined in the code.

| Component             | Connects to Arduino Pin |
| --------------------- | ----------------------- |
| Water Sensor (Signal) | **A0** (`PC0`)          |
| Green LED (Anode)     | **D11** (`PB3`)         |
| Yellow LED (Anode)    | **D12** (`PB4`)         |
| Red LED (Anode)       | **D13** (`PB5`)         |
| Buzzer (Positive)     | **D10** (`PB2`)         |



![20251001_123701](https://github.com/user-attachments/assets/c3d16f6f-db12-4d1d-a3b2-76c7fe311cf5)




**Step-by-Step Instructions:**

1.  **Water Sensor:**
    *   Connect the `+` pin to the Arduino `5V`.
    *   Connect the `-` pin to the Arduino `GND`.
    *   Connect the `S` (Signal) pin to Arduino pin **A0**.
2.  **LEDs:**
    *   **Green LED:** Connect the long leg (anode) to Arduino pin **D11**. Connect the short leg (cathode) to one end of a 220Ω resistor. Connect the other end of the resistor to `GND`.
    *   **Yellow LED:** Connect the long leg (anode) to Arduino pin **D12**. Connect the short leg (cathode) to one end of a 220Ω resistor. Connect the other end of the resistor to `GND`.
    *   **Red LED:** Connect the long leg (anode) to Arduino pin **D13**. Connect the short leg (cathode) to one end of a 220Ω resistor. Connect the other end of the resistor to `GND`.
3.  **Buzzer:**
    *   Connect the positive (`+`) lead to Arduino pin **D10**.
    *   Connect the negative (`-`) lead to `GND`.

---

## The Bare-Metal Advantage: A Case Study in Efficiency

The primary goal of this project was to showcase the difference between using the high-level Arduino API and writing low-level, bare-metal code. The results speak for themselves.

### Arduino API Version (Less Efficient)

<img width="1251" height="106" alt="b43c629c-d4e8-4d1c-b3dd-a203868c747a" src="https://github.com/user-attachments/assets/19b0ba34-5b45-4765-ad81-2d5399259470" />


### Bare-Metal Version (This Repository - Highly Efficient)

<img width="1245" height="102" alt="454b5ec8-3a29-4a85-b316-bce54eda6bd2" src="https://github.com/user-attachments/assets/fdb24bcb-976f-4c81-941b-fe1a3aaf6868" />

### Analysis: Why This Is a Game Changer

| Metric                | Arduino API | **Bare-Metal** | **Improvement**     |
| --------------------- | ----------- | -------------- | ------------------- |
| **Program Space**     | 2204 bytes  | **608 bytes**  | **72% smaller**     |
| **Dynamic Memory**    | 190 bytes   | **9 bytes**    | **95% smaller!**    |

*   **RAM Savings:** The bare-metal code uses **21 times less RAM**. The Arduino framework pre-allocates memory for features like `Serial` communication, which we aren't using. The 9 bytes used here are only for the variables we explicitly need.
*   **Flash Savings:** The code is **over 3.6 times smaller**. By avoiding the bulky Arduino libraries, we only compile the exact machine code required for our logic, creating a much leaner program.

This is not just a theoretical exercise. On a microcontroller with only 2KB of RAM, saving 181 bytes is massive. This efficiency allows for adding many more features—like a display, more sensors, or complex logic—that would be impossible with the resource-heavy Arduino framework. This is the core principle of professional embedded systems development.

## How to Use

1.  **Assemble the circuit** according to the wiring diagram above.
2.  **Open the `.ino` file** in the Arduino IDE or your preferred C++ editor (like VSCode with PlatformIO).
3.  **Upload the code** to your Arduino Uno/Nano.
4.  **Test the system** by dipping the water level sensor to different depths. You should see the LEDs change and hear the buzzer activate according to the water level.
