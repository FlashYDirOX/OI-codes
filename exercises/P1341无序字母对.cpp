#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 52;
const int INF = 0x3f3f3f3f;

struct node {
	int gree, asc;
	bool operator < ( const node &x ) const {
		if(x.gree != gree)
			return x.gree < gree;
		else return x.asc < asc;
	}
}a[MAXN + 1];

int N, cnt, num1, num2, count, first = INF, G[MAXN + 1][MAXN + 1], top, ans[MAXN + 1];
bool flag[MAXN + 1];

inline void dfs ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	getchar();

	rep(i, 1, N){
		char c1 = getchar(), c2 = getchar();
		int u = c1 - 'A', v = c2 - 'A';
		getchar();
		first = std::min(first, std::min(u, v));
		G[u][v] = G[v][u] = 1;
		a[i].gree++;
		a[i].gree++;
		a[i].asc = u;
		a[i].asc = v;
	}

	std::sort(a, a + 52);

	rep(i, 1, N){
		if(a[i].gree & 1){
			cnt++;
			cnt == 1 ? num1 = a[i].asc : num2 = a[i].asc;
		}
		if(cnt != 2 && cnt != 0){
			puts("No Solution");
			exit(0);
		}
	}

	if(cnt == 0)
		dfs(first);
	else dfs(std::min(num1, num2));

	rep(i, 1, top)
		printf("%c", ans[top - i + 1] + 'A');

	return 0;
}

inline void dfs ( int x )
{
	rep(i, 0, 52){
		if(G[x][i]){
			G[x][i] = 0;
			G[i][x] = 0;
			dfs(i);
		}
	}
	ans[++top] = x;
}
