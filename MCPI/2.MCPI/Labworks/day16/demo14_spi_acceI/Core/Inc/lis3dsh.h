/*
 * lis3dsh.h
 *
 *  Created on: Jul 9, 2021
 *      Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
 */

#ifndef INC_LIS3DSH_H_
#define INC_LIS3DSH_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

// Registers
#define LIS3DSH_WHO_AM_I_ADDR                0x0F
#define LIS3DSH_OFF_X_ADDR                   0x10
#define LIS3DSH_OFF_Y_ADDR                   0x11
#define LIS3DSH_OFF_Z_ADDR                   0x12

#define LIS3DSH_CTRL_REG4_ADDR               0x20
#define LIS3DSH_CTRL_REG1_ADDR               0x21
#define LIS3DSH_CTRL_REG2_ADDR               0x22
#define LIS3DSH_CTRL_REG3_ADDR               0x23
#define LIS3DSH_CTRL_REG5_ADDR               0x24
#define LIS3DSH_CTRL_REG6_ADDR               0x25

#define LIS3DSH_STATUS_ADDR                  0x27

#define LIS3DSH_OUT_X_L_ADDR                 0x28
#define LIS3DSH_OUT_X_H_ADDR                 0x29
#define LIS3DSH_OUT_Y_L_ADDR                 0x2A
#define LIS3DSH_OUT_Y_H_ADDR                 0x2B
#define LIS3DSH_OUT_Z_L_ADDR                 0x2C
#define LIS3DSH_OUT_Z_H_ADDR                 0x2D

// Data rate
#define LIS3DSH_DATARATE_POWERDOWN           ((uint8_t)0x00)  /* Power Down Mode*/
#define LIS3DSH_DATARATE_3_125               ((uint8_t)0x10)  /* 3.125 Hz Normal Mode */
#define LIS3DSH_DATARATE_6_25                ((uint8_t)0x20)  /* 6.25  Hz Normal Mode */
#define LIS3DSH_DATARATE_12_5                ((uint8_t)0x30)  /* 12.5  Hz Normal Mode */
#define LIS3DSH_DATARATE_25                  ((uint8_t)0x40)  /* 25    Hz Normal Mode */
#define LIS3DSH_DATARATE_50                  ((uint8_t)0x50)  /* 50    Hz Normal Mode */
#define LIS3DSH_DATARATE_100                 ((uint8_t)0x60)  /* 100   Hz Normal Mode */
#define LIS3DSH_DATARATE_400                 ((uint8_t)0x70)  /* 400   Hz Normal Mode */
#define LIS3DSH_DATARATE_800                 ((uint8_t)0x80)  /* 800   Hz Normal Mode */
#define LIS3DSH_DATARATE_1600                ((uint8_t)0x90)  /* 1600  Hz Normal Mode */

// Axes Enable
#define LIS3DSH_X_ENABLE                     ((uint8_t)0x01)
#define LIS3DSH_Y_ENABLE                     ((uint8_t)0x02)
#define LIS3DSH_Z_ENABLE                     ((uint8_t)0x04)
#define LIS3DSH_XYZ_ENABLE                   (LIS3DSH_X_ENABLE | LIS3DSH_Y_ENABLE | LIS3DSH_Z_ENABLE)
#define LIS3DSH_XY_ENABLE                    (LIS3DSH_X_ENABLE | LIS3DSH_Y_ENABLE)

#define LIS3DSH_STATUS_XYZ_Msk					0x07

// Accel config struct
typedef struct {
	uint8_t dataRate;
	uint8_t enableAxes;
	bool interruptEnable;
}LIS3DSH_InitTypedef;

// Accel raw data
typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
}LIS3DSH_RawData;

// Accel IO Functions
void LIS3DSH_WriteIO(uint8_t reg, uint8_t *dataW, uint8_t size);
void LIS3DSH_ReadIO(uint8_t reg, uint8_t *readW, uint8_t size);

// Accel Init
void LIS3DSH_Init(SPI_HandleTypeDef *accSPI, LIS3DSH_InitTypedef *accInitDef);
// Accel Get Raw Data
LIS3DSH_RawData LIS3DSH_GetRawData(void);
// Accel Poll if Ready
bool LIS3DSH_DRdy(void);

#endif /* INC_LIS3DSH_H_ */
