/*
 * File:   main.c
 * Author: Admin
 *
 * Created on August 24, 2024, 7:38 PM
 */


#include <xc.h>
#include "main.h"

#pragma config WDTE = OFF //Watchdog timer disabled

static void init_config(void) {
    //Write your initialization code here
    init_adc();
    init_clcd();
    init_digital_keypad();
    
    init_i2c(100000); //set baud rate
    /*Sloved issue of infinite loop in initalizaiton of ds1307
     cause: init_ds1307() function uses i2c function, but 12c was initialized below which caused problem
     action taken: 12c is now initialized before the ds1307*/
    init_ds1307(); 
    
}
void getdata(void)
{
    speed = read_adc();
    speed = speed/10;
    if(speed > 99)
    {
        speed = 99;
    }
    
    key = read_digital_keypad(STATE);
    
    
}

void main(void) {
    init_config(); //Calling initializing function
    
    //set event in off state
    strcpy(event, "OF");
    
    while (1) {
        //Write application code here
        getdata();
//        speed = read_adc();
        display_dashboard(event,&speed);
    }
}
