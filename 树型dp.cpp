#include <cstdio>

const int MAXN = 205;

int N, M;
int nxt[MAXN], start[MAXN], to[MAXN], e;

inline void add_edge ( int x, int y );

int main()
{
	scanf ("%d%d", &N, &M);

	for (register int i = 1; i <= N; i++) {
		int a, b;
		scanf ("%d%d", &a, &b);
		add_edge(a, b);
	}

	return 0;
}

inline void add_edge ( int x, int y )
{
	++e;
	nxt[e] = start[x];
	start[x] = e;
	to[e] = y;
}
