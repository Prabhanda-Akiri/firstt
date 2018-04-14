#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/init.h>


static int hello_init(void)
{
	printk(KERN_ALERT "Hello World jam\n");
	return 0;
} 

static void hello_exit(void)
{
	printk(KERN_ALERT "TEST: Bye\n");
}

module_init(hello_init);
module_exit(hello_exit);
