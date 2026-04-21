#include <avr/interrupt.h> 
#include "gpio.h"

int main (void)
{
    //disable global interrupts 
    cli();

    //initialize input and output pins 
    IoConfig();

    //enable global interrupts 
    sei();

    while (1)
    {
        

        //poll for Off command
        if (!(PIND & (1U<<MOTOR_OFF_COMMAND_PIN)))
        {
            //disable global interrupts
            cli();

            //turn off motor
            PORTB = ((PORTB & (~MOTOR_DRIVER_PINS_MASK)) |
                    MOTOR_DRIVER_OFF_POSITION);

            //enable global interrupts 
            sei();            
        }
    
    }

    return 0;
}