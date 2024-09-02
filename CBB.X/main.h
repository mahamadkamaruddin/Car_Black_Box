/* 
 * File:   main.h
 * Author: Admin
 *
 * Created on August 10, 2024, 11:34 AM
 */

#ifndef MAIN_H
#define	MAIN_H


/* ******************************
 file inclusions
 *******************************/
#include <xc.h>
#include <stdint.h>
#include <string.h>
#include "adc.h"
#include "clcd.h"
#include "digital_keypad.h"
#include "ds1307.h"
#include "i2c.h"
#include "app.h"

/**********************
        macro
 **********************/

/**********************
 variable declarations
 **********************/
unsigned char event[2];
unsigned short speed;
unsigned char key;

/*************************
    function definations
 *************************/

static void init_config(void);

#endif	/* MAIN_H */

