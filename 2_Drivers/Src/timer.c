#include "timer.h"

#include "hal_rcc.h"
#include "hal_gpio.h"
#include "drv_sysclk.h"
#include "drv_systick.h"






static timer_function_enum timer_function_state[8] = 
{
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT,
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT,
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT,
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT
};

static timer_mode_enum timer_mode_state[8] = 
{
    TIMER_SYSTEM_CLOCK, TIMER_SYSTEM_CLOCK,
    TIMER_SYSTEM_CLOCK, TIMER_SYSTEM_CLOCK,
    TIMER_SYSTEM_CLOCK, TIMER_SYSTEM_CLOCK,
    TIMER_SYSTEM_CLOCK, TIMER_SYSTEM_CLOCK
};


//-------------------------------------------------------------------------------------------------------------------
// @brief       TIMER 
// @param       index           TIMER 
// @return      void
// Sample usage:                timer_clock_enable(TIM_1);
//-------------------------------------------------------------------------------------------------------------------
void timer_clock_enable (timer_index_enum index)
{
    switch(index)
    {
        case TIM_1:
            RCC->APB2ENR |= 0x00000001;                                         // ????
            break;
        case TIM_2:
            RCC->APB1ENR |= 0x00000001;                                         // ????
            break;
        case TIM_3:
            RCC->APB1ENR |= 0x00000001 << 1;                                    // ????
            break;
        case TIM_4:
            RCC->APB1ENR |= 0x00000001 << 2;                                    // ????
            break;
        case TIM_5:
            RCC->APB1ENR |= 0x00000001 << 3;                                    // ????
            break;
        case TIM_6:
            RCC->APB1ENR |= 0x00000001 << 4;                                    // ????
            break;
        case TIM_7:
            RCC->APB1ENR |= 0x00000001 << 5;                                    // ????
            break;
        case TIM_8:
            RCC->APB2ENR |= 0x00000001 << 1;                                    // ????
            break;
        default:
            break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       TIMER 
// @param       index           TIMER 
// @return      void
// Sample usage:                timer_start(TIM_1);
//-------------------------------------------------------------------------------------------------------------------
void timer_start (timer_index_enum index)
{
    TIM1_Type *tim_index;
    switch(index)
    {
        case TIM_1: tim_index = ((TIM1_Type *)TIM1_BASE);   break;
        case TIM_2: tim_index = ((TIM1_Type *)TIM2_BASE);   break;
        case TIM_3: tim_index = ((TIM1_Type *)TIM3_BASE);   break;
        case TIM_4: tim_index = ((TIM1_Type *)TIM4_BASE);   break;
        case TIM_5: tim_index = ((TIM1_Type *)TIM5_BASE);   break;
        case TIM_6: tim_index = ((TIM1_Type *)TIM6_BASE);   break;
        case TIM_7: tim_index = ((TIM1_Type *)TIM7_BASE);   break;
        case TIM_8: tim_index = ((TIM1_Type *)TIM8_BASE);   break;
        default: return;
    }
    tim_index->CR1 |= (0x00000001);                                             // ?????
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       TIMER 
// @param       index           TIMER 
// @return      void
// Sample usage:                timer_stop(TIM_1);
//-------------------------------------------------------------------------------------------------------------------
void timer_stop (timer_index_enum index)
{
    TIM1_Type *tim_index;
    switch(index)
    {
        case TIM_1: tim_index = ((TIM1_Type *)TIM1_BASE);   break;
        case TIM_2: tim_index = ((TIM1_Type *)TIM2_BASE);   break;
        case TIM_3: tim_index = ((TIM1_Type *)TIM3_BASE);   break;
        case TIM_4: tim_index = ((TIM1_Type *)TIM4_BASE);   break;
        case TIM_5: tim_index = ((TIM1_Type *)TIM5_BASE);   break;
        case TIM_6: tim_index = ((TIM1_Type *)TIM6_BASE);   break;
        case TIM_7: tim_index = ((TIM1_Type *)TIM7_BASE);   break;
        case TIM_8: tim_index = ((TIM1_Type *)TIM8_BASE);   break;
        default: return;
    }
    tim_index->CR1 &= (0xFFFFFFFE);                                             // ?????
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       TIMER 
// @param       index           TIMER 
// @return      uint16_t          ???
// Sample usage:                timer_get(TIM_1);
//-------------------------------------------------------------------------------------------------------------------
uint16_t timer_get (timer_index_enum index)
{
    TIM1_Type *tim_index;
    switch(index)
    {
        case TIM_1: tim_index = ((TIM1_Type *)TIM1_BASE);   break;
        case TIM_2: tim_index = ((TIM1_Type *)TIM2_BASE);   break;
        case TIM_3: tim_index = ((TIM1_Type *)TIM3_BASE);   break;
        case TIM_4: tim_index = ((TIM1_Type *)TIM4_BASE);   break;
        case TIM_5: tim_index = ((TIM1_Type *)TIM5_BASE);   break;
        case TIM_6: tim_index = ((TIM1_Type *)TIM6_BASE);   break;
        case TIM_7: tim_index = ((TIM1_Type *)TIM7_BASE);   break;
        case TIM_8: tim_index = ((TIM1_Type *)TIM8_BASE);   break;
        default: return 0;
    }
    if(TIMER_MS == timer_mode_state[index])
        return (uint16_t)tim_index->CNT / 2;
    return (uint16_t)tim_index->CNT;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       TIMER 
// @param       index           TIMER 
// @return      void
// Sample usage:                timer_clear(TIM_1);
//-------------------------------------------------------------------------------------------------------------------
void timer_clear (timer_index_enum index)
{
    switch(index)
    {
        case TIM_1: TIM1->EGR |= 0x01;  break;
        case TIM_2: TIM2->EGR |= 0x01;  break;
        case TIM_3: TIM3->EGR |= 0x01;  break;
        case TIM_4: TIM4->EGR |= 0x01;  break;
        case TIM_5: TIM5->EGR |= 0x01;  break;
        case TIM_6: TIM6->EGR |= 0x01;  break;
        case TIM_7: TIM7->EGR |= 0x01;  break;
        case TIM_8: TIM8->EGR |= 0x01;  break;
        default:    break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       TIMER 
// @param       index           TIMER 
// @param       mode            
// @return      void
// Sample usage:                timer_init(TIM_1, TIMER_US);
//-------------------------------------------------------------------------------------------------------------------
void timer_init (timer_index_enum index, timer_mode_enum mode)
{
 
    
    timer_function_state[index] = TIMER_FUNCTION_TIMER;

    timer_clock_enable(index);                                                  // 
    TIM1_Type *tim_index;
    switch(index)
    {
        case TIM_1: tim_index = ((TIM1_Type *)TIM1_BASE);   break;
        case TIM_2: tim_index = ((TIM1_Type *)TIM2_BASE);   break;
        case TIM_3: tim_index = ((TIM1_Type *)TIM3_BASE);   break;
        case TIM_4: tim_index = ((TIM1_Type *)TIM4_BASE);   break;
        case TIM_5: tim_index = ((TIM1_Type *)TIM5_BASE);   break;
        case TIM_6: tim_index = ((TIM1_Type *)TIM6_BASE);   break;
        case TIM_7: tim_index = ((TIM1_Type *)TIM7_BASE);   break;
        case TIM_8: tim_index = ((TIM1_Type *)TIM8_BASE);   break;
        default: return;
    }

    timer_mode_state[index] = mode;
    switch(mode)
    {
        case TIMER_US:
            tim_index->ARR |= 0x0000FFFF;                                       // 
            
        case TIMER_MS:
            tim_index->ARR |= 0x0000FFFF;                                       // 
        default:
            tim_index->ARR |= 0x0000FFFF;                                       // 
            tim_index->PSC = 0;                                                 // 
            break;
    }

    tim_index->EGR |= 0x01;
}
