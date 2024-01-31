
obj-m = demo.o

# modules:
demo.ko: demo.c
	make -C /lib/modules/`uname -r`/build M=`pwd` modules

clean:
	make -C /lib/modules/`uname -r`/build M=`pwd` clean

.phony : clean
