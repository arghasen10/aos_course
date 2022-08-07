#include <linux/init.h>
#include <linux/module.h>

static int first_module_begin(void)
{
	printk (KERN_ALERT "First Module Initiated\n");
	return 0;
}

static void first_module_exit(void)
{
	printk(KERN_ALERT "First Module exit\n");
}

module_init(first_module_begin);
module_exit(first_module_exit);
