# Level8

Let's see to the binary

![](/Users/a19523132/school/Rainfall/level8/Ressources/img/level8_launch.png)

The program shows two pointers for us and expects particular input. Let's use [gdb](Ressources/gdb.md) to understand what's going on. 

After analysis, we understand that there are two global variables which are printed each time we input something.
The first is called `auth` and the other one is `service`. On top of that, depending on our input, some logic is triggered if our input match a command name

- `auth` allocates 4 bytes for the `auth` variable then and copies the rest if the input within the variable if its length is less thant 32 bytes
- `reset` will `free` the `auth` variable
- `service` will use `strdup` on the rest of the input a stores it inside `service`
- `login` will either prompt us a message or give us a shell depending on a simple condition: starting from the address of `auth` we need the following 32nd byte being set to something

Now that we know how to get the next password via a shell. We need to find a way to trigger it and this is where the printed pointers come handy. 
Since we know the address of `auth` and that `auth` and `service` are close in memory, all we have to do is to make sure that 32 bytes after `auth`, there is something meaning we are in the service memory space before typing `login`

Do not forget to input `auth` with a space at the end, otherwise it won't work. 
The `service` command also work with anything as the last character since the comparison only checks for the firsts 6 bytes

![](/Users/a19523132/school/Rainfall/level8/Ressources/img/level9.png)
