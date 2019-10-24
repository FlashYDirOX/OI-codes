#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::queue;

const int MAXN = 1000010;
const int MAXM = 2000010;
const int MOD = 100003;
const int INF = 0x3f3f3f3f;

queue<int> Q;

int N, M, root, d[MAXN], cnt[MAXN];
int start[MAXM], nxt[MAXM], to[MAXM], e;
bool sign[MAXN];

inline void add_edge ( int, int );

inline void dfs ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, M){
		int u, v;
		scanf("%d%d", &u, &v);
		if(u == v)
			continue ;
		add_edge(u, v);
		add_edge(v, u);
	}

	rep(i, 1, N)
		d[i] = INF;

	sign[1] = 1;
	Q.push(1);
	d[1] = 0;
	cnt[1] = 1;

	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		sign[node] = 0;
		for(register int i = start[node]; i; i = nxt[i]){
			int now = to[i];
			if(d[now] > d[node] + 1){
				d[now] = d[node] + 1;
				cnt[now] = cnt[node];
				if(!sign[now]){
					Q.push(now);
					sign[now] = 1;
				}
			}
			else if(d[now] == d[node] + 1){
				cnt[now] += cnt[node];	
				cnt[now] %= MOD;
			}
		}
	}

	rep(i, 1, N)
		printf("%d\n", cnt[i]);

	return 0;
}

inline void add_edge ( int u, int v )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
}
