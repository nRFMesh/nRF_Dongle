#include "mbed.h"

DigitalOut  led_r(LED1);
DigitalOut  led_g(LED2);
DigitalOut  led_b(LED3);

Serial   pc(USBTX, USBRX, 38400);

int main() 
{
    pc.printf("Hello from the nRF Dongle\n");
    int loop = 0;
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
        pc.printf("Hello from nRF loop %d\n",loop++);
      }
}
