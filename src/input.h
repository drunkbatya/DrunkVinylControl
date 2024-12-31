#pragma once
#include "stm32f4xx_ll_tim.h"

#define DeckBBtn5_Pin LL_GPIO_PIN_3
#define DeckBBtn5_GPIO_Port GPIOA
#define DeckBBtn4_Pin LL_GPIO_PIN_4
#define DeckBBtn4_GPIO_Port GPIOA
#define DeckBEncBtn_Pin LL_GPIO_PIN_5
#define DeckBEncBtn_GPIO_Port GPIOA
#define DeckBEncA_Pin LL_GPIO_PIN_6
#define DeckBEncA_GPIO_Port GPIOA
#define DeckBEncB_Pin LL_GPIO_PIN_7
#define DeckBEncB_GPIO_Port GPIOA
#define DeckBBtn3_Pin LL_GPIO_PIN_0
#define DeckBBtn3_GPIO_Port GPIOB
#define DeckBBtn2_Pin LL_GPIO_PIN_1
#define DeckBBtn2_GPIO_Port GPIOB
#define DeckBBtn1_Pin LL_GPIO_PIN_2
#define DeckBBtn1_GPIO_Port GPIOB
#define DeckABtn5_Pin LL_GPIO_PIN_10
#define DeckABtn5_GPIO_Port GPIOB
#define DeckABtn4_Pin LL_GPIO_PIN_12
#define DeckABtn4_GPIO_Port GPIOB
#define DeckABtn3_Pin LL_GPIO_PIN_13
#define DeckABtn3_GPIO_Port GPIOB
#define DeckABtn2_Pin LL_GPIO_PIN_14
#define DeckABtn2_GPIO_Port GPIOB
#define DeckABtn1_Pin LL_GPIO_PIN_15
#define DeckABtn1_GPIO_Port GPIOB
#define DeckAEncA_Pin LL_GPIO_PIN_8
#define DeckAEncA_GPIO_Port GPIOA
#define DeckAEncB_Pin LL_GPIO_PIN_9
#define DeckAEncB_GPIO_Port GPIOA
#define DeckAEncBtn_Pin LL_GPIO_PIN_10
#define DeckAEncBtn_GPIO_Port GPIOA

typedef enum {
    InputKeyDeckAEncBtn,
    InputKeyDeckA0,
    InputKeyDeckA1,
    InputKeyDeckA2,
    InputKeyDeckA3,
    InputKeyDeckA4,
    InputKeyDeckBEncBtn,
    InputKeyDeckB0,
    InputKeyDeckB1,
    InputKeyDeckB2,
    InputKeyDeckB3,
    InputKeyDeckB4,
    InputKeysCount
} InputKey;

typedef enum {
    InputEncoderDeckA,
    InputEncoderDeckB,
    InputEncodersCount
} InputEncoder;

typedef struct {
    GPIO_TypeDef* port;
    uint32_t pin;
} GPIOButton;

typedef struct {
    TIM_TypeDef* timer;
} GPIOEncoder;

typedef struct {
    uint8_t button_state[InputKeysCount];
    uint16_t encoder_state[InputEncodersCount];
} InputState;

void input_init(void);
void input_get_state(InputState* input_state);
