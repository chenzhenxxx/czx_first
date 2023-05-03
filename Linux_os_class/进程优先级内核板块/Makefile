obj-m := code.o
CURRENT_PATH := $(shell pwd)
KERNEL_PATH := /usr/src/linux
all:
	make -C $(KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	make -C $(KERNEL_PATH) M=$(CURRENT_PATH) clean