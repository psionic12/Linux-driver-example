ifneq ($(KERNELRELEASE),)
obj-m :=cde.o
else
	KDIR := /lib/modules/2.6.32-21-generic-pae/build
all:
	
	make -C $(KDIR) M=$(PWD) modules
	
clean: 
	rm -f *.ko *.mod.o *.mod.c *.symvers
endif
