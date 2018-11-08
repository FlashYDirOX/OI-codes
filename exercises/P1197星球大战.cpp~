#include <cstdio>

#define REP(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100001;
const int MAXM = 200001;

int N, M, K, father[MAXN], node[MAXN];
int e, start[MAXM], nxt[MAXM], to[MAXM];
bool broken[MAXN];

inline int find ( int x );

inline void add_edge ( int x, int y );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	REP(i, 1, M){
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y);
	}

	scanf("%d", &K);

	REP(i, 1, K){
		scanf("%d", &node[i]);
		broken[node[i]] = true;
	}

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
