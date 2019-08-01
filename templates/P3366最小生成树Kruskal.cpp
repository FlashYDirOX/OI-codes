#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 5010;
const int MAXM = 200010;

struct node {
	int u, v, w;
}G[MAXM];

int N, M, cnt, fa[MAXN];

inline bool compare ( node, node );

inline int find ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);
	}

	std::sort(G + 1, G + M + 1, compare);

	rep(i, 1, N)
		fa[i] = i;

	rep(i, 1, M){
		int u = find(G[i].u), v = find(G[i].v);
		if (u != v) {
			cnt += G[i].w;
			fa[v] = u;
		}
	}

	printf("%d\n", cnt);

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
