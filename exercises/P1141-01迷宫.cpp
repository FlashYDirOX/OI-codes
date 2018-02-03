#include <cstdio>

const int MAXN = 1010;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M, cnt;
int G[MAXN][MAXN], value[MAXN][MAXN], cx[MAXN * MAXN], cy[MAXN * MAXN];

inline void dfs(const int& x, const int& y);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	for (register int i = 1;i <= N; i++)
		for (register int j = 1; j <= N; j++)
			scanf("%1d", &G[i][j]);

	for (register int i = 1; i <= M; i++) {
		int p, q;
		cnt = 0;
		
		scanf("%d%d", &p, &q);

		if (!value[p][q]) {
			dfs(p, q);
			for (register int i = 0; i <= cnt; i++)
				value[cx[i]][cy[i]] = cnt;
		}

		printf("%d\n", value[p][q]);
	}

	return 0;
}

inline void dfs(const int&  x, const int& y)
{
	cnt++;
	cx[cnt] = x, cy[cnt] = y;
	value[x][y] = 1;

	for (register int i = 0; i < 4; i++) {
		int u = x + d[i][0], v = y + d[i][1];
		if (u < 1 || v < 1 || u > N || v > N || value[u][v] || G[u][v] == G[x][y])
			continue ;
		value[u][v] = 1;

		dfs(u, v);
	}
}
