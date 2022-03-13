/*
 * 7seg.h
 *
 *  Created on: 11 mar 2022
 *      Author: bartosz
 */


#ifndef SRC_7DISP_SEG_7DISP_SEG_H_
#define SRC_7DISP_SEG_7DISP_SEG_H_


//USER CONFIGURATION
 //set 0 for common cathode
#define COMMON_ANODE 1
//number of fields
#define FIELDS 4
//used timer handler
#define MULTIPLEXING_TIMER &htim1
//used timer number
#define MULTIPLEXING_TIMER_NUMBER TIM1
//END OF USER CONFIGURATION

extern TIM_HandleTypeDef htim1;

#if FIELDS == 1
#define MAX_NUMBER 9
#endif

#if FIELDS == 2
#define MAX_NUMBER 99
#endif

#if FIELDS == 3
#define MAX_NUMBER 999
#endif

#if FIELDS == 4
#define MAX_NUMBER 9999
#endif



#if COMMON_ANODE == 1

#define FIELD_ON 1
#define FIELD_OFF 0

#define SEGMENT_ON 0
#define SEGMENT_OFF 1

#else

#define FIELD_ON 0
#define FIELD_OFF 1

#define SEGMENT_ON 1
#define SEGMENT_OFF 0

#endif

#define DISP_SEG_A 1
#define DISP_SEG_B 2
#define DISP_SEG_C 3
#define DISP_SEG_D 4
#define DISP_SEG_E 5
#define DISP_SEG_F 6
#define DISP_SEG_G 7
#define DISP_SEG_DOT 8

#define DOT_ACTIVE 1
#define DOT_INACTIVE 0

#if FIELDS >= 1
#define FIELD_0 0
#endif
#if FIELDS >=2
#define FIELD_1 1
#endif
#if FIELDS >= 3
#define FIELD_2 2
#endif
#if FIELDS >= 4
#define FIELD_3 3
#endif

void __LEDsegmentOn(uint8_t segment);
void __LEDfieldOn(uint8_t field);
void __LEDallOff(void);
void __LEDwriteCharacter(uint8_t character);

void LEDinit(void);
void LEDchar(uint8_t offset, uint8_t digit);
void LEDint(uint8_t offset, uint16_t number);
void LEDclear(void);
void LEDdot(uint8_t dotNum, uint8_t active);

#endif /* SRC_7DISP_SEG_7DISP_SEG_H_ */
