#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::vector;

const int MAXN = 10010;
const int MAXM = 100010;

vector<int> G[MAXN];

int N, M, sum, color[MAXN], cnt[2];

inline int dfs ( int );

int main(){
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	memset(color, -1, sizeof(color));

	rep(i, 1, M){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	rep(i, 1, N)
		if(color[i] == -1){
			cnt[0] = cnt[1] = 0;
			color[i] = 1;
			sum += dfs(i);
		}

	printf("%d\n", sum);

	return 0;
}

inline int dfs ( int x )
{
	for(int i = 0; i < G[x].size(); i++){
		int v = G[x][i];
		if(color[v] == -1){
			color[v] = ( color[x] + 1 ) % 2;
			cnt[color[v]]++;
			dfs(v);
		}
		else if(color[v] == color[x]) {
			puts("Impossible");
			exit(0);
		}
	}
	//cnt1 + 1 < cnt2 ? printf("cnt1:") : printf("cnt2 ");
	//printf("%d\n", std::min(cnt1 + 1, cnt2));
	return std::min(cnt[0], cnt[1] + 1);
}
