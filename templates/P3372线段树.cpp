#include <cstdio>

#define REP(i, a, b) for(register int i = a; i <= b; i++) 
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right
#define len (right - left + 1)

typedef long long ll;

const int MAXN = 100001;
const int INF = 1e9;

int N, M;
ll sum[MAXN << 2], lazy[MAXN << 2], ans;

inline void pushdown ( int rt, int left, int right, int calc );

inline void build ( int rt, int left, int right );

inline void update ( int rt, int left, int right, int L, int R, int calc );

inline void query ( int rt, int left, int right, int L, int R );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
 
	scanf("%d%d", &N, &M);

	build(1, 1, N);

	REP(i, 1, M){
		int task, x, y, k;
		scanf("%d", &task);
		if(task == 1){
			scanf("%d%d%d", &x, &y, &k);
			update(1, 1, N, x, y, k);
		}
		if(task == 2){
			ans = 0;
			scanf("%d%d", &x, &y);
			query(1, 1, N, x, y);
			printf("%lld\n", ans);
		}
	}

	return 0;
}

inline void build ( int rt, int left, int right )
{
	if(left == right)
		scanf("%lld", &sum[rt]);
	else{
		build(lson);
		build(rson);
		sum[rt] += sum[rt << 1] + sum[rt << 1 | 1];
	}
}

inline void pushdown ( int rt, int left, int right, int calc )
{
	sum[rt] += len * calc;
	lazy[rt] += calc;
}

inline void update ( int rt, int left, int right, int L, int R, int calc )
{
	if(L <= left && R >= right){
		sum[rt] += len * calc;
		lazy[rt] += calc;
	}
	else{
		if(lazy[rt]){
			pushdown(lson, lazy[rt]);
			pushdown(rson, lazy[rt]);
			lazy[rt] = 0;
		}
		if(L <= mid)
			update(lson, L, R, calc);
		if(R > mid)
			update(rson, L, R, calc);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}

inline void query ( int rt, int left, int right, int L, int R )
{
	if(L <= left && R >= right)
		ans += sum[rt];
	else{
		if(lazy[rt]){
			pushdown(rt << 1, left, mid, lazy[rt]);
			pushdown(rt << 1 | 1, mid + 1, right, lazy[rt]);
			lazy[rt] = 0;
		}
		if(L <= mid)
			query(lson, L, R);
		if(R > mid)
			query(rson, L, R);
	}
}
