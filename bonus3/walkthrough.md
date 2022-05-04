# Bonus3

Let's see to the binary

![](/Users/a19523132/school/Rainfall/bonus3/Ressources/img/bonus3_launch.png)

The binary takes an argument. Let's use [gdb](Ressources/gdb.md) to understand what's going on.

Our input needs to match some pointer value that is being altered by our input fed through `atoi`. 
It is ruled by `pointer[atoi(argv[1])] = 0`. So if we send an empty string to parse, 
it will be `pointer[0] = 0` and since `argv[1]` equals `NULL`, the condition `pointer == argv[1]` is satisfied.

![](/Users/a19523132/school/Rainfall/bonus3/Ressources/img/end.png)
