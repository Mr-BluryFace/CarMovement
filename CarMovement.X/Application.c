/*
 * File:   Application.c
 * Author: BluryFace
 *
 * Created on November 3, 2020, 2:11 PM
 */
#include "Application.h"



motor_t motor1;
motor_t motor2;

btn_t btn_forward = {.port_name = PORTC_INDEX, .pin = PIN4, .btn_status = BUTTON_NOT_PRESSED};
btn_t btn_backward = {.port_name = PORTC_INDEX, .pin = PIN5, .btn_status = BUTTON_NOT_PRESSED};
btn_t btn_right = {.port_name = PORTC_INDEX, .pin = PIN6, .btn_status = BUTTON_NOT_PRESSED};
btn_t btn_left = {.port_name = PORTC_INDEX, .pin = PIN7, .btn_status = BUTTON_NOT_PRESSED};

unsigned int f_status = PIN_LOW;
unsigned int b_status = PIN_LOW;
unsigned int r_status = PIN_LOW;
unsigned int l_status = PIN_LOW;




main(void) {
    motor1.relay1.port_name = PORTC_INDEX;
    motor1.relay1.pin = PIN0;
    motor1.relay1.relay_status = relay_off;
    motor1.relay2.port_name = PORTC_INDEX;
    motor1.relay2.pin = PIN1;
    motor1.relay2.relay_status = relay_off;
    
    motor2.relay1.port_name = PORTC_INDEX;
    motor2.relay1.pin = PIN2;
    motor2.relay1.relay_status = relay_off;
    motor2.relay2.port_name = PORTC_INDEX;
    motor2.relay2.pin = PIN3;
    motor2.relay2.relay_status = relay_off;
    /*
    motor3.relay1.port_name = PORTC_INDEX;
    motor3.relay1.pin = PIN4;
    motor3.relay1.relay_status = relay_off;
    motor3.relay2.port_name = PORTC_INDEX;
    motor3.relay2.pin = PIN5;
    motor3.relay2.relay_status = relay_off;
    
    motor4.relay1.port_name = PORTC_INDEX;
    motor4.relay1.pin = PIN6;
    motor4.relay1.relay_status = relay_off;
    motor4.relay2.port_name = PORTC_INDEX;
    motor4.relay2.pin = PIN7;
    motor4.relay2.relay_status = relay_off;
    */
    motor_initialize(&motor1);
    motor_initialize(&motor2);
    
    btn_config(&btn_forward);
    btn_config(&btn_backward);
    btn_config(&btn_right);
    btn_config(&btn_left);
    
    while(TRUE){
        btn_read_value(&btn_forward , &f_status);
        btn_read_value(&btn_backward , &b_status);
        btn_read_value(&btn_right , &r_status);
        btn_read_value(&btn_left , &l_status);
        if(btn_forward.btn_status == BUTTON_PRESSED){
            forward();
        }else if(btn_backward.btn_status == BUTTON_PRESSED){
            backward();
        }else if(btn_right.btn_status == BUTTON_PRESSED){
            twist_right();
        }else if(btn_left.btn_status == BUTTON_PRESSED){
            twist_left();
        }else{
            stop();
        }
    }
    return(EXIT_SUCCESS);
}

void forward(void){
    motor_turn_on(&motor1);
    motor_turn_on(&motor2);
}

void backward(void){
    motor_reverse(&motor1);
    motor_reverse(&motor2);
}

void stop(void){
    motor_stop(&motor1);
    motor_stop(&motor2);
}

void twist_right(void){
    motor_turn_on(&motor2);
    motor_reverse(&motor1);
}

void twist_left(void){
    motor_reverse(&motor2);
    motor_turn_on(&motor1);
}