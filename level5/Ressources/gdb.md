# Check functions

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/gdb_launch.png)

We see 3 functions: `n`, `o` and `main`. Let's disassemble the main()

# Main disass

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/main_disass.png)

Only `n` is called

# N disass

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/n_disass.png)

It uses `fgets`, `printf`, and `exit`

So, `o` isn't called during execution

# O disass

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/o_disass.png)

Only `system` and `exit` are used here

Generally it looks like previous. Let's find `/bin/sh` passed in `system` in `o`

# Strings used

Let's determine several strings in `o` (`<+6>`)

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/bin_sh.png)

Great!

# Buffers size

Print the address from `<+26>` in `n`

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/n_buf.png)

There is buffer with size `520`

There is an address in `<+18>` which represent the maximum bytes read by `fgets`

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/real_buf.png)

It equals `512` and this is less than the size of the buffer in which we'll store the result meaning no buffer overflow is possible here.

# Function's addresses

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/o_addr.png)
![](/Users/a19523132/school/Rainfall/level5/Ressources/img/exit_addr.png)

`o` address is `0x80484a4`. `exit` address is `0x8049838`
