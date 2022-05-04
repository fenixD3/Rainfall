# Level5

The binary is the same as the previous

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/level5_launch.png)

Okay, let's launch the binary via [gdb](Ressources/gdb.md) and check all functions in it.
The buffer overflow attack isn't possible in this level, because the binary uses `fgets` reading 512 bytes to a 520 bytes buffer

After some deeper analysis, we find that there is a built-in way to spawn a shell within this program but the function were this logic happens is never called. 
Since the program don't return to the main at the end of execution but calls for `exit`, we could use what's called a [GOT overwrite exploit](https://infosecwriteups.com/got-overwrite-bb9ff5414628)

We can replace the address of `exit` in the GOT with the address of `o`, for calling it instead of `exit`.
The GOT (Global Offset Table) is a table of addresses in the data section, it contains the shared library functions addresses.

The process is as follows:

1. Get the address of `exit` in the Global Offset Table
2. Get the address of the function we want to run, `o` in our case
3. Find the stack argument representing the format string
4. Overwrite the call to `exit` by the address of `o`

gdb analysis gets us:

- exit =  0x08049838
- o = 0x080484a4

Since these two addresses share the same two high order bytes we can take a shortcut here. 
We can update only the low order bytes (0x84a4 equals 33956 in 10-base represents) so that `o` would be executed making the format string a bit shorter and more readable.

Like before let's, first, identify which positional argument is our input

`python -c 'print "AAAA" + " %p" * 8' | ./level5`

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/format_str.png)

Our input is the 4th stack argument

Now that we know the format string position in the stack all we have to do is to create a `33956` character long string,
containing the address of `exit` to match the lower order bytes from `o`() address and output its low order bytes using `%hn`

At first, write the address of `exit`, which is already 4 bytes, so using `%33952c` will add 33952 spaces as padding resulting in a 33956 character long string. 
Then all we have to do is output the number of character printed until this point using `%hn` into the 4th positional stack argument low order bytes we want to change using `%4$`

`(python -c 'print "\x08\x04\x98\x38"[::-1] + "%33952c%4$hn"'; cat) | ./level5`

![](/Users/a19523132/school/Rainfall/level5/Ressources/img/exploit.png)
![](/Users/a19523132/school/Rainfall/level5/Ressources/img/level6.png)
