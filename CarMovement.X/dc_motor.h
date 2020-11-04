/* 
 * File:   dc_motor.h
 * Author: BluryFace
 *
 * Created on November 4, 2020, 12:09 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H
#include "relay.h"

typedef struct{
    relay_t relay1;
    relay_t relay2;
}motor_t;

ret_status motor_initialize(motor_t *motor);
ret_status motor_turn_on(motor_t *motor);
ret_status motor_stop(motor_t *motor);
ret_status motor_reverse(motor_t *motor);

#endif	/* DC_MOTOR_H */

