#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>
#include <linux/jiffies.h>

static void mymod_timer_handler(unsigned long data);
static unsigned long onesec;
static unsigned long tick;

DEFINE_TIMER(mytimer, mymod_timer_handler, 0, 0);

static void mymod_timer_handler(unsigned long data)
{
	//print how much time process running
	printk(KERN_INFO "%u seconds\n", (unsigned)tick++);

	//recursive_call
	mod_timer(&mytimer, jiffies + onesec);
}

static int hi_mymod(void)
{
	onesec = msecs_to_jiffies(HZ*1);
	tick = 0;

	printk(KERN_INFO "Hello, World #2\n");
	//print time per second
	mod_timer(&mytimer, jiffies + onesec);

	return 0;	/*return zero on successful loading*/
}

static void bye_mymod(void)
{
	del_timer(&mytimer);
	printk(KERN_INFO "Goodbye\n");
}
module_init(hi_mymod);
module_exit(bye_mymod);

MODULE_DESCRIPTION("mymod");
MODULE_LICENSE("GPL");
