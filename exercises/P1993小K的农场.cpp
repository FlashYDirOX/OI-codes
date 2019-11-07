#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 10001;

int N, M;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, M){
		int u, v, w, k;
		scanf("%d", &k);
		if(k == 1){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
		}
		else if(k == 2){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, -w);
		}
		else {
		}
	}

	return 0;
}
