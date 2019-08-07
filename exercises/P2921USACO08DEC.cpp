#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100001;

int G[MAXN], f[MAXN], deep[MAXN], N;
bool flag[MAXN];

inline void dfs ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	rep(i, 1, N)
		scanf("%d", &G[i]);

	rep(i, 1, N)
		if(!flag[i])
			dfs(i, 0);

	rep(i, 1, N)
		printf("%d\n", f[i]);

	return 0;
}

inline void dfs ( int i, int step )
{
	flag[i] = true;
	deep[i] = step;
	if(f[G[i]])
		f[i] = f[G[i]] + 1;
	else if(deep[G[i]]){
		f[i] = ( deep[i] - deep[G[i]] + 1 );
		int num = G[i];
		while(num != i){
			f[num] = f[i];
			num = G[num];
		}
	}
	else{
		dfs(G[i], step + 1);
		if(!f[i])
			f[i] = f[G[i]] + 1;
	}
}
