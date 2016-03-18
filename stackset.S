// Based on http://www.valvers.com/open-software/raspberry-pi/step02-bare-metal-programming-in-c-pt2/
.section ".text.startup"
.global _start
.global _get_stack_pointer

_start:
  ldr sp, =0x8000
  b _cstartup

_inf_loop:
  b _inf_loop

_get_stack_pointer:
  str sp,[sp]
  ldr r0,[sp]
  mov pc,lr 
