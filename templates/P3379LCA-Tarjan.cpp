#include <cstdio>
#include <cctype>

#define REP(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 500001;

struct graph {
	int to, nxt, start;
}G[MAXN], quest[MAXN];

inline int read ();

inline void add_edge ( int u, int v );

inline void add_quest ( int u, int v );

int N, M, S, e;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	N = read(), M = read(), S = read();

	REP(i, 1, N - 1){
		int x = read(), y = read();
		add_edge(x, y);
	}

	e = 0;

	REP(i, 1, M){
		int x = read(), y = read();
		add_quest(x, y);
	}

	return 0;
}

inline int read ()
{
	int var = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		var = var * 10 + c - 48;
		c = getchar();
	}
	return var;
}

inline void add_edge ( int u, int v )
{
	G[++e].
}

inline void add_quest ( int u, int v );
