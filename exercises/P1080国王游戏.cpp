#include <cstdio>
#include <algorithm>

const int MAXN = 1010;

int N;

struct people {
	int left, right;
}G[MAXN];

inline int read();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	N = read();

	for (register int i = 0; i <= N; i++)
		G[i].left = read(), G[i].right = read();

	return 0;
}

inline int read()
{
	int var;
	char c = getchar();
	while (c > '9' || c < '0')
		c = getchar();
	while (c >= '0' && c <= '9') {
		var = (var << 3) + (var << 1) + c ^ '0';
		c = getchar();
	}
	return var;
}
