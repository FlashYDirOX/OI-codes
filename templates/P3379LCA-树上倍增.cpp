#include <cstdio>
#include <algorithm>
#include <cmath>

#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define frep(i, a, b) for(register int i = a; i >= b; i--)

using std::swap;

const int MAXN = 500010;
const int MAXM = 1000020;

int N, M, S, f[MAXN][21], deep[MAXN];
int e, start[MAXM], nxt[MAXM], to[MAXM];
bool flag[MAXN];

inline void add_edge ( int, int );

inline void dfs ( int );

inline int lca ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &M, &S);

	rep(i, 1, N - 1){
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}

	deep[S] = 1;
	dfs(S);

	rep(i, 1, M){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", lca(u, v));
	}

	return 0;
}

inline void add_edge ( int u, int v )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
}

inline void dfs ( int node )
{
	flag[node] = true;
	rep(i, 1, 20)
		f[node][i] = f[f[node][i - 1]][i - 1];
	for(register int i = start[node]; i; i = nxt[i]){
		if(flag[to[i]])
			continue ;
		flag[to[i]] = true;
		f[to[i]][0] = node;
		deep[to[i]] = deep[node] + 1;
		dfs(to[i]);
	}
}

/*
inline void dfs ( int node, int father )
{
	deep[node] = deep[father] + 1;
	for(register int i = 1; i <= 20; i++)
		f[node][i] = f[f[node][i - 1]][i - 1];
	for(register int i = start[node]; i; i = nxt[i]){
		if(to[i] == father)
			continue ;
		f[to[i]][0] = node;
		dfs(to[i], node);
	}
}
*/

inline int lca ( int u, int v )
{
	int d;
	if(deep[u] > deep[v])
		swap(u, v);
	d = deep[v] - deep[u];
	rep(i, 0, 20)
		if((1 << i) & d)
			v = f[v][i];
	if(u == v)
		return u;
	frep(i, 20, 0)
		if(f[u][i] == f[v][i])
			continue ;
		else{
			u = f[u][i];
			v = f[v][i];
		}

	return f[u][0];
}
