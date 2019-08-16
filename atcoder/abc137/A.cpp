#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);

	printf("%d", std::max(a + b, (std::max(a - b, a * b))));

	return 0;
}
