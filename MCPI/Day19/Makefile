AS=riscv64-linux-gnu-as
CC=riscv64-linux-gnu-ld

PROGRAM=demo07
LDFLAGS=-nostdlib -static

$(PROGRAM).out: $(PROGRAM).o
	$(CC) -g -o $@ $^ $(LDFLAGS)

$(PROGRAM).o: $(PROGRAM).s
	$(AS) $< -g -o $@

clean:
	rm -f $(PROGRAM).o $(PROGRAM).out

run: $(PROGRAM).out
	qemu-riscv64-static -g 1234 $(PROGRAM).out

debug: $(PROGRAM).out
	gdb-multiarch $(PROGRAM).out -ex "target remote :1234"
