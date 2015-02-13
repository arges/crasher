crasher
=======

Module for testing Linux kernel crash tools.

Author: Chris J Arges <christopherarges@gmail.com>

Copyright:  (C) 2014,2015 Canonical Ltd., Chris J Arges <christopherarges@gmail.com>

License: GPLv2

modules
-------
* hanger - causes soft lockups
* corrupter - causes memory corruption issues

install
-------
1. ensure headers are installed
2. build it
	* `$ make`
3. trigger hang
	* `$ sudo insmod <module>.ko`

uninstall
---------
1. remove module
	* `$ sudo rmmod <module>`
