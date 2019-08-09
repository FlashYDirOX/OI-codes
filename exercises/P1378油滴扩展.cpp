#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

#define rep(i, a, b) for(register int i = a; i <= b; i++) 
using std::min;
using std::max;
using std::abs;

const int MAXN = 9;
const int INF = 0x3f3f3f3f;

int N, a[MAXN], b[MAXN], x[MAXN], y[MAXN];
bool flag[MAXN];
double d[MAXN], ans;

inline void dfs ( int, double );

inline double dist ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	scanf("%d%d%d%d", &x[1], &y[1], &x[2], &y[2]);

	rep(i, 1, N)
		scanf("%d%d", &a[i], &b[i]);

	dfs(1, 0);

	printf("%0.0f\n", (double)(abs(x[1] - x[2]) * abs(y[1] - y[2])) - ans);

	return 0;
}

inline void dfs ( int step, double cnt )
{
	if(step == N + 1){
		ans = max(ans, cnt);
		return ;
	}

	rep(i, 1, N)
		if(!flag[i]){
			bool jump = false;
			rep(j, 1, N)
				if(flag[j] && d[j] >= dist(i, j)){
					jump = true;
					flag[i] = true;
					dfs(step + 1, cnt);
					flag[i] = false;
				}

			if(jump)
				continue ;

			d[i] = min(abs(x[1] - a[i]), abs(x[2] - a[i]));
			d[i] = min(d[i], (double)min(abs(y[1] - b[i]), abs(y[2] - b[i])));

			flag[i] = true;
			
			rep(j, 1, N)
				if(i != j && flag[j])
					d[i] = min(d[i], dist(i, j) - d[j]);
			dfs(step + 1, cnt + M_PI * d[i] * d[i]);
			flag[i] = false;
			d[i] = 0;
		}
}

inline double dist ( int u, int v )
{
	int du = a[u] - a[v], dv = b[u] - b[v];
	return sqrt(du * du + dv * dv);
}
