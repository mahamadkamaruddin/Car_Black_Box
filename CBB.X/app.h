/* 
 * File:   app.h
 * Author: Admin
 *
 * Created on August 10, 2024, 3:31 PM
 */

#ifndef APP_H
#define	APP_H

/*******************
 FILE INCLUSIONS
 ********************/

#include "main.h"

/***********
 DECLARATIONS
 *************/
unsigned char clocktime[3]; //HHMMSS
unsigned char time[9];


void display_dashboard(const char* event, const char *speed);
void displayheader(void);
void gettime(void);
void displaytime(void);
void displayevent(const char* event);
void displayspeed(const char *speed);
#endif	/* APP_H */

