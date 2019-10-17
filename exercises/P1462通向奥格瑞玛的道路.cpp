#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::queue;

const int MAXN = 10010;
const int MAXM = 100010;
const int INF = 0x3f3f3f3f;

queue<int> Q;

int N, M, B, head, tail, cnt;
int c[MAXN], cost[MAXN], d[MAXN];
int start[MAXM], to[MAXM], nxt[MAXM], value[MAXM], e;
bool sign[MAXN];

inline void add_edge ( int, int, int );

inline bool spfa ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &M, &B);

	rep(i, 1, N){
		scanf("%d", &cost[i]);
		c[i] = cost[i];
	}

	std::sort(c + 1, c + N + 1);

	rep(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}

	if(!spfa(INF)){
		puts("AFK");
		exit(0);
	}
	
	head = 1, tail = N;

	while(head <= tail){
		int mid = (head + tail) / 2;
		if(spfa(c[mid])){
			cnt = c[mid];
			tail = mid - 1;
		}
		else
			head = mid + 1;
	}

	printf("%d\n", cnt);

	return 0;
}

inline void add_edge ( int u, int v, int w )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
	value[e] = w;
}

inline bool spfa ( int v )
{
	while(!Q.empty())
		Q.pop();

	memset(sign, 0, sizeof(sign));
	rep(i, 1, N)
		d[i] = INF;
	d[1] = 0;
	sign[1] = true;
	Q.push(1);

	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		sign[node] = false;
		for(register int i = start[node]; i; i = nxt[i]){
			int now = to[i];
			if(d[now] > d[node] + value[i] && cost[now] <= v){
				d[now] = d[node] + value[i];
				if(!sign[now]){
					sign[now] = true;
					Q.push(now);
				}
			}
		}
	}
	if(d[N] <= B)
		return true;
	return false;
}
