# Check functions

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/gdb_launch.png)

We see 2 functions: `m` and `main`. Let's disassemble the main()

# Main disass

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/main_disass.png)

It calls `malloc` multiple times, `strcpy`, `fopen`, `fgets` and `puts`

# M disass

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/m_disass.png)

This function loads a global variable located at `0x8049960` called c to print its value previously set in `main` with `fgets`.
And it calls `printf`

# Strings used

Let's try to find `/bin/sh` or similar in `main` at the `<+166>`

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/home_user.png)

The string `/home/user/level8/.pass` is stored at address `0x80486eb` and it is used as input to `fopen`. 
It must be the way to get the next password.

# Buffers offset

Since we know that programs uses `strcpy` at some point, it is vulnerable to buffer overflow

ltrace ./level7  `echo -e "import string\nprint ''.join([char * 4 for char in string.ascii_letters])" | python` "teststring"

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/offset.png)

Using a buffer overflow we can override the destination address of the second call. which is `ffff`, 
using the same method as previous level, this buffer offset is indeed `20`

# Function's addresses

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/puts_addr.png)

`puts` address is `0x8049928`

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/m_addr.png)

`m` address is `0x80484f4`. It needs for us because there is called `printf` with password for the next