#include <cstdio>
#include <cmath>

inline double dist ( int u1, int v1. int u2, int v2 );

inline void search ( int k );

int main()
{
#ifndef ONLINE_JUGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	
	int N, x1, x2, y1, y2;

	scanf("%d%d%d%d%d", &N, &x1, &x2, &y1, &y2);

	for (register int i = 1; i <= N; i++)
		scanf ("%d%d", x[i], y[i]);

	for (register int i = 1; i <= N; i++)
		search(i);

	return 0;
}

inline void search ( int k )
{
	for (register int i = 1; i <= N; i++)
		max_r = std::min(dist(x[k], y[k], x[i], y[i]), max_r); 

	max_r = std::min(max_r, std::min(std::max(
}

inline double dist ( int u1, int v1. int u2, int v2 )
{
	return sqrt((u1 - u2) * (u1 - u2) + (v1 - v2) * (v1 - v2));
}
