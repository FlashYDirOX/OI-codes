#include <cstdio>
#include <queue>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::queue;

const int MAXN = 201;
const int MAXM = 6001;

queue<int> Q;

struct node {
	int u, v, w, time;
}G[MAXM];

int N, M;
int fa[MAXN];

inline bool compare ( node, node );

inline int find ( int );

inline void kruscal ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, M){
		scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);
		G[i].time = i;
	}

	std::sort(G + 1, G + M + 1, compare);

	rep(i, 1, M)
		kruscal(i);
	
	return 0;
}

inline bool compare ( node a, node b )
{
	return a.w < b.w;
}

inline int find ( int x )
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void kruscal ( int time )
{
	int cnt = 0, sum = 0;
	rep(i, 1, N)
		fa[i] = i;
	rep(i, 1, M){
		int u = find(G[i].u), v = find(G[i].v);
		if ( u != v && time >= G[i].time ) {
			sum++;
			cnt += G[i].w;
			fa[v] = u;
		}
	}
	if ( sum + 1 != N )
		cnt = -1;
	printf("%d\n", cnt);
}
