#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 10001;
const int MAXM = (10001 << 2);
const int INF = 0x3f3f3f3f;

int N, M, d[MAXN], sign[MAXN], cnt, flag[MAXN];
int start[MAXM], nxt[MAXM], to[MAXM], value[MAXM], e;

inline void add_edge ( int, int, int );

inline bool spfa ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, M){
		int u, v, w, k;
		scanf("%d", &k);
		if(k == 1){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
		}
		else if(k == 2){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, -w);
		}
		else {
			scanf("%d%d", &u, &v);
			add_edge(u, v, 0);
			add_edge(v, u, 0);
		}
	}

	rep(i, 1, N){
		add_edge(0, i, 0);
		d[i] = -INF;
	}

	spfa(0) ? puts("Yes") : puts("No");	

	return 0;
}

inline void add_edge ( int u, int v, int w )
{ 
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
	value[e] = w;
}

inline bool spfa ( int node )
{
	flag[node] = 1;
	for(register int i = start[node]; i; i = nxt[i]){
		int now = to[i];
		if(d[node] + value[i] > d[now]){
			d[now] = d[node] + value[i];
			if(flag[now])
				return false;
			else
				if(!spfa(now))
					return false;
		}
	}
	flag[node] = 0;
	return true;
}
