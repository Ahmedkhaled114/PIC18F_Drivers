/* 
 * File:   ecu_led.h
 * Author: Ahmed khaled
 *
 * Created on March 13, 2021, 1:46 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

#include "../../mcal/gpio/mcal_gpio.h" 

/* Section: Macro Declarations */

/* Section: Data Type Definitions */
typedef enum{
    LED_OFF,
    LED_ON
}led_status;

typedef struct{
    uint8_t port_name : 4;
    uint8_t pin : 3; 
    uint8_t led_status : 1;
}led_t;



/* Section : Function declarations */

ret_status led_initalize(led_t *led);
ret_status led_turn_on(led_t *led);
ret_status led_turn_off(led_t *led);
ret_status led_turn_toggel(led_t *led);


 
#endif	/* ECU_LED_H */

