# Check functions

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/gdb_launch.png)

There are 3 functions: `p`, `pp` and `main`.

# Main disass

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/main_disass.png)

This `main` calls `puts` and custom `pp` function

# Pp disass

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/pp_disass.png)

It uses `strcpy`, `strcat` and `strlen` via the `repnz scas` instruction. On top of that it calls another custom `p` function twice

# P disass

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/p_disass.png)

It uses `puts`, `read`, `strchr` and `strncpy`

# Strings used

Let's try to find `-` string. It's stored in `pp` at `<+8>` 

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/underscool.png)

# Buffer size

There is a buffer in `p` function, when it reads something via `read`. Let's print `<+20>` and `<+28>`

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/buff_size.png)

`read` call uses a buffer with `4104` size and reads `4096` maximum

# Buffer offset

It is used `strcat` in `pp` to buffer overflow, we need to find its offset for this, 
we only need to make a breakpoint on `puts` call in `main`, send some long enough data and retrieve the saved `EIP`

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/buffer_offset.png)

Saved `EIP` is at address `0x4d4c4b4a` which is equivalent to the bit `JKLM` in little endian.
Since we start to overwrite `EIP` at `J` which is the 10th character, it means that this offset is `9` bytes
