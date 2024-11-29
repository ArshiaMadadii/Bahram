/**
 * @file lm35.h
 * @brief A library for interfacing with the LM35 temperature sensor using STM32.
 *
 * This library provides a clean and flexible API for reading temperatures
 * from the LM35 sensor, allowing users to customize ADC channels and ports.
 *
 * Features:
 *  - Easy ADC and channel configuration
 *  - Modular and extendable design
 *  - Clear and descriptive function names
 *
 * @author Arshia Madadi
 * @date 11/29/2024
 */

#ifndef LM35_H
#define LM35_H

#include "stm32f1xx_hal.h"
#include "main.h"
// ========================== CONFIGURATION SECTION ==========================

/**
 * @brief Default ADC instance used for reading LM35 values.
 *        You can override this definition in your application if needed.
 */
#ifndef LM35_ADC
#define LM35_ADC  hadc1  // Default: ADC1
#endif
/**
 extern ADC_HandleTypeDef hadc1;  // Declare ADC1 globally to main.h

 * */
/**
 * @brief Default ADC channel used for LM35. Override this if needed.
 */
#ifndef LM35_CHANNEL
#define LM35_CHANNEL ADC_CHANNEL_9 // Default: Channel 1
#endif

// ========================== FUNCTION DECLARATIONS ==========================

/**
 * @brief Initialize the LM35 sensor.
 *
 * This function initializes the ADC instance and starts calibration. It
 * should be called once before using any other LM35 functions.
 */
void LM35_Init(void);

/**
 * @brief Read the current temperature from the LM35 sensor.
 *
 * @return Temperature in degrees Celsius as a floating-point value.
 */
float LM35_GetTemperature(void);

#endif /* LM35_H */
