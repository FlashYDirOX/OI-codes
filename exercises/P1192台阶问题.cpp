#include <cstdio>

const int MAXN = 100001;
const int MOD = 100003;

int f[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	int N, K;

	scanf("%d%d", &N, &K);

	f[0] = 1;

	for (register int i = 1; i <= N; i++)
		for (register int j = 1; j <= K && (i >= j); j++)
			f[i] = (f[i] + f[i - j]) % MOD;

	printf ("%d", f[N]);
	
	return 0;
}
