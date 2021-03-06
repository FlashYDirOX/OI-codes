#include <cstdio>

#define REP(i, a, b) for(register int i = a; i <= b; i++)
#define FREP(i, a, b) for(register int i = a; i >= b; i--)

const int MAXN = 400001;
const int MAXM = 800001;

int N, M, K, father[MAXN], node[MAXN], total, ans[MAXN];
int e, start[MAXM], nxt[MAXM], to[MAXM];
bool broken[MAXN];

inline int find ( int x );

inline void add_edge ( int x, int y );

inline void merge ( int u, int v );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	REP(i, 1, N)
		father[i] = i;

	REP(i, 1, M){
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}

	scanf("%d", &K);

	REP(i, 1, K){
		scanf("%d", &node[i]);
		broken[node[i]] = true;
	}

	total = N - K;

	REP(i, 0, N - 1)
		for(int j = start[i]; j; j = nxt[j])
			if(!broken[i] && !broken[to[j]] && find(i) != find(to[j])){
					merge(i, to[j]);
					total--;
			}

	ans[K + 1] = total;

	FREP(j, K, 1){
		total++;
		broken[node[j]] = 0;
		for(int i = start[node[j]]; i; i = nxt[i]){
			if(!broken[to[i]] && find(node[j]) != find(to[i])){
				total--;
				merge(node[j], to[i]);
			}
		}
		ans[j] = total;
	}

	REP(i, 1, K + 1)
		printf("%d\n", ans[i]);

	return 0;
}

inline int find ( int x )
{
	return father[x] == x ? x : father[x] = find(father[x]);
}

inline void add_edge ( int x, int y )
{
	++e;
	nxt[e] = start[x];
	start[x] = e;
	to[e] = y;
}

inline void merge ( int u, int v )
{
	int x = find(u), y = find(v);
	if(x != y)
		father[x] = y;
}
