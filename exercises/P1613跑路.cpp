#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 300001;
const int MAXM = 300001;

int N;
int start[MAXM], nxt[MAXM], to[MAXM], e;

inline void add_edge ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	rep(i, 1, N - 1){
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}



	return 0;
}

inline void add_edge ( int u, int v )
{
	nxt[e] = start[u];
	start[u] = e;
	to[e] = v;
}
