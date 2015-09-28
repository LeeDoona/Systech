obj-m := chr_dev.o

KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

ALL: test_dd Battery_Status

test_dd: chr_dev.c
	$(MAKE) -C $(KERNELDIR) SUBDIRS=$(PWD) modules

test_app: Battery_status.c
	gcc -o state Battery_status.c

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	rm -rf state