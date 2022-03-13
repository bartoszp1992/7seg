/*IELD
 * 7seg.c
 *
 *  Created on: 11 mar 2022
 *      Author: Bartosz
 *      varsion: 1.0
 *
 *      changelog:
 *
 */

#include "main.h"
#include "7seg.h"
#include <stdlib.h>
#include <string.h>

//variable for store actualy displayed field
volatile uint8_t actualField = FIELD_0;

//buffers storing chars and dots
uint8_t LEDbuffer[FIELDS];
uint8_t DOTbuffer[FIELDS];

static void _LEDsegmentOn(uint8_t segment);
static void _LEDfieldOn(uint8_t field);
static void _LEDallOff(void);
static void _LEDwriteCharacter(uint8_t character);


void LEDmultiplexing(void) {
	actualField++;
	if (actualField >= FIELDS)
		actualField = 0;

	_LEDallOff();
	_LEDfieldOn(actualField);
	_LEDwriteCharacter(LEDbuffer[actualField]);

	if (DOTbuffer[actualField] == 1) {
		HAL_GPIO_WritePin(DISP_SEG_DOT_GPIO_Port, DISP_SEG_DOT_Pin, SEGMENT_ON);
	}
}

static void _LEDsegmentOn(uint8_t segment) {

	if (segment == DISP_SEG_A)
		HAL_GPIO_WritePin(DISP_SEG_A_GPIO_Port, DISP_SEG_A_Pin, SEGMENT_ON);
	else if (segment == DISP_SEG_B)
		HAL_GPIO_WritePin(DISP_SEG_B_GPIO_Port, DISP_SEG_B_Pin, SEGMENT_ON);
	else if (segment == DISP_SEG_C)
		HAL_GPIO_WritePin(DISP_SEG_C_GPIO_Port, DISP_SEG_C_Pin, SEGMENT_ON);
	else if (segment == DISP_SEG_D)
		HAL_GPIO_WritePin(DISP_SEG_D_GPIO_Port, DISP_SEG_D_Pin, SEGMENT_ON);
	else if (segment == DISP_SEG_E)
		HAL_GPIO_WritePin(DISP_SEG_E_GPIO_Port, DISP_SEG_E_Pin, SEGMENT_ON);
	else if (segment == DISP_SEG_F)
		HAL_GPIO_WritePin(DISP_SEG_F_GPIO_Port, DISP_SEG_F_Pin, SEGMENT_ON);
	else if (segment == DISP_SEG_G)
		HAL_GPIO_WritePin(DISP_SEG_G_GPIO_Port, DISP_SEG_G_Pin, SEGMENT_ON);
	else if (segment == DISP_SEG_DOT)
		HAL_GPIO_WritePin(DISP_SEG_DOT_GPIO_Port, DISP_SEG_DOT_Pin, SEGMENT_ON);
}

static void _LEDfieldOn(uint8_t field) {

#if FIELDS >=1
	if (field == FIELD_0)
		HAL_GPIO_WritePin(DISP_FIELD_0_GPIO_Port, DISP_FIELD_0_Pin, FIELD_ON);
#endif

#if FIELDS >=2
	else if (field == FIELD_1)
		HAL_GPIO_WritePin(DISP_FIELD_1_GPIO_Port, DISP_FIELD_1_Pin, FIELD_ON);
#endif

#if FIELDS >=3
	else if (field == FIELD_2)
		HAL_GPIO_WritePin(DISP_FIELD_2_GPIO_Port, DISP_FIELD_2_Pin, FIELD_ON);
#endif

#if FIELDS >=4
	else if (field == FIELD_3)
		HAL_GPIO_WritePin(DISP_FIELD_3_GPIO_Port, DISP_FIELD_3_Pin, FIELD_ON);
#endif
}

static void _LEDallOff(void) {

#if FIELDS >=1
	HAL_GPIO_WritePin(DISP_FIELD_0_GPIO_Port, DISP_FIELD_0_Pin, FIELD_OFF);
#endif
#if FIELDS >=2
	HAL_GPIO_WritePin(DISP_FIELD_1_GPIO_Port, DISP_FIELD_1_Pin, FIELD_OFF);
#endif
#if FIELDS >=3
	HAL_GPIO_WritePin(DISP_FIELD_2_GPIO_Port, DISP_FIELD_2_Pin, FIELD_OFF);
#endif
#if FIELDS >=4
	HAL_GPIO_WritePin(DISP_FIELD_3_GPIO_Port, DISP_FIELD_3_Pin, FIELD_OFF);
#endif

	HAL_GPIO_WritePin(DISP_SEG_A_GPIO_Port, DISP_SEG_A_Pin, SEGMENT_OFF);
	HAL_GPIO_WritePin(DISP_SEG_B_GPIO_Port, DISP_SEG_B_Pin, SEGMENT_OFF);
	HAL_GPIO_WritePin(DISP_SEG_C_GPIO_Port, DISP_SEG_C_Pin, SEGMENT_OFF);
	HAL_GPIO_WritePin(DISP_SEG_D_GPIO_Port, DISP_SEG_D_Pin, SEGMENT_OFF);
	HAL_GPIO_WritePin(DISP_SEG_E_GPIO_Port, DISP_SEG_E_Pin, SEGMENT_OFF);
	HAL_GPIO_WritePin(DISP_SEG_F_GPIO_Port, DISP_SEG_F_Pin, SEGMENT_OFF);
	HAL_GPIO_WritePin(DISP_SEG_G_GPIO_Port, DISP_SEG_G_Pin, SEGMENT_OFF);
	HAL_GPIO_WritePin(DISP_SEG_DOT_GPIO_Port, DISP_SEG_DOT_Pin, SEGMENT_OFF);

}

static void _LEDwriteCharacter(uint8_t character) {

	if (character == 1 || character == '1') {
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
	} else if (character == 2 || character == '2') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_G);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_D);
	} else if (character == 3 || character == '3') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_G);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
	} else if (character == 4 || character == '4') {
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
	} else if (character == 5 || character == '5') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
	} else if (character == 6 || character == '6') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 7 || character == '7') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
	} else if (character == 8 || character == '8') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 9 || character == '9') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 0 || character == '0') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
	} else if (character == 'A') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 'C') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
	} else if (character == 'E') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 'F') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 'H') {
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 'J') {
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
	} else if (character == 'L') {
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
	} else if (character == 'P') {
		_LEDsegmentOn(DISP_SEG_A);
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
		_LEDsegmentOn(DISP_SEG_G);
	} else if (character == 'U') {
		_LEDsegmentOn(DISP_SEG_B);
		_LEDsegmentOn(DISP_SEG_C);
		_LEDsegmentOn(DISP_SEG_D);
		_LEDsegmentOn(DISP_SEG_E);
		_LEDsegmentOn(DISP_SEG_F);
	} else if (character == '-') {
		_LEDsegmentOn(DISP_SEG_G);
	}
}

/**
 * @brief  Initialise 7 segment display
 *
 * @note   clear display
 *
 * @param  None
 *
 * @retval None
 */
void LEDinit(void) {
	LEDclear();
}

/**
 * @brief  Show one char on selected field
 *
 * @note   Offset starts from 0
 *
 * @param  selected field
 *
 * @param character to display
 *
 * @retval None
 */
void LEDchar(uint8_t offset, uint8_t character) {
	LEDbuffer[offset] = character;
}

/**
 * @brief  Show integer starting at selected field
 *
 * @note   Offset starts from 0
 *
 * @param  cursor position
 *
 * @param  number for display
 *
 * @retval None
 */
void LEDint(uint8_t offset, uint16_t number) {

	if (number > MAX_NUMBER)
		number = MAX_NUMBER;

	//determine size of destination place
	uint8_t size;
	if (number < 10)
		size = 1;
	else if (number < 100)
		size = 2;
	else if (number < 1000)
		size = 3;
	else if (number < 10000)
		size = 4;

	char buffer[5];

	itoa(number, buffer, 10);
	memcpy(LEDbuffer, buffer, size);

}

/**
 * @brief  Clear whole display
 *
 * @note   None
 *
 * @param  None
 *
 * @retval None
 */
void LEDclear(void) {
	memset(LEDbuffer, ' ', FIELDS);
	memset(DOTbuffer, 0, FIELDS);
}

/**
 * @brief  Show dot on selected field
 *
 * @note   Offset starts from 0
 *
 * @param  cursor position
 *
 * @param  DOT_ACTIVE or DOT_INACTIVE
 *
 * @retval None
 */
void LEDdot(uint8_t dotNum, uint8_t active) {
	if (active == DOT_ACTIVE)
		DOTbuffer[dotNum] = 1;
	else if (active == DOT_INACTIVE)
		DOTbuffer[dotNum] = 0;
}

