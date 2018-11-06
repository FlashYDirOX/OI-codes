#include <cstdio>
#include <queue>
#include <cstring>

#define REP(i, a, b) for(register int i = a; i <= b; i++)

using std::queue;

const int MAXN = 2001;
const int MAXM = 3001;
const int INF = 1e9;

queue<int> Q;

inline void add_edge ( int u, int v, int w );

inline void init();

inline bool SPFA ();

int N, M, d[MAXN], calc[MAXN];
int start[MAXM], to[MAXM], value[MAXM], nxt[MAXM], e;
bool flag[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	while(T--){
		scanf("%d%d", &N, &M);

		REP(i, 1, M){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if(w < 0)
				add_edge(u, v, w);
			else{
				add_edge(u, v, w);
				add_edge(v, u, w);
			}
		}
		init();
		SPFA() ? puts("YE5") : puts("N0");
	}

	return 0;
}

inline void add_edge ( int u, int v, int w ){
	++e;
	nxt[e] = start[u];
	start[u] = e;
	to[e] = v;
	value[e] = w;
}

inline void init ()
{
	while(!Q.empty())
		Q.pop();

	e = 0;

	memset(flag, 0, sizeof(flag));
	memset(calc, 0, sizeof(calc));
	memset(start, 0, sizeof(start));
	memset(nxt, 0, sizeof(nxt));
	memset(value, 0, sizeof(value));
	memset(to, 0, sizeof(to));

	REP(i, 1, N)
		d[i] = INF;
}

inline bool SPFA()
{
	d[1] = 0;
	Q.push(1);
	flag[1] = true;

	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		flag[now] = false;
		if(calc[now] >= N)
			return true;
		for(register int i = start[now]; i; i = nxt[i]){
			int node = to[i];
			if(d[now] + value[i] < d[node]){
				d[node] = d[now] + value[i];
				if(!flag[node]){
					calc[node]++;
					Q.push(node);
					flag[node] = true;
					if(calc[node] > N && value[i] < 0)
						return true;
				}
			}
		}
	}

	return false;
}
