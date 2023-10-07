/*
 * DIO.c
 *
 *  Created on: 7 Oct 2023
 *      Author: Amr Al-Kayal
 */


#include "SchM_DIO.h"
#include "DIO_MemMap.h"
#include "DIO.h"
#include "Utils.h"




Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 port=ChannelId/8;
    uint8 pin=ChannelId%8;
    Dio_LevelType volt=0;
    switch(port)
    {
        case(PORTA):
        volt = READ_BIT(GPIO_PORTA_DATA_R,pin);
        break;
        case(PORTB):
        volt = READ_BIT(GPIO_PORTB_DATA_R,pin);
        break;
        case(PORTC):
        volt = READ_BIT(GPIO_PORTC_DATA_R,pin);
        break;
        case(PORTD):
        volt = READ_BIT(GPIO_PORTD_DATA_R,pin);
        break;
        case(PORTE):
        volt = READ_BIT(GPIO_PORTE_DATA_R,pin);
        break;
        case(PORTF):
        volt = READ_BIT(GPIO_PORTF_DATA_R,pin);
        break;
    }
    return volt;
}


void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    uint8 port=ChannelId/8;
    uint8 pin=ChannelId%8;

    if(Level==1)
    {
        switch(port)
        {
            case(PORTA):
            SET_BIT(GPIO_PORTA_DATA_R,pin);
            break;
            case(PORTB):
            SET_BIT(GPIO_PORTB_DATA_R,pin);
            break;
            case(PORTC):
            SET_BIT(GPIO_PORTC_DATA_R,pin);
            break;
            case(PORTD):
            SET_BIT(GPIO_PORTD_DATA_R,pin);
            break;
            case(PORTE):
            SET_BIT(GPIO_PORTE_DATA_R,pin);
            break;
            case(PORTF):
            SET_BIT(GPIO_PORTF_DATA_R,pin);
            break;
        }
    }
    else if (Level==0)
        {
            switch(port)
            {
            case(PORTA) :
            CLEAR_BIT(GPIO_PORTA_DATA_R,pin);
            break;
            case(PORTB) :
            CLEAR_BIT(GPIO_PORTB_DATA_R,pin);
            break;
            case(PORTC) :
            CLEAR_BIT(GPIO_PORTC_DATA_R,pin);
            break;
            case(PORTD) :
            CLEAR_BIT(GPIO_PORTD_DATA_R,pin);
            break;
            case(PORTE) :
            CLEAR_BIT(GPIO_PORTE_DATA_R,pin);
            break;
            case(PORTF) :
            CLEAR_BIT(GPIO_PORTF_DATA_R,pin);
            break;
            }
        }
}


Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId)
{
    Dio_PortLevelType level=0;
    switch(PortId)
    {
        case(PORTA):
        level = READ_ALL_REGISTER_PINS(GPIO_PORTA_DATA_R);
        break;
        case(PORTB):
        level = READ_ALL_REGISTER_PINS(GPIO_PORTB_DATA_R);
        break;
        case(PORTC):
        level = READ_ALL_REGISTER_PINS(GPIO_PORTC_DATA_R);
        break;
        case(PORTD):
        level = READ_ALL_REGISTER_PINS(GPIO_PORTD_DATA_R);
        break;
        case(PORTE):
        level = READ_ALL_REGISTER_PINS(GPIO_PORTE_DATA_R);
        break;
        case(PORTF):
        level = READ_ALL_REGISTER_PINS(GPIO_PORTF_DATA_R);
        break;
    }
    return level;
}


void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    switch(PortId)
        {

            case (PORTA):
            GPIO_PORTA_DATA_R=Level;
            break;

            case (PORTB):
            GPIO_PORTB_DATA_R=Level;
            break;

            case (PORTC):
            GPIO_PORTC_DATA_R=Level;
            break;

            case (PORTD):
            GPIO_PORTD_DATA_R=Level;
            break;
            case (PORTE):
            GPIO_PORTE_DATA_R=Level;
            break;
            case (PORTF):
            GPIO_PORTF_DATA_R=Level;
            break;

        }
}








