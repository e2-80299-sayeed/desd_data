/* *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
**  Micro-Controller : LM3SXXXX *************************************************************************
*/

/* Decision control */

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
	/*
	@ condition execution of instruction is supported for ARM instructions not for Thumb instructions
	@ r3 = (r1 > r2 ? r1 : r2) i.e. r3 = MAX(r1, r2)
	mov r1, #21			@ r1 = 21
	mov r2, #23			@ r2 = 23
	cmp r1, r2			@ compare/difference r1 and r2 and set NZCV.
	movgt r3, r1		@ r3 = r1 if r1 > r2	i.e. cond execution of instruction
	movle r3, r2		@ r3 = r2 if r1 <= r2	i.e. cond execution of instruction
	*/

	@ Thumb instruction set
	@ r3 = (r1 > r2 ? r1 : r2) i.e. r3 = MAX(r1, r2)
	mov r1, #25			@ r1 = 25
	mov r2, #23			@ r2 = 23
	cmp r1, r2			@ compare/difference r1 and r2 and set NZCV.
	bgt max_r1
	mov r3, r2
	b max_end
max_r1:
	mov r3, r1
max_end:

	@ Thumb-2 instruction set
	@ r3 = (r1 > r2 ? r1 : r2) i.e. r3 = MAX(r1, r2)
	mov r1, #21			@ r1 = 21
	mov r2, #23			@ r2 = 23
	cmp r1, r2			@ compare/difference r1 and r2 and set NZCV.
	ite gt				@ if-then-else (cond is true then execute first instru)
						@ (cond is false then execute second instru)
	movgt r3, r1		@ r3 = r1 if r1 > r2	i.e. cond execution of instruction
	movle r3, r2		@ r3 = r2 if r1 <= r2	i.e. cond execution of instruction

	/*
	cmp r5, r6
	ittee gt
	instruction 1		@ if r5 > r6 true
	instruction 2		@ if r5 > r6 true
	instruction 3		@ if r5 > r6 false
	instruction 4		@ if r5 > r6 false
	*/

	/*
	cmp r5, r6
	ittte gt
	instruction 1		@ if r5 > r6 true
	instruction 2		@ if r5 > r6 true
	instruction 3		@ if r5 > r6 true
	instruction 4		@ if r5 > r6 false
	*/

	/*
	cmp r5, r6
	iteee gt
	instruction 1		@ if r5 > r6 true
	instruction 2		@ if r5 > r6 false
	instruction 3		@ if r5 > r6 false
	instruction 4		@ if r5 > r6 false
	*/

	mov pc, lr

/***************************************************************/

.type Default_Handler, %function
Default_Handler:
	halt: b halt

.end

