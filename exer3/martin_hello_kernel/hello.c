#include <linux/module.h>

// Init function
static int __init hello_init(void){
	pr_info("Hello, woarld\n");
	return 0;		
}

// exit function
static void __exit hello_exit(void){
	pr_info("Goodbye, woarld\n");
}

// Pass function to kernel modules
module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Martin Stokholm Lauridsen <201908195@post.au.dk>");
MODULE_LICENSE("GPL");
