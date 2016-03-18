// Based on http://www.valvers.com/open-software/raspberry-pi/step01-bare-metal-programming-in-cpt1/
// Moonrat -- for RPi 1
// GPIO base address (ARM physical) 0x20200000
#include "gpio.h";
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;
//volatile unigned int tim; //loop var
//int main(void) __attribute__((naked));
void kernel_main(unsigned int r0, unsigned int r1, unsigned int atags) {

//gpio = (unsigned int*)GPIO_BASE; // GPIO address

gpio[1] |= (1 << 18);

while (1) {
  delay(500000);
  gpio[LED_GPCLR] = (1 << LED_GPIO_BIT); // Set GPIO16 high; turns LED on.
  delay(500000);
  gpio[LED_GPSET] = (1 << LED_GPIO_BIT); // Set GPIO16 low; turns LED off.
  int i = 0;
  for (i = 0; i< 500000; i++)
    ;
  gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);
}

}
void delay(int number) {
  int i = 0;
  for (i = 0; i< 500000; i++)
    ; // make the pi count to number
}

