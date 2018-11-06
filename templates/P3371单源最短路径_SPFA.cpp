#include <cstdio>
#include <queue>

#define REP(i, a, b) for(int i = a; i <= b; i++)

using std::queue;

const int MAXN = 10001;
const int MAXM = 500001;
const int INF = 1e9;

queue<int> Q;

int N, M, S, d[MAXN];
int e, start[MAXM], to[MAXM], nxt[MAXM], value[MAXM];
bool flag[MAXN];

inline void add_edge ( int u, int v, int w );

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

	REP(i, 1, N)
		d[i] = INF;
	d[S] = 0;

	Q.push(S);
	flag[S] = true;

	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		flag[now] = false;
		for(int i = start[now]; i; i = nxt[i]){
			int node = to[i];
			if(d[now] + value[i] < d[node]){
				d[node] = d[now] + value[i];
				if(!flag[node]){
					Q.push(node);
					flag[node] = true;
				}
			}
		}
	}

	REP(i, 1, N)
		d[i] == INF ? printf("%d ", 2147483647) : printf("%d ", d[i]);

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
