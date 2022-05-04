# Level4

The binary is the same as the previous

![](/Users/a19523132/school/Rainfall/level4/Ressources/img/level4_launch.png)

Okay, let's launch the binary via [gdb](Ressources/gdb.md) and check all functions in it.
The buffer overflow attack isn't possible in this level, because the binary uses `fgets` reading 512 bytes to a 520 bytes buffer

There is a built-in way to output the next password if a variable we have no apparent control on is equal to `16930116`.
We could update its value via the same attack as in previous level using format string. This time, the variable is located at `0x08049810`.

Like before let's, first, identify which positional argument is our input.

`python -c 'print "AAAA" + " %p" * 16' | ./level4`

![](/Users/a19523132/school/Rainfall/level4/Ressources/img/format_str.png)

Our input is in 12th place at this time because we have more instructions between the variable and `printf`.

Now that we know the format string position in the stack all we have to create a `16930116` character long string containing 
the address of the variable involved in the condition to spawn the shell and output this length to its address using `%n`

At first, we write the address of the variable, which is already 4 bytes, so using `%16930112c` will add 16930112 spaces as padding resulting in a 16930116 character long string. 
Then all we have to do is output the number of character printed until this point using `%n` into the 12th positional argument which is indeed the address of the variable we want to change using `%12$`

`python -c 'print "\x08\x04\x98\x10"[::-1] + "%16930112c%12$n"' | ./level4`

![](/Users/a19523132/school/Rainfall/level4/Ressources/img/exploit.png)
![](/Users/a19523132/school/Rainfall/level4/Ressources/img/level5.png)
