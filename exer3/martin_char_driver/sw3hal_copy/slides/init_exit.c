#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h> 

static dev_t devno;
const int first_minor = 0;
const int max_devices = 255;

static int __init hello_init(void)
{
  int err=0;

  err = alloc_chrdev_region(&devno, first_minor, max_devices, "hello driver");
  if(MAJOR(devno) <= 0)
    pr_err("Failed to register chardev\n");

  pr_info("Hello driver got Major %i\n", MAJOR(devno));
  return err;
}

static void __exit hello_exit(void)
{
    unregister_chrdev_region(devno, max_devices);
//    unregister_chrdev_(MAJOR(devno), "hello driver");
    pr_info("Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Peter HM <phm@ece.au.dk>");
MODULE_LICENSE("GPL");
