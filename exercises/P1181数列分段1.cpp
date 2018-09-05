#include <cstdio>

const int MAXN = 100010;

int cnt, ans;

inline int read();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	int N, M;

	N = read(), M = read();

	for (register int i = 1; i <= N; i++) {
		int x = read();

		if (x + cnt > M) {
			ans++;
			cnt = x;
		}
		else
			cnt += x;
	}

	printf("%d", ans + 1);

	return 0;
}

inline int read()
{
	char c = getchar();
	int x = 0;
	while (c > '9' || c < '0')
		c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x;
}
