/*
 * Simple module to lockup a machine.
 *
 * (C) 2014 Canonical Ltd., Chris J Arges <christopherarges@gmail.com>
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>

#define AUTHOR      "Chris J Arges <chris.j.arges@canonical.com>"
#define LICENSE     "GPL"

static int __init hanger_init(void)
{
	/* triggers watchdog_overflow_callback */
	printk("Triggering soft lockup.\n");
	local_irq_disable();
	while (true)
		;;

	return 0;
}

static void __exit hanger_cleanup(void)
{
}

module_init(hanger_init);
module_exit(hanger_cleanup);

MODULE_AUTHOR(AUTHOR);
MODULE_LICENSE(LICENSE);
