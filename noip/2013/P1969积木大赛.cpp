#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	
	int N, now = 0, ans = 0;

	scanf("%d", &N);

	rep(i, 1, N){
		int a;
		scanf("%d", &a);
		if(a > now)
			ans += a - now;
		now = a;
	}

	printf("%d", ans);

	return 0;
}
