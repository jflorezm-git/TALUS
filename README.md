
---

# **TALUS – Teleoperated Arm for Learning Using Sensors**

*A modular academic robotic platform integrating actuation, perception, and wireless teleoperation.*

---

## 📌 **Overview**

**TALUS** is a modular, low-cost robotic arm designed as an academic platform for experimenting with:

* Actuator control (steppers and servos)
* Embedded electronics
* Computer vision for object classification
* Wireless communication (Wi-Fi)
* Teleoperation interfaces

The project aims to bridge the gap between theoretical robotics education and hands-on experimentation by providing a reproducible, accessible system for universities with limited laboratory resources.

---

## 🎯 **Project Goal**

To develop a functional **object-classification system** (color + geometric shape) integrated into a **teleoperated robotic arm**, using accessible hardware and open-source tools.

---

## 🧠 **Motivation**

Many engineering programs struggle to offer integrated robotic systems that combine perception, control, and teleoperation in a single platform.
TALUS addresses this need by providing a **replicable, modular, low-cost** system that demonstrates the full pipeline:

**image acquisition → perception → communication → actuation**.

This enables students to learn robotics through iterative, hands-on experimentation.

---

## 🏗️ **Repository Structure**

```
TALUS/
│
├── CodeVersions/
│   ├── Actuators/
│   │   ├── Stepper/
│   │   │   ├── Offline/               → Offline stepper motor control
│   │   │   ├── WiFi_Control/          → ESP32 Wi-Fi stepper module
│   │   │   └── ... future versions
│   │   └── Servo/                     → Servo control logic
│   │
│   ├── Vision/
│   │   ├── ColorShapeRecognition/     → OpenCV classification module
│   │   └── Experiments/               → Early prototypes and tests
│   │
│   ├── Teleoperation/
│   │   ├── WebSocket_Interface/       → Real-time control UI
│   │   └── Serial_Control/
│   │
│   └── Integration/
│       ├── TALUS_V2/
│       └── TALUS_V3.1/
│
├── Docs/
│   ├── CAD/                           → 3D models of the arm
│   ├── Electronics/                    → Schematics and wiring diagrams
│   └── Architecture/                   → System overview diagrams
│
├── Results/
│   └── PerformanceTests/
│
└── README.md
```

---

## 🔧 **System Components**

### **1. Mechanics**

* 4-DOF arm
* Low-cost, modular design
* Optimized for teleoperation and lightweight pick-and-place tasks

### **2. Electronics**

* ESP32 / Arduino microcontrollers
* A4988 / TMC stepper drivers
* AS5600 magnetic encoders
* 12V/5V power system
* Multiplexers for multi-sensor setups

### **3. Actuator Control**

Includes modules for:

* **Stepper Offline** (direct STEP/DIR control)
* **Wi-Fi Stepper Control** (ESP32 web server)
* **Closed-loop Stepper Control** (AS5600 feedback)
* **Servo Control** (standard / proportional / custom modes)

### **4. Computer Vision**

* Implemented with Python + OpenCV
* HSV segmentation
* Color and geometric-shape detection (circle, square, triangle)
* Wireless communication to TALUS controller

### **5. Teleoperation**

* Web UI (WebSockets)
* Real-time control of position and movement
* Optional serial control

## 📊 **Expected Performance**

* ≥ **85%** classification accuracy
* < **500 ms** latency from detection → actuation
* < **5%** mechanical failure rate in pick-and-place tasks
* Stable Wi-Fi communication
* Fully replicable using off-the-shelf components

---

## 🗺️ **Roadmap**

* [ ] Closed-loop control for all axes (AS5600 integration)
* [ ] ROS2 teleoperation bridge
* [ ] Advanced web interface
* [ ] Improved vision heuristics / lightweight ML
* [ ] Full reproducibility guide

---

## 👤 **Author**

*Joel Adolfo Florez Molinares*

Mechatronics Engineering Student – Institución Universitaria de Barranquilla (IUB)

GitHub: **@jflorezm-git**

---

