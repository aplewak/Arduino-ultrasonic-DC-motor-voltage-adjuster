# Arduino-ultrasonic-DC-motor-voltage-adjuster
Arduino embedded system project

Arduino based program that completes the following tasks:

parts:
arduino board
16 jumper wires
resistor diode
piezo 
rgb led (4 pin)
DC motor
ultrasonic sensor (3 pin)

The following code within the loop :

Detection from 0 inches to >=15 inches

 state : 0 -3 inches
    - 0 inches representing a stop state 
    - red light is produced on 4 pin rbg led
    - DC motor is reduced to a stop
    - piezo chimes in at its highest frequency
    - ultrasonic sensor pings back at highest frequency detecting it had detected an object 0-3 inches away
    
 
 state : <3 <= 14 inches
    - dynamically reduce or increased speeds depending on object distance
    - orange light is transitioned on 4 pin rbg led
    - DC motor speed is adjusted dynamically but not haulted nor full power generated through it.
    - piezo chimes in at its medium frequency detecting object in distance 
    - ultrasonic sensor pings back at medium frequency detecting it had detected an object 3-14 inches away
 
 state : >=15 inches
    - transitions into highest speed option
    - green light is transitioned on 4 pin rbg led
    - DC motor speed is adjusted dynamically until full power is generated.
    - piezo does not chimes in as there are no obstacles in its way
    - ultrasonic sensor pings back at lowest frequency detecting it had no obstructions in its way   
    
    
    
    
** all these components worked dynamically where any actions/obstructions were handled by jumping into the designed state/loop
    depending on distance. Distance was the main dependancy within this project while coding.
