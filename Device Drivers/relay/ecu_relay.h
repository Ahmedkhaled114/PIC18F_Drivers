/* 
 * File:   ecu_relay.h
 * Author: Ahmed khaled
 *
 * Created on March 23, 2021, 1:45 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H


#include "../../mcal/gpio/mcal_gpio.h"

/* Section : Macro Declaration */

/* Section : Data Type Definition */
typedef enum {
       RELAY_ON ,
       RELAY_OFF        
} relay_status ;


typedef struct {
    uint8_t port_name    : 4;
    uint8_t pin          : 3;
    uint8_t relay_status : 1;
} relay_t ;

/*  Section : Function Declaration */

ret_status relay_initialize (relay_t *relay );
ret_status relay_turn_on    (relay_t *relay );
ret_status relay_turn_off   (relay_t *relay );

#endif	/* ECU_RELAY_H */

