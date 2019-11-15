//    分层图   模板题
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

#define DIJSTRA
//#define DP
//
//dijstra DP两种方法实现

using std::queue;
using std::priority_queue;

const int MAXN = 10001 << 7;
const int MAXM = 50001 << 7;
const int INF = 0x3f3f3f3f;

struct node {
	int num, dist;
	inline bool operator < (const node &x) const {
		return x.dist < dist;
	}
};

priority_queue<node> Q;

#ifdef DIJSTRA
int d[MAXN], sign[MAXN];
#endif

int N, M, K;
int start[MAXM], nxt[MAXM], to[MAXM], value[MAXM], e;

inline void add_edge ( int, int, int ); 

inline int dijstra ();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &M, &K);

	rep(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
		rep(j, 1, K){
			add_edge(u + j * N, v + j * N, w);
			add_edge(v + j * N, u + j * N, w);
			add_edge(u + (j - 1) * N, v + j * N, 0);
			add_edge(v + (j - 1) * N, u + j * N, 0);
		}
	}

#ifdef DIJSTRA
	printf("%d", dijstra());
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

inline int dijstra ()
{
	rep(i, 1, ( K + 1 ) * N)
		d[i] = INF;
	
	Q.push( (node) {1, 0} );
	sign[1] = 1;
	d[1] = 0;

	while(!Q.empty()){
		node p = Q.top();
		Q.pop();
		sign[p.num] = 1;
		if(p.dist ^ d[p.num])
			continue ;
		for(register int i = start[p.num]; i; i = nxt[i]){
			int now = to[i];
			if(d[p.num] + value[i] < d[now]){
				d[now] = d[p.num] + value[i];
				Q.push( (node) {now, d[now]} );
			}
		}
	}

	return d[N * (K + 1)];
}
