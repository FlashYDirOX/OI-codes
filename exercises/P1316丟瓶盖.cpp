#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100001;

inline bool compare ( int, int );

inline bool check ( int );

int N, M, f, l;
int a[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, N)
		scanf("%d", &a[i]);

	std::sort(a + 1, a + N + 1, compare);

	rep(i, 2, N)
		f = std::min(f, a[i] - a[i - 1]);
	l = a[N] - a[1];

	while(f <= l){
		int mid = f + ((l - f) >> 1);
		if(check(mid))
			f = mid + 1;
		else l = mid - 1;
	}

	printf("%d", l);

	return 0;
}

inline bool compare ( int u, int v )
{
	return u < v;
}

inline bool check ( int v )
{
	int cnt = 1, count = a[1];
	rep(i, 1, N){
		if(a[i] - count >= v){
			count = a[i];
			cnt++;
		}
	}
	return cnt >= M;
}
