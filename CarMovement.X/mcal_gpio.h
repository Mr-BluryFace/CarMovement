/* 
 * File:   mcal_gpio.h
 * Author: BluryFace
 *
 * Created on November 3, 2020, 2:01 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H

#include "std_types.h"
#include "../../pic/include/proc/pic18f46k20.h"


#define PORT_MAX_NUMBERS            5U
#define PORT_PIN_MAX_NUMBERS        8U
#define PORT_DIRECTION_INPUT        0xFFU
#define PORT_DIRECTION_OUTPUT       0x00U
#define PIN_MASK_VALUE              1U
#define PORT_MASK_VALUE             0XFF

/* Section: Macro Functions Declarations */
#define CLEAR_BIT(REGISTER,BIT_POS)  (REGISTER &= ~(PIN_MASK_VALUE << BIT_POS))
#define SET_BIT(REGISTER,BIT_POS)    (REGISTER |= (PIN_MASK_VALUE << BIT_POS))
#define TOGGLE_BIT(REGISTER,BIT_POS) (REGISTER ^= (PIN_MASK_VALUE << BIT_POS))
#define READ_BIT(REGISTER,BIT_POS)   ((REGISTER >> BIT_POS) & PIN_MASK_VALUE)

#define CLEAR_PORT(REGISTER)    (REGISTER &= ~PORT_MASK_VALUE)
#define SET_PORT(REGISTER)      (REGISTER |= PORT_MASK_VALUE)
#define TOGGLE_PORT(REGISTER)   (REGISTER ^= PORT_MASK_VALUE)

/* Section: Data Type Definitions */
typedef enum{
    PIN_LOW,
    PIN_HIGH        
}pin_logic_t;

typedef enum{
    DIRECTION_OUTPUT,
    DIRECTION_INPUT        
}direction_t;

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,    
    PIN4,
    PIN5,
    PIN6,    
    PIN7
}pin_index;

typedef enum{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,    
    PORTE_INDEX
}port_index;

ret_status gpio_pin_direction_intialize(port_index port, pin_index pin, direction_t direction);
ret_status gpio_pin_write_value(port_index port, pin_index pin, pin_logic_t pin_value);
ret_status gpio_pin_read_value(port_index port, pin_index pin, pin_logic_t *logic);

#endif	/* MCAL_GPIO_H */

