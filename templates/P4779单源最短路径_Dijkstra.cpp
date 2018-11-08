#include <cstdio>
#include <queue>

using std::priority_queue;

#define REP(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100001;
const int MAXM = 200001;
const int INF = 2147483647;

struct Node {
	int num, dist;
	bool operator < ( const Node& x ) const
	{
		return x.dist < dist;
	}
}G[MAXM];

priority_queue<Node> Q;

int N, M, S, d[MAXN];
int start[MAXM], nxt[MAXM], to[MAXM], value[MAXM], e;

inline void add_edge ( int u, int v, int w );

inline void Dijkstra ();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &M, &S);

	REP(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}

	Dijkstra();

	REP(i, 1, N)
		printf("%d ", d[i]);

	return 0;
}

inline void add_edge ( int u, int v, int w )
{
	++e;
	nxt[e] = start[u];
	start[u] = e;
	to[e] = v;
	value[e] = w;
}

inline void Dijkstra ()
{
	REP(i, 1, N)
		d[i] = INF;
	d[S] = 0;
	Q.push((Node){S, 0});
	while(!Q.empty()){
		Node now = Q.top();
		Q.pop();
		if(now.dist ^ d[now.num])
			continue ;
		for(int i = start[now.num]; i; i = nxt[i]){
			int node = to[i];
			if(d[node] > value[i]){
				d[node] = value[i];
				Q.push((Node){node, d[node]});
			}
		}
	}
}
