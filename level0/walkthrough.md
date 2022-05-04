# Level0

In the home directory we can find `level0` binary. Try to launch it

![](/Users/a19523132/school/Rainfall/level0/Ressources/img/test_binary.png)

It needs something as an input parameter. Ok, let's use [gdb](Ressources/gdb.md) for a deep dive to the binary

By passing 423 as the argument the program calls `setuid`, `getuid` and use `execv` to start 
a new /bin/sh process as a root user. We can check `.pass` file in level1 user.

![](/Users/a19523132/school/Rainfall/level0/Ressources/img/check_level1.png)

![](/Users/a19523132/school/Rainfall/level0/Ressources/img/su_level1.png)