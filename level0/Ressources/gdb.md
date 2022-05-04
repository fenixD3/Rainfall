Make `diass` with `main` function in our binary

![](/Users/a19523132/school/Rainfall/level0/Ressources/img/disass_main.png)

We can see a calling `atoi()`, `strdup()`, `getegid()`, `geteuid()`, `setresgid()`, `setreusuid()`, 
`execv()`, `fwrite()`.

We see comparing a value 423 in decimal with `eax` after calling `atoi` in line `<+25>`.
It compares with argument of function.

We see the saving a string `/bin/sh` in line `<+32>`

![](/Users/a19523132/school/Rainfall/level0/Ressources/img/bin_sh.png)

This command will be passed to `execv` in line `<+145>`

So, we must pass 423 number as the argument in our binary.