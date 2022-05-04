# Level3

The binary looks like in previous

![](/Users/a19523132/school/Rainfall/level3/Ressources/img/level3_launch.png)

Okay, let's launch the binary via [gdb](Ressources/gdb.md) and check all functions in it.
The buffer overflow attack isn't possible in this level, because the binary uses `fgets` reading 512 bytes to a 520 bytes buffer

There is a built-in way to spawn a shell and for this a global variable on which we have no apparent control must equal 64. 
After deeper dive into the code we can see that the output of `fgets` is directly passed as first and only argument to a `printf`.
According to the documentation, this usage of [printf](https://linux.die.net/man/3/printf) can be exploited:

>Code such as printf(foo); often indicates a bug, since foo may contain a % character. 
>If foo comes from untrusted user input, it may contain %n, causing the printf() call to write to memory and creating a security hole.

Using this vulnerability, we can arbitrarily set the global variable to the right value to spawn the shell. 
In order to do this, we'll need to set a format string that would update the value stored in the address of this variable.

The process is a bit tricky:

1. Get the variable `m` address `0x0804988c`
2. Use multiple `%p` to identify which stack parameter is the variable
3. Add the correct amount of character to the format string and using `%n` update the value of the variable by the number of characters

By appending %p identifiers we can find the position of the format string in the stack

`python -c 'print "AAAA" + " %p" * 8' | ./level3`

![](/Users/a19523132/school/Rainfall/level3/Ressources/img/format_str.png)

In our case it is the 4th one because `AAAA` is `41414141` is hexadecimal. 
We know the format string position in the stack all we have to do is to create a 64 character long string containing the address of the variable involved in the condition to spawn the shell and output this length to its address using %n

At first, we write the address of the variable, which is already 4 bytes, so using `%60c` will add 60 spaces as padding resulting in a 64 character long string. 
Then all we have to do is output the number of character printed until this point using `%n` into the 4th positional argument which is indeed the address of the variable we want to change using `%4$`

`(python -c 'print "\x08\x04\x98\x8c"[::-1] + "%60c%4$n"'; cat) | ./level3`

![](/Users/a19523132/school/Rainfall/level3/Ressources/img/level4.png)
