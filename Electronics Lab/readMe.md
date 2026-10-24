# 🤖 Autonomous Grid-Based Delivery Robot

An Arduino-powered autonomous line-following delivery robot capable of navigating a $4 \times 4$ coordinate grid (nodes $(0,0)$ to $(3,3)$). Equipped with PID line tracking, ultrasonic obstacle avoidance, and Bluetooth telemetry, the robot can be dispatched to specific grid coordinates, wait for delivery confirmation, and automatically return to its base node.

---

## 🎥 Demo Video
[![Watch the Demo](https://img.shields.io/badge/▶_Watch_Demo_Video-Google_Drive-blue?style=for-the-badge&logo=googledrive)](https://drive.google.com/file/d/1Y2xpSANn2OqHYdj1T0GDvPDmMKfEp0yT/view?usp=sharing)

---

## ✨ Key Features

* **Grid-Based Coordinate Navigation:** Tracks its real-time position $(X, Y)$ and orientation ($0=\text{North}$, $1=\text{East}$, $2=\text{South}$, $3=\text{West}$) across a coordinate grid ranging from $(0,0)$ to $(3,3)$.
* **PID Line Following:** Uses a 5-channel IR sensor array with Proportional-Integral-Derivative ($K_p = 1.6, K_i = 0.0, K_d = 2.2$) control for smooth, accurate line tracking.
* **Bluetooth Dispatch & Telemetry:** Controlled wirelessly via an HC-05/HC-06 Bluetooth module using a serial terminal app.
* **Return-to-Base Workflow:** Remembers the starting dispatch node, waits at the destination for admin clearance (`YES`), and autonomously navigates back to the base node.
* **Active Obstacle Avoidance:** Continuously scans the path ahead using an HC-SR04 ultrasonic sensor. If an obstacle is detected within $15\text{ cm}$, the robot halts, flashes its status LED, and waits until the path is clear before resuming.
* **Emergency Stop / Kill Switch:** Supports instant standby halting (`OFF`, `O`, or `S`) at any point during navigation or obstacle waiting.
* **Audio-Visual Indicators:** Features an onboard buzzer and status LED to signal obstacle alerts, path clearance, and successful delivery (5x synchronized blinks/beeps).

---

## 🛠️ Hardware Components

* **Microcontroller:** Arduino Uno
* **Motor Driver:** TB6612FNG Dual Motor Driver
* **Power Regulation:** MP1584EN Buck Converter (steps down battery voltage to a regulated $5\text{V}$ rail)
* **Line Sensor:** 5-Array IR Sensor Module
* **Obstacle Sensor:** HC-SR04 Ultrasonic Distance Sensor
* **Wireless Communication:** HC-05 or HC-06 Bluetooth Module
* **Actuators:** $2 \times$ DC Gear Motors (Left & Right)
* **Indicators:** $1 \times$ Active Buzzer, $1 \times$ LED with $220\ \Omega$ current-limiting resistor
* **Power Supply:** Li-ion / LiPo Battery Pack + Master Power Switch

---

## 🔌 Wiring & Pin Configuration

### 1. Power Distribution (Buck Converter & Power Rails)
| Source / Pin | Destination / Connection |
| :--- | :--- |
| **Battery (+)** | Switch (Input) |
| **Switch (Output)** | MP1584EN Buck Converter (`IN+`) & TB6612FNG (`VM`) |
| **Battery (-)** | MP1584EN Buck Converter (`IN-`) |
| **MP1584EN (`OUT+`)** | $5\text{V}$ Power Rail |
| **MP1584EN (`OUT-`)** | `GND` Power Rail |
| **Arduino Uno `5V`** | $5\text{V}$ Power Rail |
| **Arduino Uno `GND`** | `GND` Power Rail |

### 2. TB6612FNG Motor Driver
| TB6612FNG Pin | Connection |
| :--- | :--- |
| **VCC** | $5\text{V}$ Power Rail |
| **GND** | `GND` Power Rail |
| **VM** | Switch (Output / Battery Direct $+$) |
| **STBY** | $5\text{V}$ Power Rail (Enables motor driver) |
| **PWMA** | Arduino Uno Pin `D5` |
| **AIN1** | Arduino Uno Pin `D7` |
| **AIN2** | Arduino Uno Pin `D8` |
| **PWMB** | Arduino Uno Pin `D6` |
| **BIN1** | Arduino Uno Pin `D9` |
| **BIN2** | Arduino Uno Pin `D10` |
| **AO1 / AO2** | Left Motor ($+$ / $-$) |
| **BO1 / BO2** | Right Motor ($+$ / $-$) |

### 3. 5-Array IR Sensor Module
| IR Sensor Pin | Connection |
| :--- | :--- |
| **VCC** | $5\text{V}$ Power Rail |
| **GND** | `GND` Power Rail |
| **Output 1 (`IR1`)** | Arduino Uno Pin `A0` |
| **Output 2 (`IR2`)** | Arduino Uno Pin `A1` |
| **Output 3 (`IR3`)** | Arduino Uno Pin `A2` |
| **Output 4 (`IR4`)** | Arduino Uno Pin `A3` |
| **Output 5 (`IR5`)** | Arduino Uno Pin `A4` |

### 4. Peripherals & Indicators (Ultrasonic, Bluetooth, Buzzer, LED)
| Component & Pin | Connection |
| :--- | :--- |
| **HC-SR04 `VCC` / `GND`** | $5\text{V}$ Power Rail / `GND` Power Rail |
| **HC-SR04 `TRIG`** | Arduino Uno Pin `D2` |
| **HC-SR04 `ECHO`** | Arduino Uno Pin `D3` |
| **Bluetooth `VCC` / `GND`** | $5\text{V}$ Power Rail / `GND` Power Rail |
| **Bluetooth `TXD`** | Arduino Uno Pin `D4` (`BT_RX`) |
| **Bluetooth `RXD`** | Arduino Uno Pin `D13` (`BT_TX`) |
| **Buzzer (+)** | Arduino Uno Pin `D12` |
| **Buzzer (-)** | `GND` Power Rail |
| **LED Anode (+)** | Arduino Uno Pin `D11` (via $220\ \Omega$ resistor) |
| **LED Cathode (-)** | `GND` Power Rail |

---

## 📱 Bluetooth Commands & Operation

Pair your smartphone or PC with the **HC-05 / HC-06** Bluetooth module and open a Serial Bluetooth Terminal (baud rate: `9600`).

### 1. Place the Robot on the Grid
Place the robot at the origin node `(0, 0)` facing **North** (`+Y` direction) and turn on the power switch. After a 2-second initialization delay, the terminal will display:
> `Delivery Robot Ready.`  
> `Send target X,Y (e.g., 2,2) to dispatch.`  
> `Send 'OFF' to stop at any time.`

### 2. Command Reference
| Command | Action / Description |
| :--- | :--- |
| **`X,Y`** *(e.g., `2,3`)* | Dispatches the robot from its current node to target coordinates $(X, Y)$, constrained between $0$ and $3$. |
| **`YES`** | Sent after the robot reaches its destination to confirm package pickup and trigger the return trip to the base node. |
| **`OFF`**, **`O`**, or **`S`** | Emergency stop. Immediately stops the motors and places the robot into `STANDBY` mode. |

---

## ⚙️ Software & Tuning Parameters

If you need to calibrate the robot for different floor surfaces, motor speeds, or grid spacings, adjust the following constants in the Arduino sketch:

* **Line Polarity:** `BLACK = LOW`, `WHITE = HIGH`
* **Obstacle Threshold:** `obstacleThreshold = 15` (distance in $\text{cm}$)
* **PID Gains:** `Kp = 1.6`, `Ki = 0.0`, `Kd = 2.2`
* **Motor Speeds:** `baseSpeed = 90`, `maxSpeed = 120`, `turnSpeed = 70` (PWM range $0\text{--}255$)
* **Intersection Alignment:** `nodeOffsetDelay = 200` (time in $\text{ms}$ the robot drives forward after detecting a node to center its wheels over the intersection before turning)
* **Node Debounce:** `ignoreNodeDuration = 400` (time in $\text{ms}$ to ignore repeated intersection triggers when leaving a node)