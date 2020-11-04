/*
 * File:   dc_motor.c
 * Author: BluryFace
 *
 * Created on November 4, 2020, 12:09 PM
 */


#include "dc_motor.h"

ret_status motor_initialize(motor_t *motor){
    ret_status ret = R_NOK;
    if(NULL == motor){
        return ret;
    }
    else{
        relay_initialize(&(motor->relay1));
        relay_initialize(&(motor->relay2));
        ret = R_OK;
    }
    return ret;
}

ret_status motor_turn_on(motor_t *motor){
    ret_status ret = R_NOK;
    if(NULL == motor){
        return ret;
    }else{
        relay_turn_on(&(motor->relay1));
        relay_turn_off(&(motor->relay2));
        ret = R_OK;
    }
    return ret;
}

ret_status motor_stop(motor_t *motor){
    ret_status ret = R_NOK;
    if(NULL == motor){
        return ret;
    }else{
        relay_turn_off(&(motor->relay1));
        relay_turn_off(&(motor->relay2));
        ret = R_OK;
    }
    return ret;
}

ret_status motor_reverse(motor_t *motor){
    ret_status ret = R_NOK;
    if(NULL == motor){
        return ret;
    }else{
        relay_turn_off(&(motor->relay1));
        relay_turn_on(&(motor->relay2));
        ret = R_OK;
    }
    return ret;
}