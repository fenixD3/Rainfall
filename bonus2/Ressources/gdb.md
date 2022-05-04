# Check functions

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/gdb_launch.png)

`main` and `greetuser` are called here

# Main disass

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/main_disass_1.png)
![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/main_disass_2.png)

It uses `bzero` via the `rep stos` instruction, `strncpy`, `getenv`, `memcmp` and calls for a custom function called `greetuser`

# Greetuser disass

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/greetuser_disass_1.png)

It uses `strcpy` via the `movzwl` instruction, `strcat` and `puts`

# Strings used

We can find a lot stored string in `main` at `<+118>`, `<+155>`, `<+202>`and in `greetuser` at `<+25>`, `<+54>`, `<+101>`

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/strs.png)

`LANG` is located at `0x08048738`
`fi` is located at `0x0804873d`
`nl` is located at `0x08048740`
`Hello` is located at `0x08048710`
`Hyvää päivää` is located at `0x08048717`
`Goedemiddag!` is located at `0x0804872a`

# Global var

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/global_var.png)

There is a global variable `language` located at `0x08049988`

# Buffer offset

Since we need to overflow using `strcat` we must compute its buffer offset using either `LANG="nl"` 
or `LANG="fi"` as default language seems to only rewrite lower bytes. Let's go for `LANG="nl"`

Launch in gdb

`run $(python -c "print '\x90' * 40") $(echo -e "import string\nprint ''.join([char * 4 for char in string.ascii_letters])" | python)`

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/buffer_offset.png)

We get segfault at address `0x67676766` which represent `fggg` meaning last address is `efff`. 
Since `f` is the 6th letter of the alphabet, `4 * 6 - 1 = 23` bytes is our offset using this language
