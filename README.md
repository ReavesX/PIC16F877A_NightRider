# PIC16F877A NightRider LED Scanner

Emulates the iconic *Knight Rider* LED scanner (KITT) using a PIC16F877A microcontroller.

## 📋 Table of Contents

* [Features](#features)
* [Hardware Requirements](#hardware-requirements)
* [Circuit Setup](#circuit-setup)
* [Software & Setup](#software--setup)
* [Usage](#usage)
* [Customization](#customization)
* [Troubleshooting](#troubleshooting)
* [License](#license)

---

## Features

* Smooth back-and-forth LED scanning effect.
* Adjustable scan speed via code.
* Compact layout—ideal for breadboard or perfboard setups.

---

## 🔧 Hardware Requirements

* PIC16F877A microcontroller
* 8 × LEDs (preferably red)
* 220 Ω current-limiting resistors
* 10 kΩ pull-down/up resistor for MCLR
* 4 MHz crystal oscillator (or internal oscillator) + caps
* 5 V regulated power supply
* Programmer (e.g. PICkit3/4)

---

## 📐 Circuit Setup

1. Connect each LED (with resistor) to consecutive PORTD pins (RD0–RD7).
2. Connect MCLR pin with 10 kΩ pull-up resistor to +5V.
3. Hook up the oscillator circuit (4 MHz crystal + caps) or enable the internal oscillator.
4. Ensure proper Vdd (5 V) and Vss (ground) connections.
5. Connect ICD/ICSP pins (PGC/PGD) for programming with PICkit.

---

## Software & Setup

1. Install MPLAB X IDE and XC8 compiler from Microchip.
2. Open/import the `.c` source file(s).
3. Adjust configuration fuses:

   * Oscillator: 4 MHz XT (or INTOSC for internal).
   * Watchdog Timer: OFF.
   * MCLR Enabled.
   * Brown-out Reset: ON.
4. Build/project -> generate `.hex` file.
5. **To find the prebuilt **\`\`** file:**

   * Navigate to the `dist` folder inside the project repository.
   * Open `default/production` subdirectory.
   * Locate the file named something with the file extension `.X.production.hex`.
6. Program the PIC using PICkit or compatible programmer.

---

## Usage

* Power the circuit.
* PIC boots and begins LED scanning effect.
* To adjust speed: modify delay in source code (e.g., `_delay_ms(...)`) and reprogram.

---

## Customization

* **Speed**: Change loop delay values.
* **LED count**: Modify loop boundaries and wiring if using fewer than 8 LEDs.
* **Patterns**: Edit code to alter ripple, random, or symmetrical effects.
* **Oscillator**: If switching to internal, update config bits and remove external crystal.

---

## Troubleshooting

| Issue                       | Likely Cause                           | Solution                                |
| --------------------------- | -------------------------------------- | --------------------------------------- |
| LEDs don’t light            | Damaged LEDs/resistors or wrong wiring | Inspect wiring and dependencies         |
| LEDs stuck in one direction | Faulty code loop logic                 | Break in debugging; simulate via MPLAB  |
| No output at all            | Oscillator/config issue                | Check ICD connections and config bits   |
| PIC not programmable        | MCLR / Vpp wiring incorrectly          | Re-check pull‑up and PICkit connections |

---

## 📄 License

Released under the [MIT License](LICENSE). Feel free to fork, modify, and improve!

---

### Example

```c
for (int i = 0; i < 8; i++) {
    PORTB = 1 << i;
    __delay_ms(100);
}
// bounce back...
```
