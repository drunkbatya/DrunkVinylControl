#include "input.h"

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"

static void MX_TIM1_Init(void) {
    LL_TIM_InitTypeDef TIM_InitStruct = {0};
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    GPIO_InitStruct.Pin = DeckAEncA_Pin | DeckAEncB_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_1;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    LL_TIM_SetEncoderMode(TIM1, LL_TIM_ENCODERMODE_X2_TI1);
    LL_TIM_IC_SetActiveInput(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_ACTIVEINPUT_DIRECTTI);
    LL_TIM_IC_SetPrescaler(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_ICPSC_DIV1);
    LL_TIM_IC_SetFilter(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_IC_FILTER_FDIV1);
    LL_TIM_IC_SetPolarity(TIM1, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING);
    LL_TIM_IC_SetActiveInput(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_ACTIVEINPUT_DIRECTTI);
    LL_TIM_IC_SetPrescaler(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_ICPSC_DIV1);
    LL_TIM_IC_SetFilter(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_IC_FILTER_FDIV1);
    LL_TIM_IC_SetPolarity(TIM1, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_RISING);
    TIM_InitStruct.Prescaler = 0;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = 65535;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    TIM_InitStruct.RepetitionCounter = 0;
    LL_TIM_Init(TIM1, &TIM_InitStruct);
    LL_TIM_DisableARRPreload(TIM1);
    LL_TIM_SetTriggerOutput(TIM1, LL_TIM_TRGO_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM1);
    LL_TIM_EnableCounter(TIM1);
}

static void MX_TIM3_Init(void) {
    LL_TIM_InitTypeDef TIM_InitStruct = {0};
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    GPIO_InitStruct.Pin = DeckBEncA_Pin | DeckBEncB_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    LL_TIM_SetEncoderMode(TIM3, LL_TIM_ENCODERMODE_X2_TI1);
    LL_TIM_IC_SetActiveInput(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_ACTIVEINPUT_DIRECTTI);
    LL_TIM_IC_SetPrescaler(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_ICPSC_DIV1);
    LL_TIM_IC_SetFilter(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_IC_FILTER_FDIV1);
    LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING);
    LL_TIM_IC_SetActiveInput(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_ACTIVEINPUT_DIRECTTI);
    LL_TIM_IC_SetPrescaler(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_ICPSC_DIV1);
    LL_TIM_IC_SetFilter(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_IC_FILTER_FDIV1);
    LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_RISING);
    TIM_InitStruct.Prescaler = 0;
    TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
    TIM_InitStruct.Autoreload = 65535;
    TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
    LL_TIM_Init(TIM3, &TIM_InitStruct);
    LL_TIM_DisableARRPreload(TIM3);
    LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);
    LL_TIM_DisableMasterSlaveMode(TIM3);
    LL_TIM_EnableCounter(TIM3);
}

static void MX_GPIO_Init(void) {
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

    GPIO_InitStruct.Pin = DeckABtn5_Pin | DeckBBtn4_Pin | DeckBEncBtn_Pin | DeckAEncBtn_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = DeckBBtn3_Pin | DeckBBtn2_Pin | DeckBBtn1_Pin | DeckBBtn5_Pin |
                          DeckABtn4_Pin | DeckABtn3_Pin | DeckABtn2_Pin | DeckABtn1_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

static const GPIOButton gpio_buttons[InputKeysCount] = {
    {.pin = DeckAEncBtn_Pin, .port = DeckAEncBtn_GPIO_Port},
    {.pin = DeckABtn1_Pin, .port = DeckABtn1_GPIO_Port},
    {.pin = DeckABtn2_Pin, .port = DeckABtn2_GPIO_Port},
    {.pin = DeckABtn3_Pin, .port = DeckABtn3_GPIO_Port},
    {.pin = DeckABtn4_Pin, .port = DeckABtn4_GPIO_Port},
    {.pin = DeckABtn5_Pin, .port = DeckABtn5_GPIO_Port},
    {.pin = DeckBEncBtn_Pin, .port = DeckBEncBtn_GPIO_Port},
    {.pin = DeckBBtn1_Pin, .port = DeckBBtn1_GPIO_Port},
    {.pin = DeckBBtn2_Pin, .port = DeckBBtn2_GPIO_Port},
    {.pin = DeckBBtn3_Pin, .port = DeckBBtn3_GPIO_Port},
    {.pin = DeckBBtn4_Pin, .port = DeckBBtn4_GPIO_Port},
    {.pin = DeckBBtn5_Pin, .port = DeckBBtn5_GPIO_Port},
};

static const GPIOEncoder gpio_encoders[InputEncodersCount] = {
    {.timer = TIM1},
    {.timer = TIM3},
};

void input_get_state(InputState* input_state) {
    // buttons
    for(uint8_t i = 0; i < InputKeysCount; i++) {
        input_state->button_state[i] = !LL_GPIO_IsInputPinSet(gpio_buttons[i].port, gpio_buttons[i].pin);  // Pull up
    }

    // encoders
    for(uint8_t i = 0; i < InputEncodersCount; i++) {
        uint16_t encoder_value = LL_TIM_GetCounter(gpio_encoders[i].timer);
        input_state->encoder_state[i] = 32767 + ((encoder_value-1) & 0xFFFF) / 2;
    }
}

void input_init(void) {
    MX_GPIO_Init();
    MX_TIM1_Init();
    MX_TIM3_Init();
}
