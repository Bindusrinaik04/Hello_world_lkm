#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("bindu");
MODULE_DESCRIPTION("Hello world LKM");

static int hello_init(void) {

	printk(KERN_INFO "Hello kernel :-) Bindu was here\n");
	return 0;
}

static void hello_exit(void) {

	printk(KERN_INFO "bye bye\n");
}

module_init(hello_init);
module_exit(hello_exit);
