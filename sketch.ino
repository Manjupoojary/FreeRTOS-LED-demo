#include <Arduino.h>  
#include <Arduino_FreeRTOS.h>  
#include <task.h>  

// Task 1: Blink LED  
void TaskBlink(void *pvParam) {  
  pinMode(13, OUTPUT);  
  while (1) {  
    digitalWrite(13, !digitalRead(13)); // Toggle LED  
    vTaskDelay(500 / portTICK_PERIOD_MS); // 500ms delay  
  }  
}  

// Task 2: Print to Serial  
void TaskPrint(void *pvParam) {  
  while (1) {  
    Serial.println("Hello from FreeRTOS!");  
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1s delay  
  }  
}  

void setup() {  
  Serial.begin(9600);  
  // Create tasks  
  xTaskCreate(TaskBlink, "Blink", 128, NULL, 1, NULL);  
  xTaskCreate(TaskPrint, "Print", 128, NULL, 1, NULL);  
  // Note: Arduino's loop() is unused in FreeRTOS  
}  

void loop() {}  