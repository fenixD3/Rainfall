# Check functions

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/gdb_launch.png)

There is only `main` and some methods in class `N`. It's C++ code

# Main disass

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/main_disass.png)

It calls `exit` and others are invoked as C++ methods.
Some `_Znwj@plt` which are `new` keyword are invoked with a class called `_ZN1NC2Ei`, then a `_ZN1N13setAnnotationEPc` method from that class is called.

Let's look inside the `_ZN1N13setAnnotationEPc`

# _ZN1N13setAnnotationEPc disass

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/_ZN1N13setAnnotationEPc_disass.png)

It calls `strlen` and `memcpy`. Since it uses `memcpy` we could potentially exploit this function to get a shell.

# Strings used

Let's try to find may be `/bin/sh` string

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/find_bin_sh.png)

It's stored at address `0x0xb7ea7c58`

# _ZN1NC2Ei disass and buffer size

Inside the class we can find a string buffer as a property

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/_ZN1NC2Ei_disass_buff_size.png)

The buffer has size equals `104`

# Buffer offset

Since the string buffer is used in the `memcpy` we can try to get its offset

`run $(echo -e "import string\nprint ''.join([char * 4 for char in string.ascii_letters])" | python)`

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/buffer_offset.png)

The string input goes through the alphabet first in lowercase then uppercase. 
Since we get `0x42424242` which is `BBBB` in `eax` it means that end of buffer is at `AAAA`. So the offset is `108` bytes (27 * 4).

`eax` has address on method return equals `0x804a078 - 108 = 0x0804a00c`

# Function's addresses

![](/Users/a19523132/school/Rainfall/level9/Ressources/img/system_addr.png)

`system` has address `0xb7d86060`
