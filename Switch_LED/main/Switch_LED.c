#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main(void)
{
    // 0. create variables 
    int SW1_Status = 0;
    int LED1_status = 0;
    int SW2_Status = 0;
    int LED2_status = 0;

    // 1. Set LED pins to OUTPUT (GPIO 16, 18)
    gpio_set_direction(16, GPIO_MODE_OUTPUT);  // LED1
    gpio_set_direction(18, GPIO_MODE_OUTPUT);  // LED2

    // 2. Set Switch pins to INPUT (GPIO 15, 17)
    gpio_set_direction(15, GPIO_MODE_INPUT);   // SW1
    gpio_set_direction(17, GPIO_MODE_INPUT);   // SW2

    while(1)
    {
        // --- SW1 Control LED1 ---
        SW1_Status = gpio_get_level(15);
        LED1_status = !SW1_Status;  // กดติด ปล่อยดับ (Active LOW)
        gpio_set_level(16, LED1_status);

        // --- SW2 Control LED2 ---
        SW2_Status = gpio_get_level(17);
        LED2_status = !SW2_Status;
        gpio_set_level(18, LED2_status);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
