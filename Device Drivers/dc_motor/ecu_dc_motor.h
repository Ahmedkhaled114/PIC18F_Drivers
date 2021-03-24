/* 
 * File:   ecu_dc_motor.h
 * Author: Ahmed khaled
 *
 * Created on March 23, 2021, 1:45 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H


#include "../relay/ecu_relay.h"

/* Section : Macro Declaration */

/* Section : Data Type Definition */

typedef struct {
    relay_t relay1;
    relay_t relay2;
    
} dc_motor_t ;

/*  Section : Function Declaration */

ret_status dc_motor_initialize (dc_motor_t *dc_motor );
ret_status dc_motor_rotate_right(dc_motor_t *dc_motor );
ret_status dc_motor_rotate_left (dc_motor_t *dc_motor );
ret_status dc_motor_rotate_stop (dc_motor_t *dc_motor );
#endif	/* ECU_DC_MOTOR_H */

