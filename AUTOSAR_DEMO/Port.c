/*
 * Port.c
 *
 *  Created on: 7 Oct 2023
 *      Author: Amr Al-Kayal
 */
#include "DIO_MemMap.h"
#include "Std_Types.h"
#include "Port.h"




void Port_Init (const Port_ConfigType* ConfigPtr)
{

    uint8_t i;
    for(i=0;i < ConfigPtr->NumPins; i++)
    {
        const Port_PinConfigType* pinConfig = &(ConfigPtr->Pins[i]);

         // Determine the base address of the port based on the pin ID
         volatile uint32_t* portBase = (volatile uint32_t*)(0x40004000 + (pinConfig->PinId & 0xF0));

         // Enable the GPIO peripheral for the specific port
         SYSCTL_RCGCGPIO_R |= (1 << ((pinConfig->PinId & 0xF0) >> 4));

         // Set the pin direction
         if (pinConfig->Direction == 1)  // Assuming 1 represents output
         {
             *portBase |= (1 << (pinConfig->PinId & 0x0F));
         }

         else
         {
             *(portBase + 0x03FC) &= ~(1 << (pinConfig->PinId & 0x0F));
         }

         // Set pull-down resistor
         if (pinConfig->PullDown)
         {
             *(portBase + 0x03C8) |= (1 << (pinConfig->PinId & 0x0F));
         }
         else
         {
             *(portBase + 0x03C8) &= ~(1 << (pinConfig->PinId & 0x0F));
         }
     }

}


