#include "app_config.h"

#ifdef app_blink

osThreadId app_handler_blink;

/*********************************************************************


**********************************************************************/
void app_blink_task(void const * argument)
{
	extern DriversStatus_t drivers_status;
	while(1)
	{
		led(LED_RED,1);
		led(LED_GREEN,1);
		osDelay(100);
		led(LED_RED,0);
		led(LED_GREEN,0);
		osDelay(100);
		cdc_printf("\r\n");
		osDelay(1);
		if(drivers_status.usb==DRIVERS_OK)
		{
			cdc_printf("1. usb ok\r\n");
		}
		else
		{
			cdc_printf("1. usb fail\r\n");
		}
		osDelay(1);
		if(drivers_status.sdcard==DRIVERS_OK)
		{
			cdc_printf("2. sdcard ok\r\n");
		}
		else
		{
			cdc_printf("2. sdcard fail\r\n");
		}
		osDelay(1);
		if(drivers_status.spiflash==DRIVERS_OK)
		{
			cdc_printf("3. spiflash ok\r\n");
		}
		else
		{
			cdc_printf("3. spiflash fail\r\n");
		}
		osDelay(1);
		if(drivers_status.psram==DRIVERS_OK)
		{
			cdc_printf("4. psram ok\r\n");
		}
		else
		{
			cdc_printf("4. psram fail\r\n");
		}
		osDelay(1);
	}
}

/*********************************************************************


**********************************************************************/
void app_blink_start(void)
{	

  osThreadDef(blink_task, app_blink_task, osPriorityNormal, 1, 1024);
	app_handler_blink = osThreadCreate(osThread(blink_task), NULL);
}

#endif