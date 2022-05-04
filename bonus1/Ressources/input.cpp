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