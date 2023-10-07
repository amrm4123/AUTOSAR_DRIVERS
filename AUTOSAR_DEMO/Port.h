/*
 * Port.h
 *
 *  Created on: 7 Oct 2023
 *      Author: Amr Al-Kayal
 */

#ifndef PORT_H_
#define PORT_H_


#define MAX_PINS 8

bool PullUp;          // Enable pull-up resistor
bool PullDown;        // Enable pull-down resistor

typedef struct
{
   uint32_t PinId;       // Identifier of the port pin
   uint8_t Direction;    // Direction of the port pin (input or output)
   bool PullUp;          // Enable pull-up resistor
   bool PullDown;        // Enable pull-down resistor
} Port_PinConfigType;

typedef struct
{
   uint32_t NumPins;                    // Number of port pins
   Port_PinConfigType Pins[MAX_PINS];    // Array of individual port pin configurations
} Port_ConfigType;


void Port_Init (const Port_ConfigType* ConfigPtr);


#endif /* PORT_H_ */
