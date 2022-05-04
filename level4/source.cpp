#include <cstdio>
#include <cstdlib>

int m;

void p(char *string)
{
	printf(string);
}

void n()
{
	char input[520];

	fgets(input, 512, stdin);
	p(input);

	if (m == 16930116)
	{
		system("/bin/cat /home/user/level5/.pass");
	}
}

int main()
{
	n();

	return 0;
}