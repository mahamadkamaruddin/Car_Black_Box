/***************************
        header file
 ***************************/
#include "main.h"

/*
 * Function :   displayheader()
 * description: To print the time event speed text on CLCD top line
 * arguments:   NA
 * return :     void */
void displayheader(void)
{
    /*variable to store first line in the dashboard 
     * which gives description of the data to its below*/
    char header[] = "  TIME     E  SP";
    /*printing the headers of the data at top line*/
    clcd_print(header, LINE1(0));
}
/*
 * Function :   gettime()
 * description: To get the time from RTC
 * arguments:   NA
 * return :     void */
void gettime(void)
{
    clocktime[0] = read_ds1307(HOUR_ADDR);
    clocktime[1] = read_ds1307(MIN_ADDR);
    clocktime[2] = read_ds1307(SEC_ADDR);
    
    time[0] = ((clocktime[0] >> 4) & 0x0F) + '0';
    time[1] = (clocktime[0] & 0x0F) + '0';
    time[2] = ':';
    time[3] = ((clocktime[1] >> 4) & 0x0F) + '0';
    time[4] = (clocktime[1] & 0x0F) + '0';
    time[5] = ':';
    time[6] = ((clocktime[2] >> 4) & 0x0F) + '0';
    time[7] = (clocktime[2] & 0x0F) + '0';
    time[8] = '\0';
}
/*
 * Function :   displaytime()
 * description: To print the time on CLCD
 * arguments:   NA
 * return :     void */
void displaytime(void)
{
    gettime();
    clcd_print(time,LINE2(0));
}

/*
 * Function :   displayevent()
 * description: To print the time on CLCD
 * arguments:   NA
 * return :     void */
void displayevent(const char* event)
{
    /*printing the event at bottom line*/
    clcd_print(event, LINE2(11));
}

/*
 * Function :   displayspeed()
 * description: To print the time on CLCD
 * arguments:   NA
 * return :     void */
void displayspeed(const char *speed)
{
    /*printing the speed at bottom line character at a time*/
    clcd_putch((*speed / 10)+'0' ,LINE2(14));
    clcd_putch((*speed % 10)+'0' ,LINE2(15));
}
/*
 * Function :   display_dashboard()
 * description: To display the elements on the CLCD
 * arguments:   uint8_t* event, uint8_t speed
 * return :     void */
void display_dashboard(const char* event, const char *speed)
{
    displayheader();
    
    displaytime();
    
    displayevent(event);
    
    displayspeed(speed);
    
}
