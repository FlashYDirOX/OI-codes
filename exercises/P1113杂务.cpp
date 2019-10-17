#include <cstdio>
#include <queue>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::queue;

const int MAXN = 10010;
const int MAXM = 1000001;

queue<int> Q;

int N, fa[MAXN], cnt, time[MAXN], end[MAXN];
int start[MAXM], nxt[MAXM], value[MAXM], degree[MAXM], to[MAXM], e;

inline void add_edge ( int, int );

inline void bfs ();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	rep(i, 1, N){
		int u, v;
		scanf("%d", &u);
		scanf("%d", &time[u]);
		while(~scanf("%d", &v), v){
			add_edge(v, u);
			degree[u]++;
		}
	}

	bfs();

	printf("%d", cnt);

	return 0;
}

inline void add_edge ( int u, int v )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
}

inline void bfs ()
{
	rep(i, 1, N)
		if(!degree[i])
			Q.push(i);

	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		end[node] += time[node];
		cnt = std::max(cnt, end[node]);
		for(register int i = start[node]; i; i = nxt[i]){
			int num = to[i];
			degree[num]--;
			end[num] = std::max(end[num], end[node]);
			if(!degree[num])
				Q.push(num);
		}
	}
}
