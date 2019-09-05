#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::max;

const int MAXN = 100001;
int a[MAXN], f[MAXN][2], N, max0, max1;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	rep(i, 1, N)
		scanf("%d", &a[i]);

	f[1][1] = f[1][0] = 1;

	rep(i, 2, N){
		if(a[i - 1] < a[i]){
			f[i][0] = f[i - 1][1] + 1;
			f[i][1] = f[i - 1][1];
		}
		if(a[i - 1] > a[i]){
			f[i][1] = f[i - 1][0] + 1;
			f[i][0] = f[i - 1][0];
		}
		if(a[i - 1] == a[i]){
			f[i][1] = f[i - 1][1];
			f[i][0] = f[i - 1][0];
		}
	}

	printf("%d", max(f[N][0], f[N][1]));

	return 0;
}
