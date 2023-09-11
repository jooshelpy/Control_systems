# Task Description: Arduino Motor Control with Exponential Smoothing

## CytronMDD10A

The Cytron MDD10A is a motor driver module developed by Cytron Technologies.It is the dual-channel version designed to drive 2 brushed DC motors with a high current of up to 10A continuously. MDD10A also supports locked-antiphase and sign-magnitude PWM signal. It is designed to control the motion of DC motors, making it a key component in robotics, automation, and other projects that involve motor control.

## Objective

The objective of this task is to create an Arduino sketch for controlling a DC motor's speed and direction. The sketch employs a simple exponential smoothing filter to smoothly adjust the motor's speed.

## Prerequisites

Before attempting this task, you will need the following components:

- An Arduino board (e.g., Arduino Uno).
- A motor driver circuit to control the motor.
- A DC motor.
- Two GPIO pins on the Arduino for motor speed and direction control (e.g., pins 8 and 9).

## Task Details

### Motor Control

The Arduino sketch will control the motor in two directions: clockwise and counterclockwise.

1. **Clockwise Direction**: The motor will rotate clockwise, gradually increasing in speed up to the maximum value.

2. **Counterclockwise Direction**: After reaching the maximum speed in the clockwise direction, the motor will change direction and rotate counterclockwise. It will again increase in speed up to the maximum value.

### Exponential Smoothing Filter

A simple exponential smoothing filter is applied to adjust the motor speed smoothly. The smoothing factor (`smoothingFactor`) controls the rate of smoothing. The formula used for smoothing is:

                filteredSpeed = smoothingFactor * filteredSpeed + (1 - smoothingFactor) * currentSpeed
