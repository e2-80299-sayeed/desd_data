/* *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
**  Micro-Controller : LM3SXXXX *************************************************************************
*/

/* logical/bitwise operations */

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
	@ bitwise not operation -- 1's complement, 2's complement
	mov r1, #23			@ r1 = 23
	mvn r2, r1			@ r2 = ~r1
	add r2, #1			@ r2 = r2 + 1
						@ r2 = ~r1 + 1 = -23
	@ and operation
	mov r1, #9			@ r1 = 00000000 00000000 00000000 00001001
	mov r2, #5			@ r2 = 00000000 00000000 00000000 00000101
	and r3, r1, r2		@ r3 = 00000000 00000000 00000000 00000001 = 1

	@ or operation
	mov r1, #9			@ r1 = 00000000 00000000 00000000 00001001
	mov r2, #5			@ r2 = 00000000 00000000 00000000 00000101
	orr r3, r1, r2		@ r3 = 00000000 00000000 00000000 00001101 = 13

	@ xor operation
	mov r1, #9			@ r1 = 00000000 00000000 00000000 00001001
	mov r2, #5			@ r2 = 00000000 00000000 00000000 00000101
	eor r3, r1, r2		@ r3 = 00000000 00000000 00000000 00001100 = 12

	@ bit clear operation
	mov r1, #0x0000FFFF @ r1 = 00000000 00000000 11111111 11111111
	mov r2, #0x00000080 @ r2 = 00000000 00000000 00000000 10000000
						@ r3 = r1 & ~r2
	bic r3, r1, r2		@ r3 = 00000000 00000000 11111111 01111111 = 0x0000FF7F

	@ test a bit
	mov r5, #19
	ands r6, r5, #1			@ if r5 is even, r6=0 (Z=1) and if r5 is odd, r6=1 (Z=0).

	@ test a bit
	mov r5, #20
	tst r5, #1			@ if r5 is even, r6=0 (Z=1) and if r5 is odd, r6=1 (Z=0).
						@ tst Instruction does AND operation and modify NZCV flags.
	mov pc, lr

/***************************************************************/

.type Default_Handler, %function
Default_Handler:
	halt: b halt

.end
