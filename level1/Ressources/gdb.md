# Check functions

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/gdb_launch.png)

We see 2 functions: `run` and `main`. Let's disassemble the main()

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/disass_main.png)

Only the use `gets` was found only

# Run disassemble

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/disass_run.png)

We can see calls `fwrite` and `system` there

# Run address

Let's extract address of `run`

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/run_address.png)

It equals `0x8048444`.

# Buffer size

There is a buffer in `main`, we should to compute it size

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/main_buf.png)

It equals `64` bytes

# Offset

We put a breakpoint before the `gets` to retrieve some useful addresses:
- [EIP register](https://security.stackexchange.com/questions/129499/what-does-eip-stand-for)
- The one where the buffer starts using info frame command that output the current state of some variable
- Register at any given instruction during the program execution

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/offset.png)

We get the following:

1. EIP register: `0xbffff6fc`
2. Buffer beginning: `0xbffff6b0`
3. By subtraction, we find that the buffer offset is `76`

# /bin/sh

We saw it is called `system` in `run`. Let's see what string passing as an argument

![](/Users/a19523132/school/Rainfall/level1/Ressources/img/bin_sh.png)

It is `/bin/sh`!
