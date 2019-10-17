#include <cstdio>

const int MAXN = 13;

int N, M;
int f[MAXN << 1][MAXN << 1];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	f[1][0] = 1;

	for(register int j = 1; j <= M; j++)
		for(register int i = 2; i < N; i++){
			f[1][j] = f[N][j - 1] + f[2][j - 1];
			f[N][j] = f[1][j - 1] + f[N - 1][j - 1];
			f[i][j] = f[i - 1][j - 1] + f[i + 1][j - 1];
		}

	printf("%d", f[1][M]);

	return 0;
}
