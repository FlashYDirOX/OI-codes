#include <cstdio>

int k, x;

int main()
{
	scanf("%d%d", &k, &x);

	for(register int i = x - k + 1; i <= x + k - 1; i++)
		printf("%d ", i);

	return 0;
}
