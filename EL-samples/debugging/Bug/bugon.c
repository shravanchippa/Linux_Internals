/*
 * A sample kernel module in a 2.6
 * Asserting bugs and dumping information
 * BUG(), BUG_ON(), panic(), dump_stack();
*/

#include <linux/init.h>

#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

int bad_thing = 5;
int terrible_thing = 100;
long int foo = 123;

static int hello_init(void)
{
    printk(KERN_ALERT "Hello, world\n");

    BUG_ON(bad_thing);
//    dump_stack();
//    panic("foo is %ld\n", foo);

    return -1;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

