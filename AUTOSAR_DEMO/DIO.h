/*
 * DIO.h
 *
 *  Created on: 7 Oct 2023
 *      Author: Amr Al-Kayal
 */

#ifndef DIO_H_
#define DIO_H_


#include "Std_Types.h"
#include "DIO_Cfg.h"


typedef uint8 Dio_LevelType;

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;

typedef uint8 Dio_PortLevelType;




Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);



#endif /* DIO_H_ */
