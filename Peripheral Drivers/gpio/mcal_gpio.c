
/* 
 * File:   gpio_led.c
 * Author: Ahmed khaled
 *
 * Created on March 13, 2021, 1:47 AM
 */

#include <stdio.h>

#include"mcal_gpio.h"

/* Reference to the Data Direction Control Registers */
static volatile uint8_t *tris_register[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
static volatile uint8_t *lat_register[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/* Reference to the Port Status Register  */
static volatile uint8_t *port_register[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/**
 * @brief Initialize all the ports to the default states (DIRECTION_INPUT). 
 * @param port_numbers : The available Physical port numbers at the MCU -> PORT_MAX_NUMBERS
 * @return Status of the function 
 *         (R_OK) : The function done successfully
 */
ret_status gpio_port_default_init(uint8_t port_numbers){
    ret_status ret = R_NOK;
    uint8_t l_counter = ZERO_INIT;
    for(l_counter=ZERO_INIT; l_counter<PORT_MAX_NUMBERS-1; l_counter++){
        /* Write to all (Data Direction Control Registers) -> DIRECTION_INPUT */
        *tris_register[l_counter] = PORT_DIRECTION_INPUT;
    }
    ret = R_OK;
    return ret;
}


/**
 *                               gpio_pin_direction_initialize
 * 
 * @param port --> to select the port   
 * @param pin --> to selectnThe pin number -> PIN0, PIN1, PIN2, ....
 * @param direction --> The pin direction status ->(DIRECTION_OUTPUT,DIRECTION_INPUT )
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */

ret_status gpio_pin_direction_initialize(port_index port , pin_index pin ,direction_t direction  ){

ret_status ret = R_NOK;
            /* Validating the pin number */
    if(pin > PORT_PIN_MAX_NUMBERS-1 || pin < ZERO_INIT){
        return ret;
    }
    else{
        switch(direction){
            case DIRECTION_OUTPUT : /*pin will = 0  -->DIRECTION_OUTPUT */       
                /**tris_register[port] &= ~(1 << pin);*/
                
                CLEAR_BIT (*tris_register[port] , pin ); break;
                
            case DIRECTION_INPUT :  /*pin will  = 1 -->DIRECTION_INPUT*/
                /**tris_register[port] |= (1 << pin);*/
                
                SET_BIT (*tris_register[port] , pin); break;
                
            default : return R_NOK;
        }
    }
    return ret;


};
/**
 *                               gpio_pin_get_direction_status
 *    Get the direction of a specific pin -> (DIRECTION_INPUT) or (DIRECTION_OUTPUT)
 * @param port --> to select the port   
 * @param pin --> to selectnThe pin number -> PIN0, PIN1, PIN2, ....
 * @param direction --> to use pin as input or output by using (DIRECTION_OUTPUT,DIRECTION_INPUT )
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_pin_get_direction_status(port_index port , pin_index pin , direction_t *direction){
    
    ret_status ret = R_NOK ;
    if ( pin > PORT_PIN_MAX_NUMBERS -1 || pin < ZERO_INIT) {
       return ret ;   
      }
    else {
   /* Read the direction status of the (pin) -> (DIRECTION_INPUT) or (DIRECTION_OUTPUT) */
        *direction = READ_BIT(*tris_register[port], pin);
        ret = R_OK ;
    }
    return ret ;
};
/**
 *                              gpio_pin_write_value
 * 
 * @param port --> to select the port PORTA_INDEX ,PORTB_INDEX ,PORTC_INDEX ....
 * @param pin --> to selectnThe pin number -> PIN0, PIN1, PIN2, ....
 * @param logic --> to write logic one or logic zero by using (LOW,HIGH )
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_pin_write_value(port_index port , pin_index pin , logic_t logic){
    
    ret_status ret = R_NOK ; 
    if ( pin > PORT_PIN_MAX_NUMBERS -1 || pin < ZERO_INIT ){
        return ret ;
    }
     else{
        switch(logic){
            case LOW : /*pin will be low */
                
                CLEAR_BIT(*lat_register[port], pin);
                ret= R_OK;
                break;
                
            case HIGH : /*pin will be  HIGH */
                
                SET_BIT(*lat_register[port], pin); break;
                ret= R_OK;
                break;
            default : return R_NOK;
        }
    }
    return ret;     
  };
/**
 *     Read the logic or the voltage applied on a specific pin
 * @param port  --> to select the port PORTA_INDEX ,PORTB_INDEX ,PORTC_INDEX ....
 * @param pin   --> to selectnThe pin number -> PIN0, PIN1, PIN2, ....
 * @param logic --> to check the pin if  logic one or logic zero
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_pin_read_value(port_index port , pin_index pin , logic_t *logic){
   
    ret_status ret = R_NOK ; 
    if ( pin > PORT_PIN_MAX_NUMBERS -1 || NULL ==logic ){
        return ret ;
    }
     else{
          *logic = READ_BIT(*port_register[port] , pin);
          ret = R_OK;
     }
    return ret ; 
    
};

/**
 *                Change the logic on a specific pin
 * @param port --> to select the port PORTA_INDEX ,PORTB_INDEX ,PORTC_INDEX ....
 * @param pin  --> to selectnThe pin number -> PIN0, PIN1, PIN2, ....
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_pin_toggle_value(port_index port , pin_index pin ){
    ret_status ret = R_NOK ; 
    if ( pin > PORT_PIN_MAX_NUMBERS -1 || pin < ZERO_INIT ){
        return ret ;
    }
     else{    
             TOGGLE_BIT(*lat_register[port] , pin);
                ret= R_OK;
        }
    return ret ;
};

/*----------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------*/

/**
 *            Update the direction of each pin of a specific port
 * @param port -->The port that has the pin we need to Initialize -> PORTA_INDEX, PORTB_INDEX, ...
 * @param direction
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_port_direction_initialize(port_index port , direction_t direction){
    ret_status ret = R_NOK ;
    if(port > PORT_MAX_NUMBERS-1){
        return ret;
     }
    else{
    switch (direction) {
        case DIRECTION_OUTPUT : 
           *tris_register[port]= PORT_DIRECTION_OUTPUT ;
            break;
        case DIRECTION_INPUT : 
           *tris_register[port]=PORT_DIRECTION_INPUT;
            break;
        default : return R_NOK;
      }
      return R_OK;
   }
    return ret ;
};
/**
 *       Get the status direction of each pin of a specific port
 * @param port  to select the port PORTA_INDEX ,PORTB_INDEX ,PORTC_INDEX ....
 * @param direction
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_port_get_direction_status(port_index port , uint8_t *direction){
   ret_status ret = R_NOK ;
if( (port > PORT_MAX_NUMBERS-1) || (  NULL == direction ) ){
        return ret;
     }
    else{
      *direction = *tris_register[port] ;
      ret = R_OK ;
    }
 return ret;
};
/**
 *            Write a voltage level on the port
 * @param port The port that has the pin we need to Initialize -> PORTA_INDEX, PORTB_INDEX, ...
 * @param value
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_port_write_value(port_index port, uint8_t value){
    ret_status ret = R_NOK ;
 if ( port > PORT_MAX_NUMBERS-1 ){
        return ret;
       }
    else{
       *lat_register[port] = value ;
       ret = R_OK;
     }
 return ret;
};

/**
 *           Read the voltage level on the port
 * @param port  The port that has the pin we need to Initialize -> PORTA_INDEX, PORTB_INDEX, ...
 * @param value
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */

ret_status gpio_port_read_value(port_index port , uint8_t *value){
   ret_status ret = R_NOK;
 if((port > PORT_MAX_NUMBERS-1) || (NULL == value)){
        return ret;
    }
    else{
        *value = *port_register[port];
        ret = R_OK;
    }
    return ret;
};

/**
 *              Toggle the port voltage level
 * @param port--> The port that has the pin we need to Initialize -> PORTA_INDEX, PORTB_INDEX, ...
 * @return status --> Status of the function (R_OK , R_NOK)
 *         (R_OK) : The function done successfully
 */
ret_status gpio_port_toggle_value(port_index port){
    ret_status ret = R_NOK;
    if(port > PORT_MAX_NUMBERS-1){
        return ret;
    }
    else{
        TOGGLE_PORT(*lat_register[port]);
        ret = R_OK;
    }
    return ret;
};