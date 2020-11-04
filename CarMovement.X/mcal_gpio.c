/*
 * File:   mcal_gpio.c
 * Author: BluryFace
 *
 * Created on November 3, 2020, 3:03 PM
 */


#include "mcal_gpio.h"

/* Reference to the Data Direction Control Registers */
static volatile unsigned int *tris_register[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
static volatile unsigned int *lat_register[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/* Reference to the Port Status Register  */
static volatile unsigned int *port_register[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

ret_status gpio_pin_direction_intialize(port_index port, pin_index pin, direction_t direction){
    ret_status ret = R_NOK;
    if(pin > PORT_PIN_MAX_NUMBERS-1 || pin < ZERO_INIT){
        return ret;
    }else{
        switch(direction){
            case DIRECTION_OUTPUT :
                /* Clear the desired bit as indication to be DIRECTION_OUTPUT */
                CLEAR_BIT(*tris_register[port], pin); break;
            case DIRECTION_INPUT : 
                /* Set the desired bit as indication to be DIRECTION_INPUT */
                SET_BIT(*tris_register[port], pin); break;
            default : return R_NOK;
        }
        return ret;
    }
}

ret_status gpio_pin_write_value(port_index port, pin_index pin, pin_logic_t pin_value){
    ret_status ret = R_NOK;
    if(pin > PORT_PIN_MAX_NUMBERS-1  || pin < ZERO_INIT){
        return ret;
    }else{
        switch(pin_value){
            case PIN_LOW :
                /* Clear the desired bit as indication to be 0v */
                CLEAR_BIT(*lat_register[port], pin); break;
            case PIN_HIGH : 
                /* Set the desired bit as indication to be 5v */
                SET_BIT(*lat_register[port], pin); break;
            default : return R_NOK;
        }
        return ret;
    }
}

ret_status gpio_pin_read_value(port_index port, pin_index pin, pin_logic_t *logic){
    ret_status ret = R_NOK;
    if(pin > PORT_PIN_MAX_NUMBERS-1 || NULL == logic){
        return ret;
    }
    else{
        *logic = READ_BIT(*port_register[port], pin);
        ret = R_OK;
    }
    return ret;
}