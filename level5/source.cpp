#include <unistd.h>
#include <cstdlib>
#include <cstdio>

void o()
{
	system("/bin/sh");
	_exit(1);
}

void n()
{
	char input[520];

	fgets(input, 512, stdin);
	printf(input);
	exit(1);
}

int main()
{
	n();
	return 0;
}