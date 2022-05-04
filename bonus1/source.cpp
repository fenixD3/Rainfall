#include <cstring>
#include <unistd.h>
#include <cstdlib>

int main(int ac, char **av)
{
	char buffer[40];
	int size = atoi(av[1]);

	if (size < 10)
	{
		memcpy(buffer, av[2], size * 4);
		if (size == 1464814662)
		{
			execl("/bin/sh", "sh", 0);
		}
		return 1;
	}
	return 0;
}