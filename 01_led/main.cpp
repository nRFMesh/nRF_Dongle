#include "mbed.h"

int main() 
{
  DigitalOut  led_r(LED1);
  DigitalOut  led_g(LED2);
  DigitalOut  led_b(LED3);
  
  while(1) 
  {
    led_r = 0;      
    led_g = 0;      
    led_b = 0;      
    wait_ms(500);   
    led_r = 1;      
    wait_ms(500);   
    led_g = 1;      
    wait_ms(500);   
    led_b = 1;      
    wait_ms(1000);  
  }
}
