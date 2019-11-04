#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 31;
const int INF = 0x3f3f3f3f;

int N, ans, cnt;
int dist[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	while(~scanf("%d", &N), N != 0){
		rep(i, 1, N - 1)
			rep(j, i + 1, N){
					scanf("%d", &dist[i][j]);
			}
		cnt = dist[1][2];
		rep(i, 3, N){
			int sum = INF;
			rep(j, 2, i - 1)
				sum = std::min(sum, (dist[1][i] - dist[1][j] + dist[j][i]) >> 1);
			cnt += sum;
		}
		printf("%d\n", cnt);
	}


	return 0;
}
