# Biometric-Encrypted-Smart-Door-Lock-System

## Introduction
This project aims to embed the concept of biometric encryption into an IoT-based door lock system. The system leverages biometric encryption and an apt encryption algorithm to safeguard sensitive data. Focusing on robust security, it employs fingerprint recognition to allow only authorized access, and through integration with IFTTT, it enables users to develop custom automation scenarios for smart homes or office setups.

## Project Objectives
Gain insights into the concepts of Biometric encryption, especially fingerprint data encryption through feature extraction.
Implement an IoT application and develop an instinctive understanding of the project's architecture.
Establish a connection between the hardware and software related to the project.
Deeply understand the code from both a generic application perspective and a web application perspective.

## Hardware and Software Requirements
### Hardware:
NodeMCU ESP8266 Breakout Board
GT511C3 / R307 Fingerprint Sensor
Solenoid Lock
Relay Module
Buzzer
12V Adapter
Jumper Wires
Breadboard

### Software:
Adafruit IO
Arduino IDE
Visual Studio
IFTTT
AESLib (Arduino or Python)
Fritzing
Blynk/Thinkfruit (Optional)

## Methodology
The project utilizes IoT platforms, such as Adafruit.io and IFTTT, to manage data and facilitate functionality like email alerts during unauthorized access attempts. Adafruit.io serves as a cloud service, managing data storage and retrieval while offering internet accessibility. IFTTT ("If This Then That") provides web-based services that create conditional applets, allowing notifications via email, Twitter, and Facebook.

## Novelty of the Project
The project introduces structural novelty and incorporates different hardware compared to suggested references. A key innovation is the transmission of fingerprint data from the scanner sensor module to the Adafruit.io IoT platform. This data is then encrypted using AESLib and decrypted using a key provided by the IFTTT platform for automation.

## References
The project is inspired by a variety of references, including main and secondary sources, that delve into aspects like biometric encryption, biometric data storage, fingerprint sensor data collection, and more.

