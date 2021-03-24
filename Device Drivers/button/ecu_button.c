/* 
 * File:   ecu_button.c
 * Author: Ahmed khaled
 *
 * Created on March 21, 2021, 9:20 PM
 */

#include <stdio.h>

#include "ecu_button.h"

/**
 * 
 * @param btn
 * @return 
 */
ret_status button_initialize(button_t *btn){
    ret_status ret = R_NOK;
    if((NULL == btn) || (btn->port_name > PORT_MAX_NUMBERS-1) || 
            (btn->pin > PORT_PIN_MAX_NUMBERS-1)){
        return ret;
    }
    else{
        gpio_pin_direction_initialize(btn->port_name, btn->pin, DIRECTION_INPUT);
        ret = R_OK;
    }
    return ret;
}

/**
 * 
 * @param btn
 * @return 
 */
ret_status button_get_status(button_t *btn, button_status *btn_status){
    ret_status ret = R_NOK;
    if((NULL == btn) || (btn->port_name > PORT_MAX_NUMBERS-1) || 
            (btn->pin > PORT_PIN_MAX_NUMBERS-1)){
        return ret;
    }
    else{
        gpio_pin_read_value(btn->port_name, btn->pin, btn_status);
        btn->button_status = *btn_status;
        ret = R_OK;
    }
    return ret;
}