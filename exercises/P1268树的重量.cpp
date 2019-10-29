#include <cstdio>
#include <cctype>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 31;

int N;
int G[MAXN][MAXN];

inline int read ();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	while(~scanf("%d", &N), N != 0){
		rep(i, 1, N)
			rep(j, 1, N)
				G[i][j] = ( i == j ? 0 : (G[j][i] ? G[j][i]: read()));
	}

	return 0;
}

inline int read ()
{
	int x = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		x = (x << 1) + (x << 3) + c - 48;
		c = getchar();
	}
	return x;
}
