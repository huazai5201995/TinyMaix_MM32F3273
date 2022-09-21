#ifndef _timer_h_
#define _timer_h_
//  SeekFree  code
#include "hal_device_registers.h"
#include "hal_rcc.h"
#include "hal_gpio.h"


typedef enum
{
    TIM_1,
    TIM_2,
    TIM_3,
    TIM_4,
    TIM_5,
    TIM_6,
    TIM_7,
    TIM_8,
}timer_index_enum;

typedef enum
{
    TIMER_SYSTEM_CLOCK,                                                         // 
    TIMER_US,                                                                   // 
    TIMER_MS,                                                                   //
}timer_mode_enum;

typedef enum
{
    TIMER_FUNCTION_INIT = 0,                                                    // ??????
    TIMER_FUNCTION_TIMER,                                                       // ?? TIMER ??
    TIMER_FUNCTION_PIT,                                                         // ?? PIT
    TIMER_FUNCTION_PWM,                                                         // ?? PWM
    TIMER_FUNCTION_ENCODER,                                                     // ?? ENCODER
    TIMER_FUNCTION_CAMERA,                                                      // ?? CAMERA
}timer_function_enum;


typedef enum
{
    TIM_ETR_RISING,
    TIM_ETR_FALLING,
}timer_etr_mode_emun;


void        timer_clock_enable          (timer_index_enum index);

void        timer_start                 (timer_index_enum index);
void        timer_stop                  (timer_index_enum index);
extern uint16_t    timer_get                   (timer_index_enum index);
void        timer_clear                 (timer_index_enum index);


#endif
