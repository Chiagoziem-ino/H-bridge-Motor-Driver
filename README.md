This program controls a H-bridge DC motor driver using the ATmega328P microcontroller

The intended pin mappings are as follows:

Reverse Drive Switch -> PD3
Forward Drive Switch -> PD2 
Motor Off Switch -> PD6

For the MOSFETs according to the diagram below: 
![alt text](image.png)

A -> PB5
B -> PB4
c -> PB3
D -> PB2

Whenever any of the switches is pressed, the corresponding command is carried out by the microcontroller.



Additional Information:
-----------------------
 
A H-bridge motor driver makes this possible by using switches (electronic or manual) to control the direction in which current is flowing through the motor.
Correspondingly, the direction of the motor rotation changes. 

The circuit shown below is a H-bridge circuit that uses electronic switches- transistors (MOSFETs in this case).
One caution to be taken is that the transistors A and C must not be ON at the same time. Similarly, transistors B and D must not be ON at the same time, otherwise
there will be an electrical breach between the positive and negative terminals of the supply. 

To avoid this scenario, the signals given to the transistors must be given carefully, with only A and D ON in forward drive, and only B and C ON in reverse drive. 

Also, driving a motor in one direction and suddenly reversing it will cause a huge current spike that can damage components.

Note that flyback Diodes are included in the circuit to allow the inductance of the motor fully dissipate its energy whenever there is a current change.