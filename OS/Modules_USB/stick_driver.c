#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

//probe function
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	printk(KERN_INFO "[*]HP v220w Pen drive (%04X:%04X) plugged \n",id->idVendor , id->idProduct);
	return 0;
}

//disconnect 

static void pen_disconnect (struct usb_interface *interface)
{
	printk(KERN_INFO "[*]HP v220w Pen drive removed \n");
}
//usb_device_id
static struct usb_device_id pen_table[]=
{
	{USB_DEVICE(0x03f0, 0x5a07)}, //obtained by lsusb
	{}
};

MODULE_DEVICE_TABLE (usb, pen_table);

//usb driver
static struct usb_driver pen_driver ={
	.name="HP v220w-USB Stick-Driver",
	.id_table= pen_table,
	.probe = pen_probe,
	.disconnect = pen_disconnect
};

static int __init pen_init(void)
{
	int ret = -1;
	printk(KERN_INFO "[*]HP v220w Constructor of driver");
	printk(KERN_INFO "\tRegistering Driver with Kernel");
	ret=usb_register(&pen_driver);
	printk(KERN_INFO "\tRegistration is complete");
	return ret;
}

static void __exit pen_exit(void)
{
	printk(KERN_INFO "[*] HP v220w Destructor of driver");
	usb_deregister(&pen_driver);
	printk(KERN_INFO "\tUn-Registration is complete");
}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HP v220w");
MODULE_DESCRIPTION("USB Pen Registration Driver");


/*
sudo make
ls
sudo insmod stick_driver.ko
demsg
sudo rmmod usb_storage          (rmmod -f if needed)
demsg
sudo rmmod stick_driver.ko
demsg
*/
