/* 
 * File:   ecu_dc_motor.c
 * Author: Ahmed khaled
 *
 * Created on March 23, 2021, 2:44 AM
 */

#include <stdio.h>

#include "ecu_dc_motor.h"


/**
 * 
 * @param dc_motor
 * @return 
 */
ret_status dc_motor_initialize (dc_motor_t *dc_motor ){
    ret_status ret = R_NOK;
    if (dc_motor == NULL){
        return ret;
    }
    else {
    
        relay_initialize( & (dc_motor->relay1));
        relay_initialize( & (dc_motor->relay2));
        ret=R_OK;
    }
    return ret ;
};

/**
 * 
 * @param dc_motor
 * @return 
 */
ret_status dc_motor_rotate_right(dc_motor_t *dc_motor ){
    ret_status ret = R_NOK;
    if (dc_motor == NULL){
        return ret;
    }
    else {
    
        relay_turn_on (& (dc_motor->relay1));
        relay_turn_off(& (dc_motor->relay2));
        ret=R_OK;
    }
    return ret ;

};

/**
 * 
 * @param dc_motor
 * @return 
 */
ret_status dc_motor_rotate_left (dc_motor_t *dc_motor ){
    ret_status ret = R_NOK;
    if (dc_motor == NULL){
        return ret;
    }
    else {
    
        relay_turn_off(& (dc_motor->relay1));
        relay_turn_on (& (dc_motor->relay2));
        
        ret=R_OK;
    }
    return ret ;

};

/**
 * 
 * @param dc_motor
 * @return 
 */
ret_status dc_motor_rotate_stop (dc_motor_t *dc_motor ){
    ret_status ret = R_NOK;
    if (dc_motor == NULL){
        return ret;
    }
    else {
    
        relay_turn_off(& (dc_motor->relay1));
        relay_turn_off(& (dc_motor->relay2));
        ret=R_OK;
    }
    return ret ;

};