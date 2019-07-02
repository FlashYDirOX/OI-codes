#include <cstdio>

typedef unsigned long long ll;

ll b, p, k;

inline ll calc ( ll a, ll b, ll mod );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%lld%lld%lld", &b, &p, &k);

	if(p == 0)
		printf("%lld^%lld mod %lld=%lld", b, p, k, 1 % k);

	printf("%lld^%lld mod %lld=%lld", b, p, k, calc(b, p, k));

	return 0;
}

inline ll calc ( ll a, ll b, ll mod )
{
	ll cnt = 1;
	a %= mod;
	while(b){
		if(b & 1)
			cnt = (cnt * a) % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return cnt;
}
