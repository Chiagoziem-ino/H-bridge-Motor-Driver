#include <avr/io.h> 
#include <avr/interrupt.h> 
#include "gpio.h"

void IoConfig(void)
{
    /*configure output pins*/
    DDRB |= MOTOR_DRIVER_PINS_MASK;

    PORTB = ((PORTB & (~MOTOR_DRIVER_PINS_MASK)) |
            MOTOR_DRIVER_OFF_POSITION);

    /*configure input pins*/
    DDRD &= ~(1U<<PD2);
    DDRD &= ~(1U<<PD6);
    DDRD &= ~(1U<<PD3);

    PORTD |= (1U<<PD2);
    PORTD |= (1U<<PD6);
    PORTD |= (1U<<PD3);

    /*configure external pin interrupts on PD3 and PD2*/
    EICRA = EICRA_FALLING_EDGE_INTERRUPT_ON_BOTH_INT1_AND_INT0;
    EIMSK = EIMSK_EXT_INTERRUPT_REQUEST_ENABLE_ON_BOTH_INT1_AND_INT0;
    EIFR |= EIFR_CLEAR_PENDING_INT_INTERRUPTS;

    DDRB |= (1U<<0);
    PORTB &= ~(1U<<0);
}

//ISR for counter-clockwise drive
ISR (INT1_vect)
{
    //check if a motor-off command is present 
    if (!(PIND & (1U << MOTOR_OFF_COMMAND_PIN)))
    {

    }
    else 
    {
        //turn off motor first 
        PORTB = ((PORTB & (~MOTOR_DRIVER_PINS_MASK)) |
                MOTOR_DRIVER_OFF_POSITION);

        //put the motor in counter-clockwise drive
        PORTB = ((PORTB & (~MOTOR_DRIVER_PINS_MASK)) |
                MOTOR_DRIVER_COUNTER_CLOCKWISE_DRIVE);
    }
    
}

//ISR for clockwise drive
ISR (INT0_vect)
{
    //check if a motor-off command is present 
    if (!(PIND & (1U << MOTOR_OFF_COMMAND_PIN)))
    {

    }
    else 
    {
        //turn off motor first 
        PORTB = ((PORTB & (~MOTOR_DRIVER_PINS_MASK)) |
                MOTOR_DRIVER_OFF_POSITION);
        
        //put the motor in clockwise drive
        PORTB = ((PORTB & (~MOTOR_DRIVER_PINS_MASK)) |
                MOTOR_DRIVER_CLOCKWISE_DRIVE);
    }
    
}