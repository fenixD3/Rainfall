# Check functions

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/gdb_launch.png)

We see 3 functions: `n`, `m` and `main`. Let's disassemble the main()

# Main disass

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/main_disass.png)

It calls `malloc` at twice, `strcpy` and loads address to `eax`

# M disass

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/m_disass.png)

Only `puts` is called. Not interesting

# N disass

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/n_disass.png)

Only `system` is called. It is a way to get the next password, probably.

`n` address is `0x8048454`

# Strings used

Let's try to find `/bin/sh` or similar in `n` at the `<+6>`

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/bin_cat.png)

Nice, we find a shell command to get the next password. We saw `Nope` string when launch the binary. It's stored in `m` at `<+6>`

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/nope_str.png)

# Buffers size

We can find two buffers in `main` when `malloc` is called (`<+9>`, `<+25>`)

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/main_buf.png)

There are buffers with size `64` and `4`

# Buffers offset

We know the program calls `strcpy` which is vulnerable to buffer overflow. Launch in gdb

run `echo -e "import string\nprint ''.join([char * 4 for char in string.ascii_letters])" | python`

![](/Users/a19523132/school/Rainfall/level6/Ressources/img/offset.png)

This little python script creates a string that look likes `aaaabbbbcccc....` 
Since the program crashed on address `0x73737373` which is `ssss` (see hexadecimal ascii table) the offset is equal to `4 * (Index of letter - 1)`. 
So this buffer offset is `72` (s has index equals 19)


