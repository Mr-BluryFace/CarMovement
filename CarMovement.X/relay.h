/* 
 * File:   relay.h
 * Author: BluryFace
 *
 * Created on November 4, 2020, 10:47 AM
 */

#ifndef RELAY_H
#define	RELAY_H

#include "mcal_gpio.h"

typedef struct{
    unsigned int port_name: 4;
    unsigned int pin : 3 ;
    unsigned int relay_status : 1  ;      
}relay_t;


typedef enum{
    rely_on,
    relay_off        
}relay_status;



ret_status relay_initialize(relay_t *relay);
ret_status relay_turn_on(relay_t *relay);
ret_status relay_turn_off(relay_t *relay);

#endif	/* RELAY_H */

