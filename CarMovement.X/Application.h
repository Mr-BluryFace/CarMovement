/* 
 * File:   Application.h
 * Author: BluryFace
 *
 * Created on November 3, 2020, 3:43 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include <stdio.h>
#include <stdlib.h>
#include "button.h"
#include "relay.h"
#include "dc_motor.h"

void forward(void);
void backward(void);
void stop(void);
void twist_right(void);
void twist_left(void);

#endif	/* APPLICATION_H */

