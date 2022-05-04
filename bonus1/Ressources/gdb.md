# Check functions

![](/Users/a19523132/school/Rainfall/bonus1/Ressources/img/gdb_launch.png)

Only `main` is called here

# Main disass

![](/Users/a19523132/school/Rainfall/bonus1/Ressources/img/main_disass.png)

This `main` calls `atoi`, `memcpy` and `execl`

# Strings used

Looks like starting from address `0x08048482` (`<+94>`), the instruction list is meant to spawn a shell

Let's print address as a string from `<+102>`

![](/Users/a19523132/school/Rainfall/bonus1/Ressources/img/sh_str.png)

String `sh` is located at address `0x8048580`

Let's print address as a string from `<+110>`

![](/Users/a19523132/school/Rainfall/bonus1/Ressources/img/bin_sh.png)

String `sh` is located at address `0x8048583`

# Buffer offset

Since we need to exploit `memcpy` through `atoi` underflow, let's compute the offset of its buffer. 
For this test, any large enough `atoi` input should work. 
In our case `-1073741792` gives a copy of `192` bytes.

Launch in gdb

`run -1073741792 $(echo -e "import string\nprint ''.join([char * 4 for char in string.ascii_letters])" | python)`

![](/Users/a19523132/school/Rainfall/bonus1/Ressources/img/buffer_offset.png)

`0x6f6f6f6f` represent `oooo`. It means that buffer ends on `nnnn` which is 14th letter in our sequence, so the offset must be `14 * 4 = 56 bytes`
