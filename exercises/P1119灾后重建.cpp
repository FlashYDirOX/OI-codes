#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 301;
const int MAXM = 50001;
const int INF = 0x3f3f3f3f;

int N, M, Q, sum, cnt;
int t[MAXN], x[MAXM], y[MAXM], z[MAXM], f[MAXN][MAXN];
bool sign[MAXN];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, N)
		rep(j, 1, N){
			f[i][j] = INF; 
			f[i][i] = 0;
		}

	rep(i, 1, N)
		scanf("%d", &t[i]);

	rep(i, 1, M){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		f[u + 1][v + 1] = f[v + 1][u + 1] = w;
	}

	scanf("%d", &Q);

	rep(i, 1, Q){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		x[i] = u + 1;
		y[i] = v + 1;
		z[i] = w;
		sum = w;
	}

	cnt = 1;

	rep(p, 1, Q){
		rep(k, 1, N){
			if(z[p] >= t[k] && !sign[k]){
				sign[k] = 1;
				rep(i, 1, N)
					rep(j, 1, N){
						if(i == k || k == j || i == j)
							continue ;
						if(f[i][j] > f[i][k] + f[k][j])
							f[i][j] = f[i][k] + f[k][j];
					}
			}
		}
		if(t[x[p]] <= z[p] && t[y[p]] <= z[p] && f[x[p]][y[p]] < INF)
			printf("%d\n", f[x[p]][y[p]]);
		else
			puts("-1");
	}

	return 0;
}
