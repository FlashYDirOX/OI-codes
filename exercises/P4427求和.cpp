#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define frep(i, a, b) for(register int i = a; i >= b; i--)

using std::swap;

const int MAXN = 300001;
const int MAXM = 300001;
const int MOD = 998244353;
const int DEEP = 30;
const int MAXK = 51;

int N, M, k;
int deep[MAXN], f[MAXN][DEEP], d[MAXN][MAXK];
int start[MAXM], to[MAXM], nxt[MAXM], e;
bool sign[MAXM];

inline int read ();

inline void add_edge ( int, int );

inline void dfs ( int, int );

inline int ksm ( int, int );

inline int lca ( int, int );

inline void init ();

inline int calc ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	N = read();

	rep(i, 1, N - 1){
		int u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

	scanf("%d", &M); 
	rep(i, 1, M){
		int u = read(), v = read();
		k = read();
		if(!sign[k])
			init();
		printf("%d\n", calc(u, v));
	}

	return 0;
}

inline int read ()
{
	int var = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		var = ( var << 1 ) + ( var << 3 ) + c - 48;
		c = getchar();
	}
	return var;
}

inline void add_edge ( int u, int v )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
}

inline void dfs ( int node, int father )
{
	deep[node] = deep[father] + 1;
	d[node][k] = (d[father][k] + ksm(deep[node], k) % MOD) % MOD;
	rep(i, 1, DEEP)
		f[node][i] = f[f[node][i - 1]][i - 1];
	for(register int i = start[node]; i; i = nxt[i]){ 
		if(to[i] == father)
			continue ;
		f[to[i]][0] = node;
		dfs(to[i], node);
	}
}

inline int ksm ( int a, int b )
{
	int cnt = 1;
	while(b){
		if(b & 1)
			cnt = cnt * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return cnt;
}

inline int lca ( int u, int v )
{
	int step;
	if(deep[u] > deep[v])
		swap(u, v);
	step = deep[v] - deep[u];
	rep(i, 0, DEEP)
		if( ( 1 << i ) & step )
			v = f[v][i];
	if(u == v)
		return u;
	frep(i, DEEP, 0)
		if(f[u][i] == f[v][i])
			continue ;
		else{
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

inline void init ()
{
	sign[k] = true;
	memset(f, 0, sizeof(f));
	memset(deep, 0, sizeof(deep));
	deep[0] = -1;
	dfs(1, 0);
}

inline int calc ( int u, int v )
{
	int cnt = d[u][k] + d[v][k] - d[lca(u, v)][k] - d[f[lca(u, v)][0]][k];
	return cnt % MOD;
}
