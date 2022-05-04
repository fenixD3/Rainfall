# Level9

Let's see to the binary

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/level9_launch.png)

Nothing is prompted for us in normal usage. Let's use [gdb](Ressources/gdb.md) to understand what's going on. 

This time we're facing a C++ program with some class method using `memcpy` which is known to be exploitable since no overlaping checks are made.

We can see that this program calls a loaded address in memory after the class method call. 
Using `memcpy` we could overwrite this address to get the program to call `system` to spawn a shell.

For this exploit, we need:

1. Address of the `system` = 0xb7d86060 
2. Offset of the `memcpy` function = 108 
3. Address of `eax` on method return = 0x0804a00c

The main point of this exploit is to replace the address pointed by eax to a `system` call. 
For this we need to write `system` address then put `104` junk bytes to overflow and then put the address of `eax` which is where we want to overwrite. 
Everything after will be parameter to the `system`, so let's add `/bin/sh` string to get a shell and the next password!

`./level9 $(python -c 'print "\xb7\xd8\x60\x60"[::-1] + "\x90" * 104 + "\x08\x04\xa0\x0c"[::-1] + ";/bin/sh"')`

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/bonus0.png)
