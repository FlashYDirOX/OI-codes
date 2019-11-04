#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 31;
const int INF = 0x3f3f3f3f;

int N, ans, cnt;
int G[MAXN][MAXN], dist[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	while(~scanf("%d", &N), N != 0){
		rep(i, 1, N)
			rep(j, i + 1, N)
				if(i == j)
					G[i][j] = 0;
				else {
					scanf("%d", &G[i][j]);
					G[j][i] = G[i][j];
				}
		rep(i, 3, N){
			int sum = INF;
			rep(j, 2, i - 1){
				ans = std::min(ans, dist[1][i] - dist[1][j] + (dist[i][j] >> 1));
				cnt += ans;
			}
		}
		printf("%d\n", cnt);
	}


	return 0;
}
