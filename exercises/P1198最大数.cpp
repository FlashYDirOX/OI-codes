#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define lson rt << 1, head, mid
#define rson rt << 1 | 1, mid + 1, tail
#define mid ( ( head + tail ) >> 1 )

typedef long long ll;

const int MAXN = 200001 << 2;
const int INF = 0x3f3f3f3f;

using std::max;

ll M, MOD, a[MAXN], cnt, sum[MAXN], num;
char s[10];

inline ll query ( int, int, int, int, int );

inline void insert ( int, int, int, int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%lld%lld", &M, &MOD);

	rep(i, 1, M){
		int L;
		scanf("%s%d", s, &L);
		if(s[0] == 'Q'){
			if(L == 0)
				printf("%lld\n", cnt = 0);
			else
				printf("%lld\n", cnt = query(1, 1, M, num - L + 1, num) % MOD);
		}
		if(s[0] == 'A'){
			insert(1, 1, M, num + 1, ( cnt + L ) % MOD);
			++num;
		}
	}

	return 0;
}

inline ll query ( int rt, int head, int tail, int L, int R )
{
	int u = -INF, v = -INF;
	if(head >= L && tail <= R)
		return sum[rt];
	if(L <= mid)
		u = query(lson, L, R);
	if(R > mid)
		v = query(rson, L, R);
	return std::max(u, v);
}

inline void insert ( int rt, int head, int tail, int node, int value )
{
	if(head == tail){
		sum[rt] = value;
		return ;
	}
	else {
		if(node <= mid)
			insert(lson, node, value);
		if(node > mid)
			insert(rson, node, value);
		sum[rt] = std :: max ( sum[rt << 1], sum[rt << 1 | 1] ) % MOD;
	}
}
