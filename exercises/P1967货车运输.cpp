#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define rep(i, a ,b) for(register int i = a; i <= b; i++)
#define rep(i, a ,b) for(register int i = a; i >= b; i--)

using std::sort;
using std::swap;
using std::min;
using std::max;

const int MAXN = 10010;
const int MAXM = 50010;
const int INF = 0x3f3f3f3f;

struct edge {
	int u, v, w;
	bool operator < (const edge& a)const
	{
		return a.w > w;
	}
}G[MAXN];

int N, M, Q;
int fa[MAXN][20], deep[MAXN], f[MAXN], dist[MAXN][20];
int start[MAXM], to[MAXM], nxt[MAXM], value[MAXN], e;
bool flag[MAXN];

inline void kruscal ();

inline int find ( int );

inline void add_edge ( int, int, int );

inline void dfs ( int );

inline int lca ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, M)
		scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);

	kruscal();

	rep(i, 1, N){
		if(!flag[i]){
			deep[i] = 1;
			dfs(i);
			fa[i][0] = i;
			dist[i][0] = INF;
		}
	}

	rep(i, 1, 20)
		rep(j, 1, N){
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
			dist[j][i] = min(dist[fa[j][i - 1]][i - 1], dist[j][i]);
		}

	scanf("%d", &Q);

	rep(i, 1, Q){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d", lca(u, v));
	}

	return 0;
}

inline void kruscal ()
{
	rep(i, 1, N)
		f[i] = i;
	sort(G + 1, G + M + 1);
	rep(i, 1, M){
		int u = G[i].u, v = G[i].v, w = G[i].w;
		int x = find(G[i].u), y = find(G[i].v);
		if(x != y){
			f[x] = y;
			add_edge(u, v, w);
			add_edge(v, u, w);
		}
	}
}

inline int find ( int x )
{
	return f[x] == x ? x : f[x] = find(f[x]);
}

inline void add_edge ( int u, int v, int w )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
	value[e] = w;
}

inline void dfs ( int node )
{
	flag[node] = true;
	for(register int i = start[node]; i; i = nxt[i]){
		if(flag[to[i]])
			continue ;
		deep[to[i]] = deep[node] + 1;
		fa[to[i]][0] = node;
		dist[to[i]][0] = value[i];
		dfs(to[i]);
	}
}

inline int lca ( int u, int v )
{
	int d, ans = INF;
	if(find(u) != find(v))
		return -1;
	if(deep[u] > deep[v])
		swap(u, v);
	d = deep[v] - deep[u];
	frep(i, 20, 1)
		if((1 << i) & d){
			ans = min(ans, w[u][i]);
			u = fa[u][i];
		}
	if(u == v)
		return u;
}
