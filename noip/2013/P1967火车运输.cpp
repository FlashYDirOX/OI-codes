#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 10001;
const int MAXM = 500001;

struct edge {
	int u, v, w;
	inline bool operator < (const edge x)const
	{
		return x.w > w;
	}
	inline void in ( int u, int v, int w )
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
}G[MAXM];

int N, M, e, fa[MAXN];
int begin[MAXN], nxt[MAXM], to[MAXM], value[MAXM];

inline void add_edge ( int, int, int );

inline void kruscal ();

inline int find ( int );

inline int lca ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	int T;

	scanf("%d%d", &N, &M);

	rep(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[i].in(u, v, w);
	}

	std::sort(G + 1, G + M + 1);
	rep(i, 1, N)
		fa[i] = i;
	kruscal();

	scanf("%d", &T);

	rep(i, 1, T){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", lca(u, v));
	}

	return 0;
}

inline void add_edge ( int u, int v, int w )
{
	nxt[++e] = begin[u];
	begin[u] = e;
	to[e] = v;
	value[e] = w;
}

inline void kruscal ()
{
	rep(i, 1, M){
		int u = G[i].u, v = G[i].v, w = G[i].w;
		if(find(u) != find(v)){
			fa[u] = find(v);
			add_edge(u, v, w);
			add_edge(v, u, w);
		}
	}
}

inline int find ( int x )
{
	//return fa[x] == x ? x : fa[x] = find(fa[x]);
	return fa[x] == x ? x : find(fa[x]);
}

inline int lca ( int u, int v )
{
	int deep = 0, cnt = 0;
	if(find(u) != find(v))
		return -1;
	while(u != v){
		int lenu = 0, lenv = 0;
		for(register int i = begin[u]; i; i = nxt[i])
			if(fa[u] == to[i])
				lenu = value[i];
		for(register int i = begin[v]; i; i = nxt[i])
			if(fa[v] == to[i])
				lenv = value[i];
		deep++;
		cnt = std::max(cnt, std::max(lenu, lenv));
		u = fa[u], v = fa[v];
	}
	return cnt;
}
