# Loadable Kernel Module
## _Assignment-5[Part:1]_
## Question :Implement a Loadable Kernel Module (LKM) which prints a "Hello World" message in the kernel ring buffer. Submit the sources along with Makefile and README.md

### Some Information about the Loadable Kernel Module including basic commands
- LKM is an object file that contains code to extend the running kernel of an operating system,they can be loaded dynamically.
- Kernel Module Structure:
    1. Kernel modules have a .ko file extension.
    2. They contain initialization and cleanup functions (init_module and cleanup_module) that are called when the module is loaded and unloaded, respectively.
- The steps that i followed to complete this assignment are listed down in order.

#### Step 1:
Creating the Directory where my source files and Makefile are stored.
> mkdir Hello_world

#### step 2:
Inside the Hello_world directory creating the hello.c file.
> gedit hello.c

#### step 3:
> #include <linux/module.h>
#include <linux/kernel.h>

> MODULE_LICENSE("GPL");
MODULE_AUTHOR("bindu");
MODULE_DESCRIPTION("Hello world LKM");

> static int hello_init(void) {

>	printk(KERN_INFO "Hello kernel :-) Bindu was here\n");
	return 0;
}

> static void hello_exit(void) {

>	printk(KERN_INFO "bye bye\n");
}

> module_init(hello_init);
module_exit(hello_exit);

#### Step 4: 
Creating Makefile and adding the following commands to it.
> obj-m += hello.o
all:
	[tab]make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	[tab]make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	
make sure that you object file name is same as your source file name.

#### Step 5:
Make sure you have the kernel headers installed for your running kernel. 
> sudo apt-get install linux-headers-$(uname -r)

Then compile the module :
> make

#### Step 6:
After successfully compiling the hello.c file,the directory will now have multiple file.Among them the file "hello.ko" is our loadable kernel module file which we use to load and unload it to the running kernel.
Loadind the module :
> sudo insmod hello.ko

#### Step 7: Loading the module
after successfully loading the module to see the print statement.Look in to the system logs using 'dmesg'
> sudo dmesg | tail

You can also verify it using 'lsmod' command
> lsmod | gerp hello

#### Step 8: Unloading Module
To unload the Module type the following command on terminal
> sudo rmmod hello.ko

Similar to loading,you can check if the module is loaded or not using 'lsmod' or 'dmesg' commands with 'sudo' priviliges

   
