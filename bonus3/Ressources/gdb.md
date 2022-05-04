# Check functions

![](/Users/a19523132/school/Rainfall/bonus3/Ressources/img/gdb_launch.png)

There is only `main`

# Main disass

![](/Users/a19523132/school/Rainfall/bonus3/Ressources/img/main_disass_1.png)
![](/Users/a19523132/school/Rainfall/bonus3/Ressources/img/main_disass_2.png)

It uses `fopen`, `bzero` via the `rep stos` instruction, `fread`, `atoi`, `fclose`, `strcmp`, `execl` and `puts`

# Strings used

We can find interesting strings at `<+19>`, `<+255>`

![](/Users/a19523132/school/Rainfall/bonus3/Ressources/img/strs.png)

`/home/user/end/.pass` is located at `0x080486f2`
`/bin/sh` is located at `0x0804870a`
