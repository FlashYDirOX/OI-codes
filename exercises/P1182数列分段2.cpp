#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100091;

int N, M, f, l, sum, mid;
int a[MAXN];

inline bool pd ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, N){
		scanf("%d", &a[i]);
		sum += a[i];
		f = std::max(f, a[i]);
	}
	
	l = sum;

	while(f <= l){
		mid = f + ((l - f) >> 1);
		if(pd(mid))
			f = mid + 1; 
		else l = mid - 1;
	}

	printf("%d", f);

	return 0;
}

inline bool pd ( int v )
{
	int cnt = 0, count = 0;
	rep(i, 1, N){
		if(count + a[i] <= v)
			count += a[i];
		else {
			count = a[i];
			cnt++;
		}
	}
	return cnt >= M;
}
