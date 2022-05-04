#include <cstdio>
#include <cstdlib>
#include <cstring>

char *auth = NULL;
char *service = NULL;

int main()
{
	char buffer[128];

	while (1)
	{
		printf("%p, %p\n", auth, service);

		if (!fgets(buffer, 128, stdin))
		{
			return 0;
		}

		if (!strncmp(buffer, "auth ", 5))
		{
			auth = (char*)malloc(4);

			if (strlen(buffer + 5) < 31)
			{
				strcpy(auth, buffer + 5);
			}
		}

		if (!strncmp(buffer, "reset", 5))
		{
			free(auth);
		}

		if (!strncmp(buffer, "service", 6))
		{
			service = strdup(buffer + 7);
		}

		if (!strncmp(buffer, "login", 5))
		{
			if (*auth + 32)
			{
				system("/bin/sh");
			}
			else
			{
				fwrite("Password:\n", 1, 10, stdout);
			}
		}
	}

	return 0;
}