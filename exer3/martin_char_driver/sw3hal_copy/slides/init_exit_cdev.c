#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

const int first_minor = 0;
const int max_devices = 255;
static dev_t devno;
struct file_operations hello_fops;
static struct class *hello_class;
static struct cdev hello_cdev;

/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
  pr_err (__VA_ARGS__);                         \
  goto label;                                   \
  } while(0)

static int __init hello_init(void)
{
  int err=0;

  err = alloc_chrdev_region(&devno, first_minor, max_devices, "hello-driver");
  if(MAJOR(devno) <= 0)
    ERRGOTO(err_end, "Failed to allocate device number\n");

  pr_info("Hello driver got Major %i\n", MAJOR(devno));

  /* Polulate sysfs entries */
  hello_class = class_create(THIS_MODULE, "hello-class");
  if ((err = IS_ERR(hello_class)))
    ERRGOTO(err_cleanup_chrdev, "Failed to create class\n");

  /* Init cdev and register it with kernel */
  cdev_init(&hello_cdev, &hello_fops);
  err = cdev_add(&hello_cdev, devno, max_devices);
  if (err)
    ERRGOTO(err_cleanup_class, "Failed add cdev\n");

  struct device *hello_device;
  hello_device = device_create(hello_class, NULL, devno, NULL, "hello-device");
  if ((err = IS_ERR(hello_device)))
    ERRGOTO(err_cleanup_cdev, "Failed to create device\n");

  return 0; /* Success! */

err_cleanup_cdev:
    cdev_del(&hello_cdev);
err_cleanup_class:
    class_destroy(hello_class);
err_cleanup_chrdev:
    unregister_chrdev_region(devno, max_devices);
err_end:
    return err; /* Propagate error */
}

static void __exit hello_exit(void)
{
    device_destroy(hello_class, devno);
    cdev_del(&hello_cdev);
    class_destroy(hello_class);
    unregister_chrdev_region(devno, max_devices);
    pr_info("Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Peter HM <phm@ece.au.dk>");
MODULE_LICENSE("GPL");
