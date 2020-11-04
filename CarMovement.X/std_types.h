/* 
 * File:   std_types.h
 * Author: BluryFace
 *
 * Created on November 3, 2020, 2:44 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#define _XTAL_FREQ 4000000UL
#include <xc.h>

#define ZERO_INIT 0
#define TRUE  1
#define FALSE 0

typedef enum{
    R_NOK,
    R_OK
}ret_status;

#endif	/* STD_TYPES_H */

