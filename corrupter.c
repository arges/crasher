/*
 * Module to test memory corruption.
 *
 * (C) 2014 Canonical Ltd., Chris J Arges <christopherarges@gmail.com>
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

#define AUTHOR      "Chris J Arges <chris.j.arges@canonical.com>"
#define LICENSE     "GPL"

static int __init corrupter_init(void)
{
	int *memory;

	printk("Corrupter started.\n");

	memory = kmalloc(4096, GFP_KERNEL);
	if (!memory) {
		printk("Memory allocation failed.\n");
		return 1;
	}

	/* use after free */
	kfree(memory);
	printk("Triggering use after free.\n");
	*memory = 0xefbeadde;

	return 0;
}

static void __exit corrupter_cleanup(void)
{
}

module_init(corrupter_init);
module_exit(corrupter_cleanup);

MODULE_AUTHOR(AUTHOR);
MODULE_LICENSE(LICENSE);
