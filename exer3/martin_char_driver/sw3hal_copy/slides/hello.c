#include <linux/module.h>

static int __init hello_init(void)
{
    pr_info("Hello, world\n");
    return 0;
}
static void __exit hello_exit(void)
{
    pr_info("Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Peter HM <phm@ece.au.dk>");
MODULE_LICENSE("GPL");
