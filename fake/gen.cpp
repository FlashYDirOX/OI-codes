#include <cstdio>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(0));

	printf("%d %d", rand() % 10000, rand() % 10000);

	return 0;
}
