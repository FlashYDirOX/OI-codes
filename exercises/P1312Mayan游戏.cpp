#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 8;
const int move[2][2] = {{-1, 0}, {1, 0}};
const int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int G[MAXN][MAXN];

inline void scan();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	scan();

	return 0;
}

inline void scan()
{	
	scanf("%d", &N);
	rep(i, 1, 5){
		int cnt = 1;
		for(;~scanf("%d", &G[i][cnt]), G[i][cnt] != 0; cnt++)
	}
}
