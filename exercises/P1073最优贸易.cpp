//    分层图   模板题
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

#define SPFA
//#define TARJAN
//
//SPFA TARJAN两种方法实现

using std::queue;

const int MAXN = 100001 << 2;
const int MAXM = 500001 << 2;
const int INF = 0x3f3f3f3f;

int N, M, cnt;
int cost[MAXN];
int e, start[MAXM], nxt[MAXM], to[MAXM], value[MAXM];

#ifdef SPFA
int d[MAXN], sign[MAXN];
#endif

inline void add_edge ( int, int, int );

inline int spfa ();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	
	rep(i, 1, N)
		scanf("%d", &cost[i]);

	rep(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(w == 1){
			add_edge(u, v, 0);
			add_edge(u, v + N, -cost[v]);
			add_edge(u + N, v + N, 0);
			add_edge(u + N, v + (N << 1), cost[v]);
			add_edge(u + (N << 1), v + (N << 1), 0);
		}
		else {
			add_edge(u, v, 0);
			add_edge(v, u, 0);
			add_edge(u, v + N, -cost[v]);
			add_edge(v, u + N, -cost[u]);
			add_edge(u + N, v + N, 0);
			add_edge(v + N, u + N, 0);
			add_edge(u + N, v + (N << 1), cost[v]);
			add_edge(v + N, u + (N << 1), cost[u]);
			add_edge(u + (N << 1), v + (N << 1), 0);
			add_edge(v + (N << 1), u + (N << 1), 0);
		}
	}

#ifdef SPFA
	cnt = std::max(cnt, spfa());
	printf("%d", cnt);
#endif

	return 0;
}

inline void add_edge ( int u, int v, int w )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
	value[e] = w;
}

inline int spfa ()
{
	queue<int> Q;
	int step = ( N << 1 ) | N ;
	rep(i, 1, step)
		d[i] = -INF;
	
	Q.push(1);
	sign[1] = 1;
	d[1] = 0;

	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		sign[node] = 0;
		for(register int i = start[node]; i; i = nxt[i]){
			int now = to[i];
			if(d[node] + value[i] > d[now]){
				d[now] = d[node] + value[i];
				if(!sign[now]){
					Q.push(now);
					sign[now] = 1;
				}
			}
		}
	}
	return d[(N << 1) + N];
}
