/**
 * @file lm35.c
 * @brief Implementation of the LM35 temperature sensor library.
 */

#include "lm35.h"
#include "main.h"
// ========================== PRIVATE VARIABLES ==========================
// No private variables needed for now

// ========================== PUBLIC FUNCTIONS ==========================

/**
 * @brief Initialize the LM35 sensor.
 *
 * Configures the ADC peripheral for the given ADC instance and channel.
 * This function also performs calibration and starts the ADC conversion.
 */
void LM35_Init(void) {
    // Initialize the ADC hardware
    HAL_ADC_Init(&LM35_ADC);

    // Perform calibration
    HAL_ADCEx_Calibration_Start(&LM35_ADC);

    // Start the ADC conversion process
    HAL_ADC_Start(&LM35_ADC);
}

/**
 * @brief Read the current temperature from the LM35 sensor.
 *
 * This function reads the ADC value, converts it to voltage, and then calculates
 * the temperature in degrees Celsius based on the LM35 sensor's linear response.
 *
 * @return Temperature in degrees Celsius. Returns -1 if an error occurs.
 */
float LM35_GetTemperature(void) {
    uint32_t adc_value; // Raw ADC value
    float temperature;  // Calculated temperature

    // Wait for ADC conversion to complete
    if (HAL_ADC_PollForConversion(&LM35_ADC, 100) == HAL_OK) {
        // Get the raw ADC value
        adc_value = HAL_ADC_GetValue(&LM35_ADC);

        // Convert ADC value to voltage and calculate temperature
        temperature = (float)(adc_value * 3.3 / 4095.0) * 100.0;
    } else {
        // Return error value in case of failure
        temperature = -1;
    }

    return temperature;
}

/*-------------------------   EXAMPLE -----------------------------------------------*/

/*

#include "lm35.h"
#include "uart.h"
#include "stdio.h"

char buffer[50];  // Buffer for UART messages
float temperature; // Variable to store the read temperature

int main(void) {
    // Initialize the HAL library and system clock
    HAL_Init();
    SystemClock_Config();

    // Initialize peripherals
    LM35_Init();  // Initialize LM35 sensor

    // Send a startup message via UART
    uartx_write_text(&huart1, "LM35 Temperature Sensor Initialized!\r\n");

    while (1) {
        // Read the current temperature
        temperature = LM35_GetTemperature();

        // Format the temperature value into a string
        sprintf(buffer, "Current Temperature: %.2f°C\r\n", temperature);

        // Send the temperature reading over UART
        uartx_write_text(&huart1, buffer);

        // Wait for 1 second
        HAL_Delay(1000);
    }
}


   */
