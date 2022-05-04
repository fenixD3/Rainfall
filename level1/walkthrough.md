# Level1

We can see, level1 waits some input, but nothing works

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/level1_launch.png)

Okay, let's launch the binary via [gdb](Ressources/gdb.md) and check all functions in it

We found calling `gets` there, and we can use it exploit to create [buffer overflow attack](https://en.wikipedia.org/wiki/Buffer_overflow).

>Never use gets(). Because it is impossible to tell without knowing the data in advance how many characters gets() will read, 
>and because gets() will continue to store characters past the end of the buffer, it is extremely dangerous to use.
>It has been used to break computer security.

We should compute the buffer offset. It equals 76 (see gdb markdown file).
And we should to call `run` using this offset and the function's address

`(python -c "print '\x90' * 76 + '\x08\x04\x84\x44'[::-1]"; cat) | ./level1`

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/level2.png)

We append the address of run() in reverse (this is what [::1] is used for, in python it's a reverse string operation) to respect byte order after a list of 76 NOP instructions.

Segfault still happens, but we know that we are on the right track because we get into a shell but since it is executed via system() this time, it returns when the command is finished.

Asking to open a shell is not enough to stay in it. We need to use something that does read on standard input indefinitely like cat.
