/* 
 * File:   ecu_led.c
 * Author: Ahmed khaled
 *
 * Created on March 13, 2021, 1:47 AM
 */


#include <stdio.h>

#include "ecu_led.h"

ret_status led_initalize(led_t *led){
    ret_status ret = R_NOK ;
    if ( (NULL == led ) || ( led ->port_name > PORT_MAX_NUMBERS-1 ) 
            ||( led  ->pin > PORT_PIN_MAX_NUMBERS-1 ) ) {
        return ret;
    }
    else {
    
        gpio_pin_direction_initialize(led->port_name , led->pin , DIRECTION_OUTPUT);
        gpio_pin_write_value(led->port_name , led->pin , LOW );
        ret = R_OK;
    }
    
    return ret ;
    
};



ret_status led_turn_on(led_t *led){
    ret_status ret = R_NOK ;
    if ( (NULL == led ) || ( led ->port_name > PORT_MAX_NUMBERS-1 ) 
            ||( led  ->pin > PORT_PIN_MAX_NUMBERS-1 ) ) {
        return ret;
    }
    else {
    
        
        gpio_pin_write_value(led->port_name , led->pin , HIGH );
        led->led_status = LED_ON;
        ret = R_OK;
    }
    
    return ret ;
};


ret_status led_turn_off(led_t *led){
    
    ret_status ret = R_NOK ;
    if ( (NULL == led ) || ( led ->port_name > PORT_MAX_NUMBERS-1 ) 
            ||( led  ->pin > PORT_PIN_MAX_NUMBERS-1 ) ) {
        return ret;
    }
    else {
    
       
        gpio_pin_write_value(led->port_name , led->pin , LOW );
        led->led_status = LED_OFF;
        ret = R_OK;
    }
    
    return ret ;
};


ret_status led_turn_toggel(led_t *led){
    ret_status ret = R_NOK ;
    if ( (NULL == led ) || ( led ->port_name > PORT_MAX_NUMBERS-1 ) 
            ||( led  ->pin > PORT_PIN_MAX_NUMBERS-1 ) ) {
        return ret;
    }
    else {
    

        gpio_pin_toggle_value(led->port_name , led->pin );
        ret = R_OK;
    }
    
    return ret ;
};