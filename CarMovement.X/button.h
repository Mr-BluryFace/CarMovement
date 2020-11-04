/* 
 * File:   button.h
 * Author: BluryFace
 *
 * Created on November 3, 2020, 3:30 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "mcal_gpio.h"

typedef struct{
    unsigned int port_name: 4;
    unsigned int pin : 3;           
    unsigned int btn_status : 1;
}btn_t;

typedef enum{
    BUTTON_NOT_PRESSED,
    BUTTON_PRESSED           
}btn_status;

ret_status btn_config(btn_t *button);
ret_status btn_read_value(btn_t *button, btn_status *status);

#endif	/* BUTTON_H */

