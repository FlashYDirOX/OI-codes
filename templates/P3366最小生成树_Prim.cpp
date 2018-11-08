#include <cstdio>
#include <queue>

#define REP(i, a, b) for(int i = a; i <= b; i++)

using std::priority_queue;

const int MAXN = 5001 << 1;
const int MAXM = 200001 << 1;
const int INF = 1e9;

struct Node {
	int num, dist;
	bool operator < (const Node& a) const
	{
		return a.dist < dist;
	}
}G[MAXN];

priority_queue<Node> Q;

int N, M, d[MAXN], visit[MAXN], cnt;
int start[MAXM], nxt[MAXM], to[MAXM], value[MAXM], e;

inline void add_edge ( int u, int v, int w );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	REP(i, 1, M){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add_edge(x, y, z);
		add_edge(y, x, z);
	}

	REP(i, 1, N)
		d[i] = INF;

	d[1] = 0;
	visit[1] = true;
	Q.push((Node){1, 0});

	while(!Q.empty()){
		Node now = Q.top();
		Q.pop();
		if(now.dist ^ d[now.num])
			continue ;
		cnt += now.dist;
		visit[now.num] = true;
		for(int i = start[now.num]; i; i = nxt[i]){
			int node = to[i];
			if(d[node] > value[i] && !visit[node]){
				d[node] = value[i];
				Q.push((Node){node, d[node]});
			}
		}
	}
	
	printf("%d", cnt);

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
