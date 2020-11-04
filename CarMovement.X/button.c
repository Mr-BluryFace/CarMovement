/*
 * File:   button.c
 * Author: BluryFace
 *
 * Created on November 3, 2020, 3:30 PM
 */


#include "button.h"

ret_status btn_config(btn_t *button){
    ret_status ret = R_NOK;
    if((NULL == button) || (button->port_name > PORT_MAX_NUMBERS-1) || 
            (button->pin > PORT_PIN_MAX_NUMBERS-1)){
        return ret;
    }
    else{
        gpio_pin_direction_intialize(button->port_name, button->pin, DIRECTION_INPUT);
        ret = R_OK;
    }
    return ret;
}

ret_status btn_read_value(btn_t *button, btn_status *status){
    ret_status ret = R_NOK;
    if((NULL == button) || (button->port_name > PORT_MAX_NUMBERS-1) || 
            (button->pin > PORT_PIN_MAX_NUMBERS-1)){
        return ret;
    }
    else{
        gpio_pin_read_value(button->port_name, button->pin, status);
        button->btn_status = *status;
        ret = R_OK;
    }
    return ret;
}