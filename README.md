#  VerticalCar (STM32 4WD Robot)

A high-performance four-wheel-drive robot platform powered by the **STM32F103C8T6 (Blue Pill)**. This project is developed, compiled, and flashed entirely within an **Arch Linux** environment.

---

##  Hardware Specifications

### Core Components
* **Microcontroller:** STM32F103C8T6 (Blue Pill)
* **Motor Driver:** L298N Dual H-Bridge
* **Chassis:** 4WD Acrylic Platform + 4 DC Geared Motors
* **Power Source:** 2x 18650 Li-ion Batteries (7.4V - 8.4V)
* **Programmer:** ST-Link V2 (SWD Interface)

###  Wiring Map

#### 1. Logic Interface (STM32 → L298N)
| STM32 Pin | L298N Pin | Function |
| :--- | :--- | :--- |
| **PA0** | **IN1** | Left Side (Forward) |
| **PA1** | **IN2** | Left Side (Backward) |
| **PA2** | **IN3** | Right Side (Forward) |
| **PA3** | **IN4** | Right Side (Backward) |
| **PA6** (PWM) | **ENA** | Left Speed Regulation |
| **PA7** (PWM) | **ENB** | Right Speed Regulation |

> **Setup Tip:** To enable speed control via code, you must **remove the black jumpers** from the ENA/ENB headers on the L298N and connect them to PA6/PA7.

#### 2. Power Distribution
* **Main Power:** Connect Battery (+) to L298N **12V** and Battery (-) to L298N **GND**.
* **Common Ground:** Connect L298N **GND** to STM32 **G (GND)**. This is essential for signal stability.
* **Logic Power:** Connect L298N **+5V** output to STM32 **5V** input.

---

## Software Environment 

### 1. Install Toolchain
```bash
sudo pacman -S arduino-cli stlink
```

### 2. Configure the STM32 Core
```bash
# Initialize config
arduino-cli config init

# Add STM32 Board Manager URL
arduino-cli config add board_manager.additional_urls [https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json](https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json)

# Update index and install the core
arduino-cli core update-index
arduino-cli core install STM32:stm32

```
---

## Development Workflow

### 1. Compilation
```bash
arduino-cli compile --fqbn STM32:stm32:GenF1:pnum=BLUEPILL_F103C8 --output-dir ./build
```
### 2. Flashing
```bash
st-flash write ./build/*.bin 0x08000000
```


