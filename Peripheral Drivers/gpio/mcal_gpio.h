/* 
 * File:   mcal_gpio.h
 * Author: Ahmed khaled
 *
 * Created on March 13, 2021, 1:46 AM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H

/* Section: Include */

#include "../../std_types.h" 
 #include "pic18f46k20.h"

/* Section: Macro Declarations */

#define PORT_MAX_NUMBERS            5U
#define PORT_PIN_MAX_NUMBERS        8U
#define PORT_DIRECTION_INPUT        0xFFU
#define PORT_DIRECTION_OUTPUT       0x00U
#define PIN_MASK_VALUE              1U
#define PORT_MASK_VALUE             0XFF
#define PORT_ALL_CLEAR              0X00
#define PORT_ALL_OFF                0X00

/* Section: Macro Functions Declarations */

#define CLEAR_BIT(REGISTER,BIT_POS)  (REGISTER &= ~(PIN_MASK_VALUE << BIT_POS))
#define SET_BIT(REGISTER,BIT_POS)    (REGISTER |= (PIN_MASK_VALUE << BIT_POS))
#define TOGGLE_BIT(REGISTER,BIT_POS) (REGISTER ^= (PIN_MASK_VALUE << BIT_POS))
#define READ_BIT(REGISTER,BIT_POS)   ((REGISTER >> BIT_POS) & PIN_MASK_VALUE)

#define CLEAR_PORT(REGISTER)    (REGISTER &= ~PORT_MASK_VALUE)
#define SET_PORT(REGISTER)      (REGISTER |= PORT_MASK_VALUE)
#define TOGGLE_PORT(REGISTER)   (REGISTER ^= PORT_MASK_VALUE)

/* Section: Data Type Definitions */

typedef enum {
   
     LOW,
     HIGH
 
} logic_t ;

typedef enum {
   
     DIRECTION_OUTPUT,
     DIRECTION_INPUT 
 
} direction_t ;

typedef enum {
    
     PIN0,
     PIN1,
     PIN2,
     PIN3,
     PIN4,
     PIN5,
     PIN6,      
     PIN7,       
} pin_index ;

typedef enum {
   
     PORTA_INDEX ,
     PORTB_INDEX ,
     PORTC_INDEX ,
     PORTD_INDEX ,
     PORTE_INDEX 
 
} port_index ;


/* Section: Function declarations */

ret_status gpio_port_default_init(uint8_t port_numbers );

ret_status gpio_pin_direction_initialize(port_index port , pin_index pin ,direction_t direction  );
ret_status gpio_pin_get_direction_status(port_index port , pin_index pin , direction_t *direction);
ret_status gpio_pin_write_value(port_index port , pin_index pin , logic_t logic);
ret_status gpio_pin_read_value(port_index port , pin_index pin , logic_t *logic);
ret_status gpio_pin_toggle_value(port_index port , pin_index pin );

ret_status gpio_port_direction_initialize(port_index port , direction_t direction);
ret_status gpio_port_get_direction_status(port_index port , uint8_t *direction);
ret_status gpio_port_write_value(port_index port, uint8_t value);
ret_status gpio_port_read_value(port_index port , uint8_t *value);
ret_status gpio_port_toggle_value(port_index port);

#endif	/* MCAL_GPIO_H */