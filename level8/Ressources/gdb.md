# Check functions

![](/Users/a19523132/school/Rainfall/level8/Ressources/img/gdb_launch.png)

There is only `main`, nice

# Main disass

![](/Users/a19523132/school/Rainfall/level8/Ressources/img/main_disass_1.png)
![](/Users/a19523132/school/Rainfall/level8/Ressources/img/main_disass_2.png)
![](/Users/a19523132/school/Rainfall/level8/Ressources/img/main_disass_3.png)

It calls `printf`, `fgets`, `malloc`, `strcpy`, `free`, `strdup` and `system`.
There is an infinite loop at `<+451>` (`jmp` command) to `<main+16>` (it moves the control flow to the start)

# Strings used

We can see the buffer from `fgets` is compared to some string using this instruction:

`ADDRESS <+LINE>:   repz cmpsb %es:(%edi),%ds:(%esi)`

So, we can find the list of compared strings, printing the addressed in string representation at `<+93>`, `<+228>`, `<+282>`, `<+343>`:

![](/Users/a19523132/school/Rainfall/level8/Ressources/img/compared_strings.png)

There is the different commands: `auth`, `reset`, `service`, and `login`. We can find the string passing to `system` at `<+394>`:

![](/Users/a19523132/school/Rainfall/level8/Ressources/img/bin_sh.png)

Great, it launches the another shell!

# Global variables

Let's see to the global vars

![](/Users/a19523132/school/Rainfall/level8/Ressources/img/global_vars.png)

Both `auth` and `service` are created by the program whereas the rest is made by the compiler and linker
