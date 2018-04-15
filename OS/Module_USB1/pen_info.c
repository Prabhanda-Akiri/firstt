#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
 
static struct usb_device *device;
 
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    struct usb_host_interface *iface_desc;
    struct usb_endpoint_descriptor *endpoint;
    int i;
 
    iface_desc = interface->cur_altsetting;
    printk(KERN_INFO "Hi Prajwala...!!\n");
    printk(KERN_INFO "Pen i/f %d now probed: (%04X:%04X)\n",
            iface_desc->desc.bInterfaceNumber, id->idVendor, id->idProduct);
    printk(KERN_INFO "ID->bNumEndpoints: %02X\n",
            iface_desc->desc.bNumEndpoints);
    printk(KERN_INFO "ID->bInterfaceClass: %02X\n",
            iface_desc->desc.bInterfaceClass);
 
    for (i = 0; i < iface_desc->desc.bNumEndpoints; i++)
    {
        endpoint = &iface_desc->endpoint[i].desc;
 
        printk(KERN_INFO "ED[%d]->boooEndpointAddress: 0x%02X\n",
                i, endpoint->bEndpointAddress);
        printk(KERN_INFO "ED[%d]->booomAttributes: 0x%02X\n",
                i, endpoint->bmAttributes);
        printk(KERN_INFO "ED[%d]->wMaxPacketSize: 0x%04X (%d)\n",
                i, endpoint->wMaxPacketSize, endpoint->wMaxPacketSize);
    }
 
    device = interface_to_usbdev(interface);
    return 0;
}
 
static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "Pen i/f %d now disconnected\n",
            interface->cur_altsetting->desc.bInterfaceNumber);
}
 
static struct usb_device_id pen_table[] =
{
    { USB_DEVICE(0x03f0, 0x5a07) },
    {} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, pen_table);
 
static struct usb_driver pen_driver =
{
    .name = "pen_driver",
    .probe = pen_probe,
    .disconnect = pen_disconnect,
    .id_table = pen_table,
};
 
static int __init pen_init(void)
{
    printk(KERN_INFO "\tRegistering Driver with Kernel");
    printk(KERN_INFO "\tRegistration is complete");
    return usb_register(&pen_driver);
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
MODULE_AUTHOR("Anil Kumar Pugalia <email@sarika-pugs.com>");
MODULE_DESCRIPTION("USB Pen Info Driver");
