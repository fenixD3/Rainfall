# Check functions

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/gdb_launch.png)

We see 2 functions: `p` and `main`. Let's disassemble the main()

# Main disass

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/main_disass.png)

Only `p` is called

Let's try to find may be `/bin/sh` string like in previous level

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/find_bin_sh.png)

>The find command allow us to look for specific strings between two addresses.

it is stored at `0xb7f8cc58` address

# P disass

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/p_disass.png)

It uses `fflush`, `gets`, `printf`, `exit`, `puts` and `strdup`

`ret` instruction has address `0x0804853e`

It is interesting to view at the stored data in `<+51>`

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/pointer_stored.png)

# Buffer size and offset

Print the address from `<+19>` in `p`

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/p_buf.png)

There is buffer with size `76`

Put a breakpoint after `gets`

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/buf_offset.png)

We get the following:

1. EIP register: `0xbffff6ec`
2. Buffer beginning: `0xbffff69c`
3. By subtraction, we find that the buffer offset is `80`

# Function's addresses

![](/Users/a19523132/school/Rainfall/level2/Ressources/img/add_func.png)

`system` address is `0xb7e6b060`. `exit` address is `0xb7e5ebe0`
