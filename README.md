# IOT Based Digital Keypad Door Lock System

# Arduino-Based Combinational Lock System

## Problem Statement
Traditional physical keys have long been the standard for securing doors and other access points. However, they present several issues, including the risk of being lost, stolen, or duplicated without authorization. These vulnerabilities can lead to unauthorized access, compromising the security of homes, offices, and other secured areas. Additionally, managing multiple keys can be cumbersome and inefficient, especially in environments with many secure points.

## Goal
The goal of this project is to develop a digital lock system that enhances security and convenience by eliminating the need for physical keys. This system leverages an Arduino UNO microcontroller to control a digital combination lock, where users can enter a code via a keypad. The system aims to provide:

- **Security:** By requiring a specific combination to unlock, the system reduces the risks associated with physical keys.
- **Convenience:** Users no longer need to carry physical keys, and the system provides immediate feedback through an LCD screen.
- **Reliability:** The use of a servo motor ensures precise and consistent locking and unlocking actions.

## Components

- **Arduino UNO:**  
  The central microcontroller that manages the entire system. It processes input from the keypad, controls the LCD screen, and operates the servo motor.

- **Keypad:**  
  A numeric keypad serves as the input device for entering the lock combination. It is simple to use and allows for a secure way to input the access code.

- **LCD Screen:**  
  This component provides real-time feedback to the user. It displays messages such as "Door is Open, Waiting..." when the correct combination is entered or "Wrong Password" when the wrong code is inputted. This helps users understand the system’s status instantly.

- **Servo Motor:**  
  The servo motor physically operates the lock mechanism. When the correct code is entered, the servo rotates to unlock the door. It is reliable and precise, ensuring that the locking mechanism works effectively every time.

- **Power Supply:**  
  The system is powered by a standard 5V power supply, sufficient to run the Arduino UNO and connected components.

## Assembly Instructions

1. **Hardware Setup:**
   - Connect the keypad to the Arduino UNO, ensuring each key is properly mapped to the correct pin.
   - Attach the LCD screen, making sure it is wired to display feedback correctly.
   - Connect the servo motor to the locking mechanism and ensure it is properly wired to the Arduino for control.

2. **Software Setup:**
   - Install the Arduino IDE and necessary libraries, such as those for the keypad and LCD.
   - Write or upload the provided sketch to the Arduino UNO, configuring it to handle the input, output, and locking logic.

3. **Operation:**
   - Enter the predefined code on the keypad to unlock the system.
   - The servo motor will rotate if the correct code is entered, unlocking the door. The LCD screen will display success or error messages based on the code entered.

## Benefits
- **Enhanced Security:** The digital system eliminates risks associated with lost or stolen keys, offering a more secure alternative.
- **User-Friendly Interface:** The keypad and LCD screen make the system easy to use, with clear and immediate feedback.
- **Reliable Locking Mechanism:** The servo motor ensures that the lock operates smoothly and consistently, enhancing the system's reliability.

## Documents Included:
- **AcmeGrade Digital Keypad.pptx**
- **IOT Based Digital Keypad Door Lock System Report.pdf**
- **Divyansh Marwaha_Internship Completion.jpg**
- **Divyansh Marwaha_Training Completion.jpg**
- **Password based Door lock.ino**
## Link of Tinkercad Simulation:
- **https://www.tinkercad.com/things/4LuaQLVF4CT-password-based-door-lock?sharecode=vSy1JrQtFz2aqPvQUBLDyM8_5uFFewDRSZ_N5SV2Qz4**
