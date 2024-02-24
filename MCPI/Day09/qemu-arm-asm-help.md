1. Install QEmu on PC (Ubuntu).
	```sh
	> sudo apt install qemu-system-arm
	```
2. Add toolchain PATH in .bashrc.
	* Open Terminal and give below command
		```sh
		> vim ~/.bashrc
		```
	* Add PATH of the toolchain (in ST) into OS's PATH variable. 
		```sh
		export PATH=/opt/st/stm32cubeide_1.12.1/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.10.3-2021.10.linux64_1.0.200.202301161003/tools/bin:$PATH
		```
	* Save file (:wq) and "close the terminal".
3. Copy the following files on your system.
	* basic.s --> minimal Cortex-M3 ARM assembly code.
	* lm3.ld --> Linker script for lm3s811 (Cortex-M3 processor).
	* Makefile --> Makefile to compile and run the program in QEmu.
4. Commands for compilation and execution on QEmu.
	* Compile the program.
		```sh
		> make
		```
	* Run program on QEmu. This terminal will stuck now. Do not close it.
		```sh
		> make run
		```
	* Debug program from another terminal. Open new terminal and give command.
		```sh
		> make debug
		```
	* Basic debugging commands
		```
		# set breakpoint to main function
		gdb> break main

		# jump to break point
		gdb> cont

		# to display register contents
		gdb> info registers r0 r1 xpsr

		# to go to next instruction (step over if function)
		gdb> next

		# to go to next instruction (step into if function)
		gdb> step

		# exit gdb
		gdb> quit
		```
	* Stop debugging.
		```sh
		> make stop
		```
	* Delete generate object and executble/binary files.
		```sh
		> make clean
		```
5. Files created after compilation.
	* basic.o --> object code
	* basic.elf --> ARM executable with ELF format (sectioned binary)
		```sh
		> arm-none-eabi-readelf -a basic.elf

		> arm-none-eabi-objdump -h basic.elf

		> arm-none-eabi-objdump -S basic.elf

		> arm-none-eabi-objdump -t basic.elf
		```
	* basic.bin --> Binary file (flat binary)
		* In-memory image of the elf code, data, and custom segments that can be run by the CPU.
		* This file can be burned into flash.
	