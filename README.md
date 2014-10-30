hanger
=====

Author: Chris J Arges <christopherarges@gmail.com>

Copyright:  (C) 2014 Canonical Ltd., Chris J Arges <christopherarges@gmail.com>

License: GPLv2

install
-------
1. ensure headers are installed
2. build it
	* `$ make`
3. trigger hang
	* `$ sudo insmod hanger.ko`

uninstall
---------
1. remove module
	* `$ sudo rmmod hanger`
