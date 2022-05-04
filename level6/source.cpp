#include <cstdlib>
#include <cstdio>
#include <cstring>

typedef void(*function_pointer)(void);

void n(void)
{
	system("/bin/cat /home/user/level7/.pass");
}

void m(void)
{
	puts("Nope");
}

int main(int argc, char **argv)
{
	char *input = (char*)malloc(64);
	function_pointer *f = (function_pointer*)malloc(4);
	*f = m;

	strcpy(input, argv[1]);
	(*f)();
}
