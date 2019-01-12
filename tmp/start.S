
.text
.globl _start 
.globl ymj_main

_start:
    .word 0x20000000+4096
    .word ymj_main


ymj_main_1:
    ldr r0, =#0x40021000
    ldr r1, =#0x3
    str r1, [r0]
    nop
    ldr r0, =#0x40021004
    ldr r1, =#0x0
    str r1, [r0]
    nop
    ldr r0, =#0x40021014
    ldr r1, =#0x14
    str r1, [r0]
    nop
    nop
    ldr r0, =#0x4002100c
    ldr r1, =#0xffffffff
    str r1, [r0]
    
    ldr r0, =#0x40021018
    ldr r1, =#0xffffffff
    str r1, [r0]
    
    ldr r0, =#0x4002101c
    ldr r1, =#1<<28
    str r1, [r0]

    

    ldr r0, =#0x40011004
    ldr r1, =#0x22222222
    str r1, [r0]
    
    ldr r0, =#0x40011014
    ldr r1, =#0
    str r1, [r0]
loop1:
    b loop1


