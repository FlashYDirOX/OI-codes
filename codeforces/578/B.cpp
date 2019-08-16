#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 101;

int G[MAXN];

int main()
{
	int t, N, M, K;
	scanf("%d", &t);
	for(;t;t--){
		bool flag = false;
		scanf("%d%d%d", &N, &M, &K);
		rep(i, 1, N)
			scanf("%d", &G[i]);
		rep(i, 1, N - 1){
			if(G[i] + K >= G[i + 1])
				M += G[i] - std::max(G[i + 1] - K, 0);
			if(G[i] + K <= G[i + 1]){
				M -= G[i + 1] - G[i] - K;
				if(M < 0){
					flag = true;
					break ;
				}
			}
		}
		flag ? puts("NO") : puts("YES");
	}


	return 0;
}
