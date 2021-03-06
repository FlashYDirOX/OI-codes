#include <cstdio>

#define REP(i, a, b) for(int i = a; i <= b; i++)

const int MAXN = 201;

int N, K;
int f[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &K);

	REP(i, 1, N)
		f[i][1] = 1;
	REP(i, 1, N)
		REP(j, 2, K)
			if(i >= j)
				f[i][j] = f[i - 1][j - 1] + f[i - j][j];

	printf("%d", f[N][K]);

	return 0;
}
