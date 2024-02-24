.global _start

_start:

	addi a7, zero, 93
	addi a0, zero, 13
	ecall

# cmd> make
# cmd> ./basic.out
# cmd> echo $?
