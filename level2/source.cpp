#include <cstdio>
#include <cstring>
#include <cstdlib>

void p()
{
	unsigned check;
	char buf[76];

	fflush(stdout);
	gets(buf);
	if ((check & 0xb0000000) == 0xb0000000)
	{
		printf("(%p)\n", check);
		exit(1);
	}
	puts(buf);
	strdup(buf);
	return;
}

int main()
{
	p();
	return 0;
}