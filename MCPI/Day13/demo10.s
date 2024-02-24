/* *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
**  Micro-Controller : LM3SXXXX 
*************************************************************************
*/

/* Stack */

.syntax unified

.global pfnVectors
.global Default_Handler
.global _start
.equ Top_Of_Stack, 0x20002000    /* end of 8K RAM */

.global sdata
.global edata
.global etext
.global sbss
.global ebss

.section .vectors
vectors:
	.word Top_Of_Stack          @ msp = 0x20002000
	.word _start                @ Starting Program address
	.word Default_Handler	    @ NMI_Handler
	.word Default_Handler	    @ HardFault_Handler
	.word Default_Handler	    @ MemManage_Handler
	.word Default_Handler	    @ BusFault_Handler
	.word Default_Handler	    @ UsageFault_Handler
	.word 0                     @ 7
	.word 0                     @ To
	.word 0                     @ 10 
	.word 0                     @ Reserved
	.word Default_Handler	    	@ SVC_Handler
	.word Default_Handler	    @ DebugMon_Handler
	.word 0                     @ Reserved
	.word Default_Handler	    @ PendSV_Handler
	.word Default_Handler	    @ SysTick_Handler
	.word Default_Handler	    @ IRQ_Handler
	.word Default_Handler	    @ IRQ_Handler

.section .rodata


.section .data


.section .bss


.section .text

.thumb
/**
 * This is the code that gets called when the processor first
 * starts execution following a reset. 
*/
.type _start, %function
_start:                              @ _start label is required by the linker

	//init .data section
	ldr r7, =etext
	ldr r6, =sdata
	ldr r5, =edata
	mov r4, #0
data_init:
	cmp r6, r5
	beq data_init_end
	ldrb r4, [r7], #1
	strb r4, [r6], #1
	b data_init
data_init_end:

	//clear .bss section
	ldr r6, =sbss
	ldr r7, =ebss
	mov r4, #0
bss_init:
	cmp r6, r7
	beq bss_init_end
	strb r4, [r6], #1
	b bss_init
bss_init_end:

	bl main
	stop:   b stop

/***************************************************************/
.global main
.type main, %function
main:                              

//method 1:
	mov r4, #0
	mov r5, #0
	mov r6, #0
	@ push three registers on stack
	mov r1, #11
	mov r2, #22
	mov r3, #33
	stmdb sp!, {r1-r3}
	@ pop three registers from stack
	ldmia sp!, {r4-r6}
		@ output: r4=11, r5=22, r6=33

//method 2:
	mov r4, #0
	mov r5, #0
	mov r6, #0
	@ push three registers on stack
	mov r1, #10
	mov r2, #20
	mov r3, #30
	stmfd sp!, {r1-r3}
	@ pop three registers from stack
	ldmfd sp!, {r4-r6}
		@ output: r4=11, r5=22, r6=33

//method 3:
	mov r4, #0
	mov r5, #0
	mov r6, #0
	@ push three registers on stack
	mov r1, #100
	mov r2, #200
	mov r3, #300
	push {r1-r3}
	@ pop three registers from stack
	pop {r4-r6}
		@ output: r4=11, r5=22, r6=33

	mov pc, lr

/***************************************************************/

.type Default_Handler, %function
Default_Handler:
	halt: b halt

.end

