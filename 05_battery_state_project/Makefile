obj-m := BatteryDD.o

KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

ALL: test_dd test_app

test_dd: BatteryDD.c
	$(MAKE) -C $(KERNELDIR) SUBDIRS=$(PWD) modules

test_app: BatteryManager.c
	gcc -o battery_state BatteryManager.c

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	rm -rf battery_state