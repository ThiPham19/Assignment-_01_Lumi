/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "system_stm32f4xx.h"
#include "timer.h"
#include "eventman.h"
#include "led.h"
#include "melody.h"
#include "lightsensor.h"
#include "temhumsensor.h"
#include "eventbutton.h"
#include "button.h"
#include "Ucglib.h"


/******************************************************************************/
/*                     PRIVATE TYPES and DEFINITIONS                         */
/******************************************************************************/
typedef enum{
	EVENT_EMPTY,
	EVENT_APP_INIT,
	EVENT_APP_FLUSHMEM_READY
}	event_api_t, *event_api_p;

typedef enum{
	STATE_APP_STARTUP,
	STATE_APP_IDLE,
	STATE_APP_RESET
} state_app_t;
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/


/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
static ucg_t ucg;
state_app_t eCurrentState;
uint8_t LevelLed = 0;
uint32_t TimerId;
/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
static void AppStateManager(uint8_t);
static void SetStateApp(state_app_t);
static state_app_t GetStateApp(void);
void DeviceStateMachine(uint8_t event);
void LoadConfiguration(void);
void AppInitCommon(void);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

/******************************************************************************/
void AppInitCommon()
{
	SystemCoreClockUpdate();
	TimerInit();
	EventSchedulerInit(&AppStateManager);
	EventButton_Init();
	BuzzerControl_Init();
	LedControl_Init();
	LightSensor_Init(ADC_READ_MODE_DMA);
	TemHumSensor_Init();

	/*************		setup LCD		****************/
	Ucglib4WireSWSPI_begin(&ucg, UCG_FONT_MODE_SOLID);
	ucg_ClearScreen(&ucg);
	ucg_SetFont(&ucg, ucg_font_helvR08_tf);
	ucg_SetColor(&ucg, 0, 255, 255, 255);
	ucg_SetColor(&ucg, 1, 0, 0, 0);
	ucg_SetRotate180(&ucg);
}

static void AppStateManager(uint8_t event)
{
	switch(GetStateApp())
	{
	case STATE_APP_STARTUP:
		if(event == EVENT_APP_INIT)
		{
			//Load configuration
			LoadConfiguration();
			SetStateApp(STATE_APP_IDLE);

		}
		break;

	case STATE_APP_IDLE:
		DeviceStateMachine(event);
		break;

	case STATE_APP_RESET:
		break;

	default:
		break;
	}
}

static void SetStateApp(state_app_t state)
{
	eCurrentState = state;
}

static state_app_t GetStateApp(void)
{
	return eCurrentState;
}
/*hàm cho câu 1: hiển thị dòng chữ lên LCD*/
void LoadConfiguration(void){
	ucg_DrawString(&ucg, 0, 12, 0, "IOT Programming by Lumi Smarthome");
}

void tangDoSangLed()
			{
				while(LevelLed < 100)
				{
					LevelLed ++;
					LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_GREEN, LevelLed);
				}
			}
void giamDoSangLed()
			{
				while(LevelLed > 0)
				LevelLed --;
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_GREEN, LevelLed);
			}

void DeviceStateMachine(uint8_t event)
{
	switch(event)
	{
	/*hàm cho câu 2: Nhấn nút B3 năm lần khi đó tất cả các Led trên Kit
	mở rộng sẽ nháy năm lần màu GREEN với cường độ sáng là 50% và hiển
	thị thông tin sau thiết bị lên màn hình LCD*/
		case EVENT_OF_BUTTON_0_PRESS_5_TIMES:
		{
			uint8_t count = 5;

			while(count > 0)
			{
				LedControl_SetAllColor(LED_COLOR_GREEN, 50);
				//thêm hàm delay
				TimerId = TimerStart("Delay", 800, 0, NULL, NULL);
				LedControl_SetAllColor(LED_COLOR_GREEN, 0);
				TimerStop(TimerId);
			}

			//LedControl_BlinkStart(LED_ALL_ID, LED_COLOR_GREEN, 5, 2, LED_COLOR_BLACK);
			ucg_ClearScreen(&ucg);
			ucg_SetFont(&ucg, ucg_font_helvR08_tf);
			ucg_SetColor(&ucg, 0, 255, 255, 255);
			ucg_SetColor(&ucg, 1, 0, 0, 0);
			ucg_SetRotate180(&ucg);
			ucg_DrawString(&ucg, 0, 0, 0, "Device: Board STM32 Nucleo");
			ucg_DrawString(&ucg, 1, 0, 0, "Code: STM32F401RE_NUCLEO");
			ucg_DrawString(&ucg, 2, 0, 0, "Manufacturer: STMicroelectronics");
			ucg_DrawString(&ucg, 3, 0, 0, "Kit expansion: Lumi Smarthome");
			ucg_DrawString(&ucg, 4, 0, 0, "Project: Simulator touch switch");
		}	break;


		uint8_t button1count;
		case EVENT_OF_BUTTON_1_PRESS_LOGIC:
		{
			button1count = 0;
			if(button1count == 0)
			{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_RED, 50);
				BuzzerControl_SetMelody(pbeep);
				button1count = 1;
			}else{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_RED, 0);
				BuzzerControl_SetMelody(pbeep);
				button1count = 0;
			}

		}	break;


		uint8_t button2count;
		case EVENT_OF_BUTTON_2_PRESS_LOGIC:
		{
			button2count = 0;
			if(button2count == 0)
			{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_GREEN, 50);
				BuzzerControl_SetMelody(pbeep);
				button2count = 1;
			}else{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_GREEN, 0);
				BuzzerControl_SetMelody(pbeep);
				button2count = 0;
			}
		}	break;

		uint8_t button4count;
		case EVENT_OF_BUTTON_4_PRESS_LOGIC:
		{
			button4count = 0;
			if(button4count == 0)
			{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_WHITE, 50);
				BuzzerControl_SetMelody(pbeep);
				button4count = 1;
			}else{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_WHITE, 0);
				BuzzerControl_SetMelody(pbeep);
				button4count = 0;
			}
		}	break;


		uint8_t button5count;
		case EVENT_OF_BUTTON_5_PRESS_LOGIC:
		{
			button5count = 0;
			if(button5count == 0)
			{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_BLUE, 50);
				BuzzerControl_SetMelody(pbeep);
				button5count = 1;
			}else{
				LedControl_SetColorGeneral(LED_KIT_ID0, LED_COLOR_BLUE, 0);
				BuzzerControl_SetMelody(pbeep);
				button5count = 0;
			}
		}	break;


		case EVENT_OF_BUTTON_1_HOLD_1S:
		{

			TimerId = TimerStart("LevelUpLed", 1000, 20, tangDoSangLed, NULL);

		}	break;


		case EVENT_OF_BUTTON_5_HOLD_1S:
		{
			TimerId = TimerStart("LevelDownLed", 1000, 20, giamDoSangLed, NULL);
		}	break;


		case EVENT_OF_BUTTON_1_RELEASED_1S:
		{
			TimerStop(TimerId);// cần hỏi lại
		} break;


		case EVENT_OF_BUTTON_5_RELEASED_1S:
		{
			TimerStop(TimerId);// cần hỏi lại
		} break;


		default:
			break;
	}
}

void Task_multiSensorScan()
{
	//hiển thị nhiệt độ
	char original_temp[100] = "Temp = ";
 	uint32_t temp = TemHumSensor_GetTemp();
 	sprintf(original_temp,"%s%d%s",original_temp,temp,"oC");
 	ucg_DrawString(&ucg, 2, 1, 0, original_temp);

 	char original_humi[50] = "Humi = ";
	uint32_t humi = TemHumSensor_GetHumi();
 	sprintf(original_humi,"%s%d%s",original_humi,humi,"%");
 	ucg_DrawString(&ucg, 3, 1, 0, original_humi);

 	char original_light[50] = "Humi = ";
	uint32_t light = LightSensor_MeasureUseDMAMode();
 	sprintf(original_light,"%s%d%s",original_light,light,"%");
 	ucg_DrawString(&ucg, 4, 1, 0, original_light);
}

void MultiSensorScan()
{
    uint32_t lastUpdateTime = GetMilSecTick();
    uint32_t updateInterval = 1000; // 1 giây (1000 millisecond)

    while (1) {
        uint32_t currentTime = GetMilSecTick();

        if (currentTime - lastUpdateTime >= updateInterval) {
            // Đã đủ thời gian để cập nhật nhiệt độ và độ ẩm
            // Thực hiện việc cập nhật thông tin từ cảm biến và hiển thị lên LCD
            Task_multiSensorScan();

            // Cập nhật thời gian của lần cập nhật cuối cùng
            lastUpdateTime = currentTime;
        }

        // Sleep để tránh lặp quá nhanh và gây tải CPU không cần thiết
        // Thời gian sleep có thể điều chỉnh tùy ý
        // Sleep 1 giây trước khi kiểm tra lại
        TimerStart("Delay_1s", 1000, 0, NULL, NULL);
    }
}
int main(void){
	AppInitCommon();
	SetStateApp(STATE_APP_STARTUP);
	EventSchedulerAdd(EVENT_APP_INIT);

	while(1)
	{
		processTimerScheduler();
		processEventScheduler();
		MultiSensorScan();
	}
}
