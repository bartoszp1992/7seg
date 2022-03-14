/*IELD
 * 7seg.c
 *
 *  Created on: 11 mar 2022
 *      Author: Bartosz
 *      varsion: 1.3
 *
 *      changelog:
 *      1.3 - display as structure
 *
 */

#include "main.h"
#include "7seg.h"
#include <stdlib.h>
#include <string.h>



static void _LEDsegmentOn(LEDdisplayTypeDef* LEDdisplay, uint8_t segment);
static void _LEDfieldOn(LEDdisplayTypeDef* LEDdisplay, uint8_t field);
static void _LEDallOff(LEDdisplayTypeDef* LEDdisplay);
static void _LEDwriteCharacter(LEDdisplayTypeDef* LEDdisplay, uint8_t character);


void LEDmultiplexing(LEDdisplayTypeDef* LEDdisplay) {
	LEDdisplay->actualField++;
	if (LEDdisplay->actualField >= FIELDS)
		LEDdisplay->actualField = 0;

	_LEDallOff(LEDdisplay);
	_LEDfieldOn(LEDdisplay, LEDdisplay->actualField);
	_LEDwriteCharacter(LEDdisplay, LEDdisplay->LEDbuffer[LEDdisplay->actualField]);

	if (LEDdisplay->DOTbuffer[LEDdisplay->actualField] == 1) {
		HAL_GPIO_WritePin(LEDdisplay->SegDOTPort, LEDdisplay->SegDOTPin, SEGMENT_ON);
	}
}

static void _LEDsegmentOn(LEDdisplayTypeDef* LEDdisplay, uint8_t segment) {

	if (segment == DISP_SEG_A)
		HAL_GPIO_WritePin(LEDdisplay->SegAPort, LEDdisplay->SegAPin, SEGMENT_ON);
	else if (segment == DISP_SEG_B)
		HAL_GPIO_WritePin(LEDdisplay->SegBPort, LEDdisplay->SegBPin, SEGMENT_ON);
	else if (segment == DISP_SEG_C)
		HAL_GPIO_WritePin(LEDdisplay->SegCPort, LEDdisplay->SegCPin, SEGMENT_ON);
	else if (segment == DISP_SEG_D)
		HAL_GPIO_WritePin(LEDdisplay->SegDPort, LEDdisplay->SegDPin, SEGMENT_ON);
	else if (segment == DISP_SEG_E)
		HAL_GPIO_WritePin(LEDdisplay->SegEPort, LEDdisplay->SegEPin, SEGMENT_ON);
	else if (segment == DISP_SEG_F)
		HAL_GPIO_WritePin(LEDdisplay->SegFPort, LEDdisplay->SegFPin, SEGMENT_ON);
	else if (segment == DISP_SEG_G)
		HAL_GPIO_WritePin(LEDdisplay->SegGPort, LEDdisplay->SegGPin, SEGMENT_ON);
	else if (segment == DISP_SEG_DOT)
		HAL_GPIO_WritePin(LEDdisplay->SegDOTPort, LEDdisplay->SegDOTPin, SEGMENT_ON);
}

static void _LEDfieldOn(LEDdisplayTypeDef* LEDdisplay, uint8_t field) {

#if FIELDS >=1
	if (field == FIELD_0)
		HAL_GPIO_WritePin(LEDdisplay->Field0Port, LEDdisplay->Field0Pin, FIELD_ON);
#endif

#if FIELDS >=2
	else if (field == FIELD_1)
		HAL_GPIO_WritePin(LEDdisplay->Field1Port, LEDdisplay->Field1Pin, FIELD_ON);
#endif

#if FIELDS >=3
	else if (field == FIELD_2)
		HAL_GPIO_WritePin(LEDdisplay->Field2Port, LEDdisplay->Field2Pin, FIELD_ON);
#endif

#if FIELDS >=4
	else if (field == FIELD_3)
		HAL_GPIO_WritePin(LEDdisplay->Field3Port, LEDdisplay->Field3Pin, FIELD_ON);
#endif
}

static void _LEDallOff(LEDdisplayTypeDef* LEDdisplay) {

#if FIELDS >=1
	HAL_GPIO_WritePin(LEDdisplay->Field0Port, LEDdisplay->Field0Pin, FIELD_OFF);
#endif
#if FIELDS >=2
	HAL_GPIO_WritePin(LEDdisplay->Field1Port, LEDdisplay->Field1Pin, FIELD_OFF);
#endif
#if FIELDS >=3
	HAL_GPIO_WritePin(LEDdisplay->Field2Port, LEDdisplay->Field2Pin, FIELD_OFF);
#endif
#if FIELDS >=4
	HAL_GPIO_WritePin(LEDdisplay->Field3Port, LEDdisplay->Field3Pin, FIELD_OFF);
#endif

	HAL_GPIO_WritePin(LEDdisplay->SegAPort, LEDdisplay->SegAPin, SEGMENT_OFF);
	HAL_GPIO_WritePin(LEDdisplay->SegBPort, LEDdisplay->SegBPin, SEGMENT_OFF);
	HAL_GPIO_WritePin(LEDdisplay->SegCPort, LEDdisplay->SegCPin, SEGMENT_OFF);
	HAL_GPIO_WritePin(LEDdisplay->SegDPort, LEDdisplay->SegDPin, SEGMENT_OFF);
	HAL_GPIO_WritePin(LEDdisplay->SegEPort, LEDdisplay->SegEPin, SEGMENT_OFF);
	HAL_GPIO_WritePin(LEDdisplay->SegFPort, LEDdisplay->SegFPin, SEGMENT_OFF);
	HAL_GPIO_WritePin(LEDdisplay->SegGPort, LEDdisplay->SegGPin, SEGMENT_OFF);
	HAL_GPIO_WritePin(LEDdisplay->SegDOTPort, LEDdisplay->SegDOTPin, SEGMENT_OFF);

}

static void _LEDwriteCharacter(LEDdisplayTypeDef* LEDdisplay, uint8_t character) {

	if (character >= 48 && character <= 57) {
		switch (character) {
		case '1':

			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			break;
		case '2':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			break;
		case '3':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			break;
		case '4':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			break;
		case '5':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			break;
		case '6':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case '7':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			break;
		case '8':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case '9':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case '0':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			break;
		}
	} else {
		switch (character){
		case 'A':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case 'C':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			break;
		case 'E':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case 'F':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case 'H':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case 'J':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			break;
		case 'L':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			break;
		case 'P':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_A);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		case 'U':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_B);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_C);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_D);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_E);
			_LEDsegmentOn(LEDdisplay, DISP_SEG_F);
			break;
		case '-':
			_LEDsegmentOn(LEDdisplay, DISP_SEG_G);
			break;
		}
	}
}

/**
 * @brief  Initialise 7 segment display
 *
 * @note   clear display
 *
 * @param  Display handler
 *
 * @retval None
 */
void LEDinit(LEDdisplayTypeDef* LEDdisplay) {

	LEDclear(LEDdisplay);
	LEDdisplay->actualField = FIELD_0;
}

/**
 * @brief  Show one char on selected field
 *
 * @note   Offset starts from 0
 *
 * @param  Display handler
 *
 * @param  selected field
 *
 * @param character to display
 *
 * @retval None
 */
void LEDchar(LEDdisplayTypeDef* LEDdisplay, uint8_t offset, uint8_t character) {
	LEDdisplay->LEDbuffer[offset] = character;
}

/**
 * @brief  Show integer starting at selected field
 *
 * @note   Offset starts from 0
 *
 * @param  Display handler
 *
 * @param  cursor position
 *
 * @param  number for display
 *
 * @retval None
 */
void LEDint(LEDdisplayTypeDef* LEDdisplay, uint8_t offset, uint16_t number) {

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
	memcpy(LEDdisplay->LEDbuffer, buffer, size);

}

/**
 * @brief  Clear whole display
 *
 * @note   None
 *
 * @param  Display handler
 *
 * @retval None
 */
void LEDclear(LEDdisplayTypeDef* LEDdisplay) {
	memset(LEDdisplay->LEDbuffer, ' ', FIELDS);
	memset(LEDdisplay->DOTbuffer, 0, FIELDS);
}

/**
 * @brief  Show dot on selected field
 *
 * @note   Offset starts from 0
 *
 * @param  Display handler
 *
 * @param  cursor position
 *
 * @param  DOT_ACTIVE or DOT_INACTIVE
 *
 * @retval None
 */
void LEDdot(LEDdisplayTypeDef* LEDdisplay, uint8_t dotNum, uint8_t active) {
	if (active == DOT_ACTIVE)
		LEDdisplay->DOTbuffer[dotNum] = 1;
	else if (active == DOT_INACTIVE)
		LEDdisplay->DOTbuffer[dotNum] = 0;
}

