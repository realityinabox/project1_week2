/* ###################################################################
**     Filename    : Events.c
**     Project     : Lab2
**     Processor   : MK64FN1M0VLQ12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-12, 19:05, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"
#include "PDC1.h"
#include "PE_types.h"
#include "rLED.h"
#include "gLED.h"

#ifdef __cplusplus
extern "C" {
#endif 

volatile int old_enc = 0;

static const int8_t enc_states [] =
	  {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};  //encoder lookup table

static bool t1;
static bool t2;
static int enc = 0;

volatile int rot;
volatile int counter = 0;
volatile int pb = 0xFF;
volatile int enc_write_flag = 0;

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MK64FN1M0LQ12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  SM1_OnBlockSent (module Events)
**
**     Component   :  SM1 [SPIMaster_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void SM1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt_LDD]
*/
/*!
**     @brief
**         This event is called when an active signal edge/level has
**         occurred.
**     @param
**         UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
*/
/* ===================================================================*/
void EInt1_OnInterrupt(LDD_TUserData *UserDataPtr)
{
	// Get pin value

}

/*
** ===================================================================
**     Event       :  ENC_SW_2_OnInterrupt (module Events)
**
**     Component   :  ENC_SW_2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ENC_SW_2_OnInterrupt(void)
{
	enc_write_flag = 1;
	// Get the pin values
	t1 = ENC_SW_1_GetVal();
	t2 = ENC_SW_2_GetVal();

	// Left shift t2 by 1 spot, then combine them to create a 2 bit number
	enc = (t2 << 1) | t1;

	// old_enc is a global volatile int, so the previous value remains
	// left shift the previous value by two to make room for current value
	old_enc = old_enc << 2;

	// insert the new value in the 2 LSB
	old_enc |= enc;

	// chop off old values beyond the 4 LSB in order to make the following if statements easier
	old_enc &= 0x0F;

	// CW
	if (old_enc == 0b0010 || old_enc == 0b1011 || old_enc == 0b1101 || old_enc == 0b0100)
		if (counter < 100)
			counter += 1;
	// CCW
	if (old_enc == 0b0001 || old_enc == 0b0111 || old_enc == 0b1110 || old_enc == 0b1000)
		if (counter > 0)
			counter -= 1;
}

/*
** ===================================================================
**     Event       :  ENC_SW_1_OnInterrupt (module Events)
**
**     Component   :  ENC_SW_1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ENC_SW_1_OnInterrupt(void)
{
  /* Write your code here ... */
	enc_write_flag = 1;
	t1 = ENC_SW_1_GetVal();
	t2 = ENC_SW_2_GetVal();

	enc = (t2 << 1) | t1;

	old_enc = old_enc <<2;
	old_enc |= enc;

	old_enc &= 0x0F;
	// CW
	if (old_enc == 0b0010 || old_enc == 0b1011 || old_enc == 0b1101 || old_enc == 0b0100)
		if (counter < 100)
			counter += 1;
	// CCW
	if (old_enc == 0b0001 || old_enc == 0b0111 || old_enc == 0b1110 || old_enc == 0b1000)
		if (counter > 0)
			counter -= 1;

}

/*
** ===================================================================
**     Event       :  ENC_PB_OnInterrupt (module Events)
**
**     Component   :  ENC_PB [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
volatile int read_1;
void ENC_PB_OnInterrupt(void)
{
  /* Write your code here ... */
	pb = 1;
}

/*
** ===================================================================
**     Event       :  TI1_SW_OnInterrupt (module Events)
**
**     Component   :  TI1_SW [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
volatile int timer_1s;
void TI1_SW_OnInterrupt(void)
{
  /* Write your code here ... */
	timer_1s = 1;
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
volatile int adc1_flag;
void AD1_OnEnd(void)
{
  /* Write your code here ... */
	adc1_flag = 1;
}

/*
** ===================================================================
**     Event       :  AD1_OnCalibrationEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD1_OnCalibrationEnd(void)
{
  /* Write your code here ... */

}


/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
	TmDt1_AddTick();
}

/*
** ===================================================================
**     Event       :  SM2_OnBlockSent (module Events)
**
**     Component   :  SM2 [SPIMaster_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. This event is
**         available only if the SendBlock method is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
*/
/* ===================================================================*/
void SM2_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.11]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
