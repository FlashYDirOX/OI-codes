#include <cstdio>

#define REP(i, a, b) for(register int i = a; i <= b; i++)
#define mid (left + right >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right
#define len (right - left + 1)

typedef long long ll;

const int MAXN = 1000001;
const int INF = 1e9;

int N, M;

inline void build ( int rt, int left, int right );

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
		if(task == 1)
	}

	return 0;
}

inline void build ( int rt, int left, int right )
{
	if(left == right)
		scanf("%d", &sum[rt]);
	else{
		build(lson);
		build(rson);
		sum[rt] += sum[rt << 1] + sum[rt << 1 | 1];
	}
}
