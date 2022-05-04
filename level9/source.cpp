#include <cstdlib>
#include <cstring>

class N
{
public:
	char m_Buffer[104];
	int m_Value;

	N(int value)
		: m_Value(value)
	{}

	int operator+(N number)
	{
		return m_Value + number.m_Value;
	}

	int operator-(N number)
	{
		return m_Value - number.m_Value;
	}

	void setAnnotation(char *str)
	{
		memcpy(m_Buffer, str, strlen(str));
	}
};

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		exit(1);
	}

	N *first = new N(5);
	N *second = new N(6);

	first->setAnnotation(argv[1]);

	return *first + *second;
}