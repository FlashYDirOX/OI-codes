#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 101;
const int INF = 0x3f3f3f3f;
const int p[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 5, -1, -2, -1, -3},
	{0, -1, 5, -3, -2, -4},
	{0, -2, -3, 5, -2, -2},
	{0, -1, -2, -2, 5, -1},
	{0, -3, -4, -2, -1, 0}
};

int dp[MAXN][MAXN], x[MAXN], y[MAXN], N;

char s1[MAXN], s2[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	int slen1, slen2;
	char c;
	
	scanf("%d", &slen1);
	getchar();
	rep(i, 1, slen1){
		scanf("%c", &c);
		if(c == 'A') 
			x[i] = 1;
        if(c == 'C') 
			x[i] = 2;
        if(c == 'G') 
			x[i] = 3;
        if(c == 'T') 
			x[i] = 4;
	}
	getchar();

	scanf("%d", &slen2);
	getchar();
	rep(i, 1, slen2){
		scanf("%c", &c);
		if(c == 'A') 
			y[i] = 1;
        if(c == 'C') 
			y[i] = 2;
        if(c == 'G') 
			y[i] = 3;
        if(c == 'T') 
			y[i] = 4;
	}

	rep(i, 1, slen1)
		rep(j, 1, slen2)
			dp[i][j] = -INF;

	dp[0][0] = 0;

	rep(i, 1, slen1)
		dp[i][0] = dp[i - 1][0] + p[x[i]][5];
	rep(i, 1, slen2)
		dp[0][i] = dp[0][i - 1] + p[5][y[i]];

	rep(i, 1, slen1)
		rep(j, 1, slen2){
			dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + p[x[i]][5]);
			dp[i][j] = std::max(dp[i][j], dp[i][j - 1] + p[5][y[j]]);
			dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + p[x[i]][y[j]]);
		}

	printf("%d", dp[slen1][slen2]);

	return 0;
}
