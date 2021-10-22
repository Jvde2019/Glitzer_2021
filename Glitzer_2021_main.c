/****************************************************************************//**
* \file structcmd.h
* \brief A Documented file.
* Details.
*
* *************** GLITZER using PIC16F628A   ***********************
*
* IDE:         MPLAB Xpress 
* Compiler:    XC8 (2.31)
* File:        Glitzer_2021_main.c
* Project:     2021  Nr. 001
* Created on:  22. Oct 2021, 20:26
* Author:      jm
*                                                                               
* This Software is free for private use. Any commercial use is prohibited.
* you free to redistribute it or modify the code way you wish.
* This software is for educational purpose only.
*
* The author will not be responsible for any loss or liability whatsoever.
* In any circumstances jm shall not be liable for any
* special, incidental or consequential damages, for any reason whatsoever.
* No guarantee or warranty whatsoever. 
* // http://microchip.wikidot.com/tls2101:start
*
********************************************************************************/

/*******************************************************************************
* Includes
********************************************************************************/
#include <xc.h>
#include "Glitzer_2021.h"

//#include <limits.h>
//#include <stdint.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <sys.h>
//#include <pic16f628a.h>
//#include <pic16f628a.inc>

/********************************************************************************
* Constants
********************************************************************************/

#define TRUE = 1
#define FALSE = 0
#define _XTAL_FREQ = 4000000

/********************************************************************************
* Global Variables uintxxx Types needs <stdint.h>
********************************************************************************/
const unsigned char ROM_random_values[]={0x58,0x51,0x9f,0x2e,0xe7,0x8a,0x0c,
                                         0xab,0x47,0x99,0xdd,0x3d,0xed,0x15,
                                         0x7d,0xb6,0x20,0x61};

unsigned int loops=0;
unsigned int i=0;
unsigned char EEPROM_address=0,d=0;
unsigned int loops,i;
unsigned int count_ints,pwm;
unsigned char up,down,duty;

unsigned char Task = 0;
volatile int PWMcount = 0;
volatile int PWMduty[12];

/********************************************************************************
* Arrays
********************************************************************************/

unsigned char random_values[16]; // 16 Bytes 
//unsigned char PORTALatch[1];

/*******************************************************************************
* Arrays 2 Dimensiones
********************************************************************************/

//uint8_t stripe[30][3];

/********************************************************************************
* Structs
********************************************************************************/
struct LATA
{
  unsigned int L0: 1; 
  unsigned int L1: 1;
  unsigned int L2: 1;
  unsigned int L3: 1;
  unsigned int L4: 1;
  unsigned int L5: 1;
  unsigned int L6: 1;
  unsigned int L7: 1;
} LATABits;

struct LATB
{
  unsigned int L0: 1; 
  unsigned int L1: 1;
  unsigned int L2: 1;
  unsigned int L3: 1;
  unsigned int L4: 1;
  unsigned int L5: 1;
  unsigned int L6: 1;
  unsigned int L7: 1;
} LATBBits;

//struct pixelcolor{
//  uint8_t gbyte;
//  uint8_t rbyte;
//  uint8_t bbyte;
//}Pixelcolors[30];

//struct temp_pixelcolor{
//  uint8_t gbyte;
//  uint8_t rbyte;
//  uint8_t bbyte;
//}temp_pixelcolors;

/*******************************************************************//**
* Struct for RGB:
* Array for 30Pixel = Sripebuffer
* Predefined Colors
//                                                                    */

 /* TODO write stripe rewrite with predefined colors and pointer to it  */


/*******************************************************************//**
* Functionprototypes
************************************************************************/

void Init(void);

void Low(void);
void High(void);
void Res(void);
void Warte(int);
void InitInterrupt(void);

/*******************************************************************//**
* void Warte(void)
* in:  loops  - how many times to delay 10ms
* out:
*
* \brief dalays for loops times 10ms
*
************************************************************************/

void Warte(int loops)
{
  for (i=0;i<loops;i++)
   {
   _delay(982);
   }
}


/*******************************************************************//**
* void porta_low(void)
*
* \brief  only for debugging
*
************************************************************************/
void porta_low(void)
{
PORTAbits.RA0 =0; 
PORTAbits.RA1 =0;
PORTAbits.RA2 =0;
PORTAbits.RA3 =0;
}


/*******************************************************************//**
* void porta_low(void)
*
* \brief  only for debugging
*
************************************************************************/
void porta_high(void)
{
PORTAbits.RA0 =1; 
PORTAbits.RA1 =1;
PORTAbits.RA2 =1;
PORTAbits.RA3 =1;
}

/*******************************************************************//**
* void LED1()
*
* \brief  only for debugging
*
************************************************************************/
void LED1()
{
    PORTAbits.RA1 =0; 
    
    if (count_ints < 512 )
    {
     PORTBbits.RB5 = 1;                // Einschalten  
     pwm++;
     if (pwm > 50)
     {  
       PORTBbits.RB5 = 0;  
     }  
    }
    else
    {
     PORTBbits.RB5 = 0;                // Einschalten    
     duty--;
    }    
    
    PORTAbits.RA1 =0; 
 //   i=0,up=0,down=512,duty=0,loops=0;
    
//       for (loops = 0;loops < 512;loops++)
//       {
//         if (loops == 256) duty=1 ;   
//         if (duty == 0) ; 
//         PORTBbits.RB5 = 1;                // Einschalten
//         {
//             up++;
//             for (i = 0;i < 255;i++)         
//             if (i>=up) PORTBbits.RB5 = 0;     // Ausschalten
//         }
//         if (duty == 1) ; 
//         PORTBbits.RB5 = 1;                // Einschalten      
//         {
//            down--;                
//             for (i = 0;i < 255;i++)                     
//             if (i>=down) PORTBbits.RB5 = 0;   // Ausschalten
//           }  
//        } 
//       
}
/*******************************************************************//**
* void Init()
*
* \brief  Init all needed Hardware
*
************************************************************************/
void Init(void)
{
    int ii=0;
    PORTA = 0;   // clear PORT A 
    TRISA = 0;   // PORT A all Output
    
    PORTB = 0;   // clear PORT B 
    TRISB = 0;   // PORT B all Output
    
// EEPROM read    
     
//     for (ii = 0;ii < 15;ii++)
//      {
//         random_values[ii] = ROM_random_values[ii];
//      }

}

/*******************************************************************//**
* void InitInterupt()
*
* \brief  Init Interuptrelated things
*
************************************************************************/
void InitInterrupt(void)
{
//Timerinterupt T0 4 MHz int clock ==> 1ms Interrupt 
    
   OPTION_REGbits.T0CS   = 0;         // Timer increments on instruction clock
   OPTION_REGbits.PSA    = 0;         // Prescaler works for Timer 0
   OPTION_REGbits.PS2    = 0;// Prescaler
   OPTION_REGbits.PS1    = 0;
   INTCONbits.T0IE       = 1;         // Enable interrupt on TMR0 overflow
   OPTION_REGbits.INTEDG = 0;         // falling edge trigger the interrupt
   INTCONbits. GIE       = 1;         // Global interrupt enable
}        
        


//void interrupt   tc_int  (void)        // interrupt function 
 
//{
//    if(INTCONbits.T0IF && INTCONbits.T0IE)  // if timer flag is set & interrupt enabled
//    {   
//        if (PWMduty[0] <= PWMcount) { PORTBbits.RB7 = 0; } else { PORTBbits.RB7 = 1; }
 //       if (PWMduty[1] <= PWMcount) { PORTBbits.RB5 = 0; } else { PORTBbits.RB5 = 1; }
 //       if (PWMduty[2] <= PWMcount) { PORTBbits.RB1 = 0; } else { PORTBbits.RB1 = 1; }         
 //       if (PWMduty[3] <= PWMcount) { PORTBbits.RB3 = 0; } else { PORTBbits.RB3 = 1; }
//        if (PWMduty[4] <= PWMcount) { OUTPUT_LOW(led2Green); } else { OUTPUT_HIGH(led2Green); }
//        if (PWMduty[5] <= PWMcount) { OUTPUT_LOW(led2Blue) ; } else { OUTPUT_HIGH(led2Blue); }
//         
//        if (PWMduty[6] <= PWMcount) { OUTPUT_LOW(led3Red)  ; } else { OUTPUT_HIGH(led3Red); }
//        if (PWMduty[7] <= PWMcount) { OUTPUT_LOW(led3Green); } else { OUTPUT_HIGH(led3Green); }
//        if (PWMduty[8] <= PWMcount) { OUTPUT_LOW(led3Blue) ; } else { OUTPUT_HIGH(led3Blue); }
//         
//        if (PWMduty[9] <= PWMcount) { OUTPUT_LOW(led4Red)  ; } else { OUTPUT_HIGH(led4Red); }
//        if (PWMduty[10]<= PWMcount) { OUTPUT_LOW(led4Green); } else { OUTPUT_HIGH(led4Green); }
//        if (PWMduty[11]<= PWMcount) { OUTPUT_LOW(led4Blue) ; } else { OUTPUT_HIGH(led4Blue); }
      
 //       if (++PWMcount == 255) {
 //       PWMcount = 0;
 //       Task++; 
 //       }
 //      PORTAbits = LATABits;
 //       PORTBbits = LATBBits;
         //  TMR0 -= 250;               // reload the timer - 250uS per interrupt
    //  count_ints++; 
    // if (count_ints == 1024) count_ints = 0 ;    
 //    INTCONbits.T0IF = 0;       // clear the interrupt flag     
 //   }
//}
/*******************************************************************//**
* void main(void)
*
* \brief  the main code
*
************************************************************************/

void main(void) {
    Init();
    InitInterrupt();
 //   while(1)
    return;
}
 /* TODO cleanup  */
// main()
//{
     
 
  //   
  //   InitInterrupt();
  //   while(1)
  //   { 
     


//LED 1
  //  switch (Task)
  //  {        
  //      case 1: porta_low();PWMduty[0] = 20;PWMduty[1] = 100;PWMduty[2] = 22;PWMduty[3] = 200;break;    
  //      case 2: porta_high();PWMduty[0] = 60;PWMduty[1] = 100;PWMduty[2] = 200;PWMduty[3] = 50;break;                 
  //      case 3: porta_low();PWMduty[0] = 30;PWMduty[1] = 100;PWMduty[2] = 100;PWMduty[3] = 90; break;                
  //      case 4: porta_high();PWMduty[0] = 1;PWMduty[1] = 100;PWMduty[2] = 2;PWMduty[3] = 200;break;                
  //      case 5: porta_low();PWMduty[0] = 64;PWMduty[1] = 100;PWMduty[2] = 80;PWMduty[3] = 128; break;          
  //      case 6: porta_high();PWMduty[0] = 0;PWMduty[1] = 100;PWMduty[2] = 22;PWMduty[3] = 90;Task = 0; break;                 
  //  }
        
//         LED1();
//     }
//     PORTAbits.RA1 =0; 
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB5 = 1;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB5 = 0;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB5 = 1;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB5 = 0;   // Ausschalten
//           }  
//         }   
//        
//LED 2
     
//     PORTAbits.RA1 =1;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB5 = 0;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB5 = 1;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB5 = 0;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB5 = 1;   // Ausschalten
//           }  
//         }   
//     PORTAbits.RA1 =1;
//     PORTBbits.RB5 = 0;   
//     
////LED 3
//     
//     PORTAbits.RA7 = 0;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB4 = 1;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB4 = 0;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB4 = 1;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB4 = 0;   // Ausschalten
//           }  
//         }     
//     PORTAbits.RA7 =1;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB4 = 0;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB4 = 1;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB4 = 0;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB4 = 1;   // Ausschalten
//           }  
//         }
//     PORTAbits.RA7 =0;
//     PORTBbits.RB4 = 0;
//  //3    
//     PORTAbits.RA0 =0;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB7 = 1;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB7 = 0;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB7 = 1;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB7 = 0;   // Ausschalten
//           }  
//         }     
//     PORTAbits.RA0 =1;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB7 = 0;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB7 = 1;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB7 = 0;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB7 = 1;   // Ausschalten
//           }  
//         }
//     PORTAbits.RA0 =0;
//     PORTBbits.RB7 = 0;   
// //4    
//     PORTAbits.RA6 =0;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB6 = 1;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB6 = 0;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB6 = 1;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB6 = 0;   // Ausschalten
//           }  
//         }     
//     PORTAbits.RA6 =1;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB6 = 0;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB6 = 1;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB6 = 0;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB6 = 1;   // Ausschalten
//           }  
//         }
//     PORTAbits.RA6 =0;
//     PORTBbits.RB6 = 0;
//     
//   //5 ra2 rb1   
//     PORTAbits.RA2 =0;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB1 = 1;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB1 = 0;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB1 = 1;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB1 = 0;   // Ausschalten
//           }  
//         }     
//     PORTAbits.RA2 =1;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB1 = 0;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB1 = 1;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB1 = 0;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB1 = 1;   // Ausschalten
//           }  
//         }
//     PORTAbits.RA2 =0;
//     PORTBbits.RB1 = 0;  
//     
//     //6 ra3 rb3   
//     PORTAbits.RA3 =0;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB3 = 1;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB3 = 0;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB3 = 1;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB3 = 0;   // Ausschalten
//           }  
//         }     
//     PORTAbits.RA3 =1;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB3 = 0;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB3 = 1;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB3 = 0;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB3 = 1;   // Ausschalten
//           }  
//         }
//     PORTAbits.RA3 =0;
//     PORTBbits.RB3 = 0; 
//     
//      //7 rb0 rb2   
//     PORTBbits.RB0 =0;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB2 = 1;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB2 = 0;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB2 = 1;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB2 = 0;   // Ausschalten
//           }  
//         }    
//     
//     
//     PORTBbits.RB0 =1;
//     i=0,up=0,down=255;
//         for (loops = 0;loops < 512;loops++)
//         {  
//           if (loops <255)                         // increase Brightness
//           {                       
//             PORTBbits.RB2 = 0;                // Einschalten
//             up++;
//             for (i = 0;i < 255;i=i+5)
//             if (i>=up) PORTBbits.RB2 = 1;     // Ausschalten
//           }
//           if (loops>255)                         // decrease Brightness
//           {
//             PORTBbits.RB2 = 0;                // Einschalten    
//             down--;   
//             for (i = 0;i < 255;i=i+5)
//             if (i>=down) PORTBbits.RB2 = 1;   // Ausschalten
//           }  
//         }
//     PORTBbits.RB0 =0;
//     PORTBbits.RB2 = 0; 
//     
//          }         
//    // }
 //} //main
// no code behind this line
