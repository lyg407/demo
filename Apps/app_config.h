#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/*****************************************
板载驱动 / on board drivers
*****************************************/
#include "drivers_config.h"
#include "led.h"
#include "spiflash.h"
#include "psram.h"
#include "qspiflash.h"
#include "usb_device.h"

#include "cdc.h"
#include "io.h"

#include "cJSON.h"
#include "fifo.h"
#include "fatfs.h"
/******************************************
expansion board drivers
******************************************/



typedef enum
{
	DRIVERS_FAIL = 0,
	DRIVERS_OK,
	DRIVERS_STATUS_NUM
	
}DriversStatus;




typedef struct
{
	DriversStatus sdcard;
	DriversStatus gui;
	DriversStatus usb;
	DriversStatus uart;
	DriversStatus spiflash;
	DriversStatus psram;
	
}DriversStatus_t;



extern uint8_t retSD; /* Return value for SD */
extern char SDPath[4]; /* SD logical drive path */
extern FATFS SDFatFS; /* File system object for SD logical drive */
extern FIL SDFile; /* File object for SD */
extern uint8_t retUSER; /* Return value for USER */
extern char USERPath[4]; /* USER logical drive path */
extern FATFS USERFatFS; /* File system object for USER logical drive */
extern FIL USERFile; /* File object for USER */



#endif