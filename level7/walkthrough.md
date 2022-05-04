# Level7

Let's see to the binary

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/level7_launch.png)

The program waits our input as two strings. Let's use [gdb](Ressources/gdb.md) to understand what's going on. 

Once again, we'll exploit `strcpy` but in a more advanced way. 
We found out that the two given arguments are copied to two set addresses inside the code, 
then the password file of the next user is read and its content is stored into variable that is printed in an unreachable function under normal circumstances.

Using a buffer overflow we could ask the program to write our second argument to wherever we want by shifting any address by the offset of the first `strcpy` call. 
We find a useless `puts` that does nothing useful for the program's execution so like a previous level we can use a GOT Overwrite to redirect to the wanted function.

For this exploit, we need:

1. Address of the `puts` = 0x08049928 
2. Offset of first `strcpy` = 20 
3. Address of the wanted function ( `m` = 0x080484f4)
4. Then all we have to do is shifting the address of `puts` into the second `strcpy` destination address and write the wanted function address into it

./level7 `python -c 'print "\x90"*20 + "\x08\x04\x99\x28"[::-1]'` `python -c 'print "\x08\x04\x84\xf4"[::-1]'`

![](/Users/a19523132/school/Rainfall/level7/Ressources/img/level8.png)
