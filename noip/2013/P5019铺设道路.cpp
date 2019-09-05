#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100001;

int N, cnt, num;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	scanf("%d", &cnt);

	num = cnt;

	rep(i, 2, N){
		int a;
		scanf("%d", &a);
		if(a > num)
			cnt += a - num;
		num = a;
	}

	printf("%d", cnt);

	return 0;
}
