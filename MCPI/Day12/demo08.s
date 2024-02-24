/* *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
**  Micro-Controller : LM3SXXXX *************************************************************************
*/
/* array - demo */
@ r0 = *r4;		r4 = r4 + 4;	-- LDR instruction
@ r0 = *r4++;					-- Post-indexing
@ r0 = r4[r1] = *(r4+r1);		-- Pre-indexing
@ r0 = *(r4+(r7<<2));			-- Pre-indexing with shift


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
@ uint32_t arr[5] = { 11, 22, 33, 44, 55 }
arr:	.word	11
		.word	22
		.word	33
		.word	44
		.word	55

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
	ldr r4, =arr				@ r4 = arr
	mov r7, #0					@ r7 = 0
loop:
	cmp r7, #5					@ while(r7 < 5)
	bge loop_end				@ {
	ldr r0, [r4]				@	r0 = *r4;
	add r4, #4					@	r4 = r4 + 4;	
	add r7, #1					@	r7++;
	b loop						@ }	
loop_end:
	*/

	/*
	@ post-indexing i.e. ldr r0, [r4], #4 -- with writeback
	ldr r4, =arr				@ r4 = arr
	mov r7, #0					@ r7 = 0
loop:
	cmp r7, #5					@ while(r7 < 5)
	bge loop_end				@ {
	ldr r0, [r4], #4			@	r0 = *r4++;
		@ first load value at r4 addr into r0 and then increment r4 by 4.
	add r7, #1					@	r7++;
	b loop						@ }	
loop_end:
	*/

	/*
	@ pre-indexing i.e. ldr r0, [r4, r1]
	ldr r4, =arr				@ r4 = arr
	mov r1, #0					@ r1 = 0
	mov r7, #0					@ r7 = 0
loop:
	cmp r7, #5					@ while(r7 < 5)
	bge loop_end				@ {
	ldr r0, [r4, r1]			@	r0 = *(r4+r1);
		@ add r1 into r4 and then get value at that location.
	add r1, #4					@ 	r1 = r1 + 4
	add r7, #1					@	r7++;
	b loop						@ }	
loop_end:
	*/

	/*
	@ pre-indexing with shift i.e. ldr r0, [r4, r7, lsl #2]
	ldr r4, =arr				@ r4 = arr
	mov r7, #0					@ r7 = 0
loop:
	cmp r7, #5					@ while(r7 < 5)
	bge loop_end				@ {
	ldr r0, [r4, r7, lsl #2]	@	r0 = *(r4+(r7<<2));
		@ add r1 into r4 and then get value at that location.
	add r7, #1					@	r7++;
	b loop						@ }	
loop_end:
	*/

	@ pre-indexing with writeback/update i.e. ldr r0, [r4, #4]!
	ldr r4, =(arr-4)			@ r4 = arr
	mov r7, #0					@ r7 = 0
loop:
	cmp r7, #5					@ while(r7 < 5)
	bge loop_end				@ {
	ldr r0, [r4, #4]!			@	r0 = *++r4;
		@ add r1 into r4 and then get value at that location.
	add r7, #1					@	r7++;
	b loop						@ }	
loop_end:

	mov pc, lr

/***************************************************************/

.type Default_Handler, %function
Default_Handler:
	halt: b halt

.end

