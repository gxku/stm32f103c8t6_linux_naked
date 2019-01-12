.text
.globl _start 

_start:
    .word 0x20000000+20480 /*sram form 0x20000000,size 20K*/
    .word main

