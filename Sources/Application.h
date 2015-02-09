/*
 * Application.h
 *
 *  Created on: Feb 9, 2015
 *      Author: Steve
 */


#include "WAIT1.h"
#include "FX1.h"
#include "FAT1.h"
#include "UTIL1.h"
#include "PORT_PDD.h"

#ifndef APPLICATION_H_
#define APPLICATION_H_

void APP_Run(void);
static void Err(void);
static void LogToFile(int16_t x, int16_t y, int16_t z);




#endif /* APPLICATION_H_ */
