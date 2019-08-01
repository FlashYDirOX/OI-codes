#include <cstdio>
#include <queue>

using std::priority_queue;
#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100010;
const int MAXM = 200010;
const int INF = 2147483647;

struct node {
	int dis, num;
	bool operator < ( const node &x ) const
	{
		return x.dis < dis;
	}
};

priority_queue<node> Q;

int N, M, S;
int d[MAXN];
int e, start[MAXM], nxt[MAXM], to[MAXM], value[MAXM];

inline void add_edge ( int, int, int );

inline void dijkstra ();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &M, &S);

	rep(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}

	dijkstra();

	rep(i, 1, N)
		printf("%d ", d[i]);

	return 0;
}

inline void add_edge ( int u, int v, int w )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
	value[e] = w;
}

inline void dijkstra ()
{
	rep(i, 1, N)
		d[i] = INF;
	d[S] = 0;
	Q.push( (node){0, S});
	while(!Q.empty()){
		node tmp = Q.top();
		Q.pop();
		if(d[tmp.num] ^ tmp.dis)
			continue;
		for(register int i = start[tmp.num]; i; i = nxt[i])
			if(d[tmp.num] + value[i] < d[to[i]]){
				d[to[i]] = d[tmp.num] + value[i];
				Q.push( (node){d[to[i]], to[i]});
			}
	}
}
