# Level6

Let's see to the binary

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/level6_launch.png)

The program waits our input. Let's use [gdb](Ressources/gdb.md) to understand what's going on. 

This time a buffer overflow is possible due to [strcpy](https://linux.die.net/man/3/strcpy) being used

> If the destination string of a strcpy() is not large enough, then anything might happen. 
> Overflowing fixed-length string buffers is a favorite cracker technique for taking complete control of the machine.

Since our input can be arbitrary long, we can exploit this vulnerability to modify memory. 
We found that the `Nope` message is output by a function that is assigned to a pointer and there is another function that makes a `system` call giving us the password for next level. 
All we have to do is:

1. Find the address of the `n` = 0x08048454 (where `system` is called)
2. Get the buffer offset = 72

Like this, we can tinker an input that overwrite what's stored inside the function pointer address

./level6 `python -c 'print "0" * 72 + "\x08\x04\x84\x54"[::-1]'`

This simply shifts the value `0x08048454` `72` bytes further into the memory where the function pointer is located

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/level7.png)
