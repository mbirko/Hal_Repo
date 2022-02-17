#include <linux/module.h>
#include <linux/fs.h>

// Dummy functions
int allocate_it(char *ch){return *ch&1;};
void deallocate_it(char *ch){};

static int __init hello_init(void)
{
  int err;
  /* Allocate resouces */
  err = allocate_it("A");
  if (err) goto fail_A;
  err = allocate_it("B");
  if (err) goto fail_B;
  err = allocate_it("C");
  if (err) goto fail_C;
  
  return 0; /* success */

  fail_C: deallocate_it("B");
  fail_B: deallocate_it("A");
  fail_A: 
  return err; /* propagate the error */ 
}

static void __exit hello_exit(void)
{
  /* Deallocate resouces */
  deallocate_it("C");
  deallocate_it("B");
  deallocate_it("A");
  return; 
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Peter HM <phm@ece.au.dk>");
MODULE_LICENSE("GPL");