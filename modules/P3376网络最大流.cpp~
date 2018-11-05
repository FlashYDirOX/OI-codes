#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define REP(i, a, b) for(register int i = a; i <= b; i++)

using std::queue;

const int MAXN = 10001;
const int MAXM = 100001;
const int INF = 0x3f3f3f3f;

queue<int> Q;

int N, M, S, T;
int e, start[MAXN], nxt[MAXM], capa[MAXM], to[MAXM], flow[MAXM];
int level[MAXM], ans;

inline void IN ();

inline void add_edge ( int u, int v, int w );

inline bool bfs ();

inline int dfs ( int x, int cpflow );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	IN();

	while(bfs()){
		ans += dfs(S, INF);
	}

	printf("%d", ans);

	return 0;
}

inline void add_edge ( int u, int v, int w )
{
	++e;
	nxt[e] = start[u];
	start[u] = e;
	to[e] = v;
	capa[e] = w;
	flow[e] = 0;
}

inline void IN ()
{
	scanf("%d%d%d%d", &N, &M, &S, &T);

	REP(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}
}

inline bool bfs ()
{
	memset(level, 0, sizeof(level));
	while(!Q.empty())
		Q.pop();
	Q.push(S);
	level[S] = 1;
	while(!Q.empty()){
		int now = Q.front();
		for(int i = start[now]; i; i = nxt[i]){
			int node = to[i];
			if(!level[node] && capa[i] > flow[i]){
				level[node] = level[now] + 1;
				Q.push(node);
			}
		}
	}
	return level[T] ? 1 : 0;
}

inline int dfs ( int x, int maxflow )
{
	int addflow = 0;
	if(x == T)
		return maxflow;
	for(int i = start[x]; i; i = nxt[i]){
		int node = to[i];
		if(level[x + 1] == level[node]){
			int tmp = dfs(node, std::min(maxflow - addflow, capa[i] - flow[i]));
			flow[i] += tmp;
			flow[to[i]] -= tmp;
			addflow += tmp;
		}
	}
	return addflow;
}
