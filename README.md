# ESP32 Environmental Monitoring with ThingSpeak

**Project:** ESP32 to ThingSpeak  
**Student:** Tariq Abualsoud  
**Student ID:** 12217122

## Overview

This project demonstrates an Internet of Things (IoT) environmental monitoring system using an **ESP32 microcontroller**, a **DHT22 temperature and humidity sensor**, and the **ThingSpeak cloud platform**. The ESP32 collects simulated environmental measurements in **Wokwi**, connects to Wi-Fi, and periodically uploads the readings to ThingSpeak for storage and visualization.

The goal is to illustrate the complete data flow from sensor acquisition to a remotely accessible cloud dashboard.

## Project Objectives

- Read temperature and relative humidity using the DHT22 sensor.
- Connect the ESP32 to a Wi-Fi network.
- Validate sensor readings before transmission.
- Upload measurements to separate ThingSpeak channel fields.
- Display changes over time using cloud-based graphs.
- Verify successful operation through simulation and Serial Monitor output.

## Technologies and Components

| Component / Service | Purpose |
| --- | --- |
| ESP32 | Reads sensor data and manages Wi-Fi communication |
| DHT22 | Measures temperature and relative humidity |
| Wokwi | Simulates the circuit and microcontroller |
| Arduino framework | Provides the ESP32 programming environment |
| Wi-Fi | Connects the ESP32 to ThingSpeak |
| ThingSpeak | Stores measurements and visualizes their trends |
| Serial Monitor | Displays readings and diagnostic messages |

## System Architecture

```text
    DHT22 Sensor
  Temperature & Humidity
          |
          v
         ESP32
   Read and validate data
          |
          v
         Wi-Fi
    Transmit readings
          |
          v
       ThingSpeak
   Store and plot data
```

## ThingSpeak Channel Configuration

The ThingSpeak channel uses two fields:

| Field | Measurement | Unit |
| --- | --- | --- |
| Field 1 | Temperature | °C |
| Field 2 | Relative Humidity | % |

Measurements are transmitted approximately **every 20 seconds**. Successful uploads create new entries in the ThingSpeak channel, which are displayed on separate time-series charts.

## How the System Works

1. The ESP32 starts and establishes a Wi-Fi connection.
2. The DHT22 sensor provides temperature and humidity measurements.
3. The program checks whether the sensor readings are valid.
4. The ESP32 transmits both values to their respective ThingSpeak fields.
5. The system repeats the process after the configured interval (approximately 20 seconds).
6. ThingSpeak records the new data and updates the graphs.

## Running the Simulation

1. Open the [Wokwi project](https://wokwi.com/projects/478940198728415233).
2. Review the ESP32 and DHT22 circuit connections and the Arduino code.
3. Start the simulation in Wokwi.
4. Open the **Serial Monitor** to inspect sensor readings and transmission messages.
5. Open the [ThingSpeak channel](https://thingspeak.mathworks.com/channels/3551365) to view the temperature and humidity graphs.

> **Note:** Uploading to ThingSpeak requires a configured channel and valid write API key in the ESP32 code. Never publish private API keys or Wi-Fi credentials in a public repository.

## Results and Evidence

The project results are documented using screenshots of the following:

1. **Wokwi circuit:** ESP32 and DHT22 wiring within the simulator.
2. **ThingSpeak graphs:** Temperature and relative humidity data visualized in the cloud dashboard.
3. **Successful Serial Monitor output:** Sensor readings and successful data transmission messages.




<img width="1902" height="910" alt="image" src="https://github.com/user-attachments/assets/90eb51cc-286b-4a78-aff9-c45390053c3d" />
<img width="464" height="451" alt="image" src="https://github.com/user-attachments/assets/7b6d8ab1-a7c8-4ab0-a7c8-f4dc35bbc955" />
<img width="937" height="737" alt="image" src="https://github.com/user-attachments/assets/8a8b6d92-87b2-46a7-863d-c7cbbec2e81b" />

  
 

## Learning Outcomes

This project develops practical understanding of sensor interfacing, ESP32 programming, wireless connectivity, periodic data transmission, cloud-based IoT data logging, and time-series visualization.

## Project Links

- [Wokwi Simulation](https://wokwi.com/projects/478940198728415233)
- [ThingSpeak Dashboard](https://thingspeak.mathworks.com/channels/3551365)

---

**Prepared by:** Tariq Abualsoud  
**Student ID:** 12217122  
**Project:** ESP32 to ThingSpeak
