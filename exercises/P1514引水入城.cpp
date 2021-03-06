#include <cstdio>

#define REP(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 501;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M;
int G[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	
	REP(i, 1, N)
		REP(j, 1, M)
			scanf("%d", &G[i][j]);

	return 0;
}
