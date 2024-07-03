# DIY-3D-Printed-Rotating-Display-Table
DIY 3D Printed Rotating Display Table

# DIY 3D Printed Rotating Display Table

Welcome to the DIY 3D Printed Rotating Display Table project! This guide will take you through the steps to create your very own rotating display table, perfect for showcasing 3D printed models, collectibles, or products. We'll cover everything from gathering supplies, 3D printing parts, programming the Arduino, and assembling the final product. Let's get started!

## Table of Contents

1. [Introduction](#introduction)
2. [Supplies](#supplies)
3. [Step 1: 3D Print the Components](#step-1-3d-print-the-components)
4. [Step 2: Upload the Arduino Code](#step-2-upload-the-arduino-code)
5. [Step 3: Assembling the Display Table](#step-3-assembling-the-display-table)

## Introduction

The DIY 3D Printed Rotating Display Table is an excellent project for hobbyists, makers, and professionals alike. Using 3D printing and basic electronics, you can create a customizable display table that brings motion and style to your presentations.

## Supplies

### Electronic Components
- **Arduino Nano**: Microcontroller to control the stepper motor.
- **28BYJ-48 Stepper Motor with ULN2003 Driver**: Provides precise control for smooth rotation.
- **DC Power Plug**: Powers the Arduino Nano and the stepper motor.

### 3D Printing Materials
- **PLA Filament**: Ideal for strength and ease of use.
- **3D Printer**: Capable of printing with fine details.

### Additional Supplies
- **Jumper Wires**: For connections between components.
- **Screwdriver Set**: For assembly.
- **Hot Glue Gun or Super Glue**: Optional, for securing parts.
- **Breadboard**: Optional, for initial testing.
- **Power Supply**: Compatible with the DC power plug and Arduino Nano.

## Step 1: 3D Print the Components

First, 3D print all necessary components using your modeled parts. Ensure your printer is properly calibrated, and use the following settings for optimal results:

- **Layer Height**: 0.2 mm
- **Wall Thickness**: 1.2 mm
- **Infill Density**: 20-30%
- **Supports**: Enable if necessary

### Instructions

1. **Prepare Your 3D Printer**: Check bed leveling, clean the extruder, and load the filament.
2. **Load the 3D Models**: Import your parts into slicing software.
3. **Configure Print Settings**: Adjust settings for quality and strength.
4. **Slice the Model**: Generate the G-code for your 3D printer.
5. **Start Printing**: Print each component, monitoring the first few layers for adhesion.
6. **Post-Processing**: Remove supports and sand rough edges if needed.

## Step 2: Upload the Arduino Code

Next, program the Arduino Nano to control the stepper motor. Follow these steps:

1. **Install Arduino IDE**: Download from [here](https://www.arduino.cc/en/software).
2. **Connect the Arduino Nano**: Use a USB cable to connect to your computer.
3. **Open the Arduino IDE**: Select "Arduino Nano" as the board and the correct port.
4. **Enter the Code**: Copy the code below into a new sketch:

    ```cpp
    // Define stepper motor control pins
    #define IN1 9
    #define IN2 10
    #define IN3 11
    #define IN4 12

    // Define the steps in the sequence
    int stepSequence[8][4] = {
      {1, 0, 0, 0},
      {1, 1, 0, 0},
      {0, 1, 0, 0},
      {0, 1, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 1},
      {0, 0, 0, 1},
      {1, 0, 0, 1}
    };

    // Variables for direction and speed
    bool direction = true; // false for anti-clockwise, true for clockwise
    int speed = 5; // Speed control (1 to 10), higher value means slower speed

    void setup() {
      // Set control pins as outputs
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
    }

    void loop() {
      // Iterate through the step sequence based on direction
      if (direction) {
        for (int i = 0; i < 8; i++) {
          setStep(stepSequence[i][0], stepSequence[i][1], stepSequence[i][2], stepSequence[i][3]);
          delay(speed); // Control speed
        }
      } else {
        for (int i = 7; i >= 0; i--) {
          setStep(stepSequence[i][0], stepSequence[i][1], stepSequence[i][2], stepSequence[i][3]);
          delay(speed); // Control speed
        }
      }
    }

    void setStep(int a, int b, int c, int d) {
      digitalWrite(IN1, a);
      digitalWrite(IN2, b);
      digitalWrite(IN3, c);
      digitalWrite(IN4, d);
    }
    ```

5. **Upload the Code**: Verify and upload the code to the Arduino Nano.

## Step 3: Assembling the Display Table

Finally, assemble the components to complete your rotating display table.

### Instructions

1. **Attach the Stepper Motor to the Base**: Secure the motor using screws or brackets, ensuring alignment with the rotating platform.
2. **Connect the Stepper Motor to the ULN2003 Driver**: Plug the motor's connector into the driver board.
3. **Mount the Arduino Nano**: Secure the Nano in your 3D printed base, allowing access to the USB port.
4. **Wire the Stepper Motor Driver to the Arduino Nano**: Connect as follows:
    - IN1 (driver) to pin 9 (Arduino)
    - IN2 (driver) to pin 10 (Arduino)
    - IN3 (driver) to pin 11 (Arduino)
    - IN4 (driver) to pin 12 (Arduino)
    - GND and VCC (driver) to GND and 5V (Arduino)
5. **Connect the DC Power Plug**: Wire to the Arduino Nano and driver, matching polarity.
6. **Assemble the Rotating Platform**: Attach to the motor shaft, ensuring a tight fit.
7. **Test the Setup**: Power on and verify smooth operation. Adjust code if needed.
8. **Finalize the Assembly**: Secure all parts and reinforce with glue if necessary.

### Tips
- **Cable Management**: Keep wires organized to avoid tangling.
- **Lubrication**: Use lubrication if the platform feels stiff.
- **Ventilation**: Ensure adequate ventilation to prevent overheating.

Congratulations! You've completed your DIY 3D Printed Rotating Display Table. Enjoy showcasing your creations with smooth, controlled rotations!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

Thank you to the open-source community and all contributors who helped make this project possible.
