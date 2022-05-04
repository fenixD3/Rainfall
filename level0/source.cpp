#include <cstdlib>
#include <cstdio>
#include <cstring>
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	if (atoi(argv[1]) == 423)
	{
		char *const args[] = { strdup("/bin/sh"), NULL };
		gid_t gid = getegid();
		uid_t uid = geteuid();

		setresgid(gid, gid, gid);
		setresuid(uid, uid, uid);
		execv("/bin/sh", args);
	}
	else
	{
		fwrite("No !\n", 1, 5, stderr);
	}

	return 0;
}
