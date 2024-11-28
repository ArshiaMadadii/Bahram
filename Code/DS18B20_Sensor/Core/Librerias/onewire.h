

#include "puertos.h"
#include "delays.h"
#include "main.h"

#define onewire_Pin GPIO_PIN_1
#define onewire_GPIO_Port GPIOA





uint8_t onewire_reset ();
void onewire_Write (uint8_t dato);
uint8_t onewire_Read();

