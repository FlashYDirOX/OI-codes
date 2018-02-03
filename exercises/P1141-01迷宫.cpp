#include <cstdio>

const int MAXN = 1010;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M;
int G[MAXN][MAXN], value[MAXN][MAXN], cx[MAXN * MAXN], cy[MAXN * MAXN];

inline void bfs(int x, int y);

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
		
		scanf("%d%d", &p, &q);
		if (!value[p][q])
			bfs(p, q);
		printf("%d\n", value[p][q]);
	}

	return 0;
}

inline void bfs(int x, int y)
{
	int head = 0, tail = 1;

	cx[head] = x, cy[head] = y;
	value[x][y] = 1;

	while (head < tail) {
		for (register int i = 0; i < 4; i++) {
			int u = cx[head] + d[i][0], v = cy[head] + d[i][1];
			if (u < 1 || v < 1 || u > N || v < N || value[u][v] || G[u][v] == G[cx[head]][cy[head]])
				continue ;
			tail++;
			cx[tail] = u;
			cy[tail] = v;
		}
		head++;
	}

	for (register int i = 0; i <= tail; i++)
		value[cx[i]][cy[i]] = tail;
}
