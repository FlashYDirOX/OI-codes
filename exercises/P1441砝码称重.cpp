#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define frep(i, a, b) for(register int i = a; i >= b; i--)

using std::max;

const int MAXN = 21;
const int MAXM = 2010;

int N, M, ans, cnt;
int a[MAXN], sign[MAXN], f[MAXM];

inline void dfs ( int, int );

inline void dp ();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, N)
		scanf("%d", &a[i]);

	dfs(1, 0);

	printf("%d", ans);

	return 0;
}

inline void dfs ( int step, int num )
{
	if(step == N + 1){
		if(num == M)
			dp();
		return ;
	}
	sign[step] = 1;
	dfs(step + 1, num + 1);
	sign[step] = 0;
	dfs(step + 1, num);
}

inline void dp ()
{
	int tot = 0, cnt = 0;
	memset(f, 0, sizeof(f));
	f[0] = 1;
	rep(i, 1, N){
		if(sign[i])
			continue ;
		frep(j, tot, 0)
			if(f[j] && !f[j + a[i]]){
				f[j + a[i]] = 1;
				cnt++;
			}
		tot += a[i];
	}
	ans = max(ans, cnt);
}
