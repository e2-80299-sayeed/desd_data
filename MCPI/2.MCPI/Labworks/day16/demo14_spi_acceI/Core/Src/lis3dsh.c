/*
 * lis3dsh.c
 *
 *  Created on: Jul 9, 2021
 *      Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
 */

#include "lis3dsh.h"

#define _LIS3DSH_CS_ENABLE		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET)
#define _LIS3DSH_CS_DISABLE		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET)

static SPI_HandleTypeDef accSPI_Handle;

// Accel IO Functions
void LIS3DSH_WriteIO(uint8_t reg, uint8_t *dataW, uint8_t size) {
	uint8_t spiReg = reg;
	// Enable CS
	_LIS3DSH_CS_ENABLE;
	// Send Accel Register Address
	HAL_SPI_Transmit(&accSPI_Handle, &spiReg, 1, 10);
	// Send Accel Register Value
	HAL_SPI_Transmit(&accSPI_Handle, dataW, size, 20);
	// Disable CS
	_LIS3DSH_CS_DISABLE;
}

void LIS3DSH_ReadIO(uint8_t reg, uint8_t *dataR, uint8_t size) {
	uint8_t spiBuf[4];
	spiBuf[0] = reg | 0x80;
	// Enable CS
	_LIS3DSH_CS_ENABLE;
	// Send Accel Register Address
	HAL_SPI_Transmit(&accSPI_Handle, spiBuf, 1, 10);
	// Receive Accel Register Value
	HAL_SPI_Receive(&accSPI_Handle, spiBuf, size, 20);
	// Disable CS
	_LIS3DSH_CS_DISABLE;
	for(uint8_t i=0; i<size; i++)
		dataR[i] = spiBuf[i];
}

// Accel Init
void LIS3DSH_Init(SPI_HandleTypeDef *accSPI, LIS3DSH_InitTypedef *accInitDef) {
	uint8_t spiData;
	// copy accSPI into global var
	accSPI_Handle = *accSPI;
	// enable X, Y axes and set output data rate -- CTRL_REG4
	spiData = accInitDef->dataRate | accInitDef->enableAxes;
	LIS3DSH_WriteIO(LIS3DSH_CTRL_REG4_ADDR, &spiData, 1);
	// if interrupt enable, enable DRDY interrupt -- LIS3DSH_CTRL_REG3_ADDR -- assignment
}

// Accel Get Raw Data
LIS3DSH_RawData LIS3DSH_GetRawData(void) {
	uint8_t spiBuf[2];
	LIS3DSH_RawData dataRaw;
	// read 16-bit X axis data
	LIS3DSH_ReadIO(LIS3DSH_OUT_X_L_ADDR, spiBuf, 2);
	dataRaw.x = (spiBuf[1] << 8) + spiBuf[0];
	// read 16-bit Y axis data
	LIS3DSH_ReadIO(LIS3DSH_OUT_Y_L_ADDR, spiBuf, 2);
	dataRaw.y = (spiBuf[1] << 8) + spiBuf[0];
	// read 16-bit Z axis data
	LIS3DSH_ReadIO(LIS3DSH_OUT_Z_L_ADDR, spiBuf, 2);
	dataRaw.z = (spiBuf[1] << 8) + spiBuf[0];
	return dataRaw;
}

// Accel Poll if Ready
bool LIS3DSH_DRdy(void) {
	uint8_t accStatus;
	do {
		LIS3DSH_ReadIO(LIS3DSH_STATUS_ADDR, &accStatus, 1);
	}while((accStatus & LIS3DSH_STATUS_XYZ_Msk) == 0);
	return true;
}

