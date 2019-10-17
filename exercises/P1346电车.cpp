#include <cstdio>
#include <queue>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::queue;

queue<int> Q;

const int MAXN = 101;
const int INF = 0x3f3f3f3f;

int N, f, l, G[MAXN][MAXN];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &f, &l);

	rep(i, 1, N)
		rep(j, 1, N){
			G[i][j] = INF;
			G[i][i] = 0;
		}

	rep(i, 1, N){
		int step, u;
		scanf("%d", &step);
		rep(j, 1, step){
			scanf("%d", &u);
			j == 1 ? G[i][u] = 0 : G[i][u] = 1;
		}
	}

	rep(k, 1, N)
		rep(i, 1, N)
			rep(j, 1, N)
				G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);

	printf("%d", G[f][l] == INF ? -1 : G[f][l]);

	return 0;
}
