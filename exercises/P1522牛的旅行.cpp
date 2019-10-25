#include <cstdio>
#include <cmath>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::min;
using std::max;

const int MAXN = 151;
const int INF = 0x3f3f3f3f;

int N, flag = 1;
int G[MAXN][MAXN], x[MAXN], y[MAXN], dist[MAXN][MAXN], father[MAXN], maxd[MAXN];

inline void dfs ( int node );

inline double calc ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);
	rep(i, 1, N)
		scanf("%d%d", &x[i], &y[i]);
	rep(i, 1, N){
		rep(j, 1, N){
			dist[i][j] = INF;
			int value;
			scanf("%d%d", &value);
			if(value)
				dist[i][j] = sqrt(i, j);
		}
		dist[i][i] = 0;
	}

	rep(k, 1, N)
		rep(i, 1, N)
			rep(j, 1, N)
				if(i != j && j != k)
					if(dist[i][k] != INF && dist[k][j] != INF)
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	rep(i, 1, N)
		if(!sign[i]){
			dfs(i);
			flag = 2;
		}

	rep(i, 1, N)
		rep(j, 1, N){
			if(dist[i][j] != INF)
				maxd[i] = max(maxd[i], dist[i][j]);
			cnt = max(cnt, maxd[i]);
		}

	rep(i, 1, N)
		rep(j, 1, N){
		}

	return 0;
}

inline void dfs ( int node )
{
	if(sign[node])
		return ;
	for(register int i = start[node]; i; i = nxt[i]){
		sign[node] = flag;
		dfs(to[i]);
	}
}

inline double calc ( int u, int v )
{
	return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}
