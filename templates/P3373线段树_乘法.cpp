#include <cstdio>
#define Mid ((left + right) >> 1)
#define lson rt << 1, left, Mid
#define rson rt << 1 | 1, Mid + 1, right
#define LEN (right - left + 1)

const int MAXN = 100000 + 10;
typedef long long LL;

int N, M, P;
LL sum[MAXN << 2], Lazy_plus[MAXN << 2], Lazy_mult[MAXN << 2];

inline void build (int rt, int left, int right);

inline void Pushdown (int rt, int left, int right);

inline void update_plus (int rt, int left, int right, int L, int R, int cnt);

inline void update_mult (int rt, int left, int right, int L, int R, int cnt);

inline LL query (int rt, int left, int right, int L, int R);

int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
#endif

	scanf ("%d%d%d", &N, &M, &P);

	build (1, 1, N);

	for (register int i = 1; i <= M; i++) {
		int task, x, y, k;
		scanf ("%d", &task);
		if (task == 1) {
			scanf ("%d%d%d", &x, &y, &k);
			update_mult (1, 1, N, x, y, k);
		}
		if (task == 2) {
			scanf ("%d%d%d", &x, &y, &k);
			update_plus (1, 1, N, x, y, k);
		}
		if (task == 3) {
			scanf ("%d%d", &x, &y);
			printf ("%d\n", query (1, 1, N, x, y) % P);
		}
	}

	return 0;
}

inline void build (int rt, int left, int right)
{
	Lazy_mult[rt] = 1;
	if (left == right)
		scanf ("%d", &sum[rt]);
	else {
		build (lson);
		build (rson);
		sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % P;
	}
}

inline void Pushdown (int rt, int left, int right)
{
	Lazy_mult[rt << 1] = (Lazy_mult[rt << 1] * Lazy_mult[rt]) % P;
	Lazy_mult[rt << 1 | 1] = (Lazy_mult[rt << 1 | 1] * Lazy_mult[rt]) % P;
	Lazy_plus[rt << 1] = (Lazy_plus[rt << 1] * Lazy_mult[rt] + Lazy_plus[rt]) % P;
	Lazy_plus[rt << 1 | 1] = (Lazy_plus[rt << 1 | 1] * Lazy_mult[rt] + Lazy_plus[rt]) % P;
	sum[rt << 1] = (Lazy_plus[rt] * (Mid - left + 1) + sum[rt << 1] * Lazy_mult[rt] ) % P;
	sum[rt << 1 | 1] = (Lazy_plus[rt] * (right - Mid) + sum[rt << 1 | 1] * Lazy_mult[rt] ) % P;
	Lazy_plus[rt] = 0;
	Lazy_mult[rt] = 1;
}

inline void update_plus (int rt, int left, int right, int L, int R, int cnt)
{
	if (L <= left && right <= R) {
		sum[rt] = (sum[rt] + LEN * cnt) % P;
		Lazy_plus[rt] += cnt;
	}
	else {
		if (Lazy_plus[rt] || Lazy_mult[rt] != 1)
			Pushdown (rt, left, right);
		if (L <= Mid)
			update_plus (lson, L, R, cnt);
		if (R > Mid)
			update_plus (rson, L, R, cnt);
		sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % P;
	}
}

inline void update_mult (int rt, int left, int right, int L, int R, int cnt)
{
	if (L <= left && right <= R) {
		sum[rt] = (sum[rt] * cnt) % P;
		Lazy_plus[rt] = (Lazy_plus[rt] * cnt) % P;
		Lazy_mult[rt] = (Lazy_mult[rt] * cnt) % P;//Notice!!All of the three value should be mult!!
	}
	else {
		if (Lazy_plus[rt] || Lazy_mult[rt] != 1)
			Pushdown (rt, left, right);
		if (L <= Mid)
			update_mult (lson, L, R, cnt);
		if (R > Mid)
			update_mult (rson, L, R, cnt);
		sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % P;
	}
}

inline LL query (int rt, int left, int right, int L, int R)
{
	if (L <= left && right <= R)
		return sum[rt] % P;
	else {
		if (Lazy_plus[rt] || Lazy_mult[rt] != 1)
			Pushdown (rt, left, right);
		LL tmp = 0;
		if (L <= Mid)
			tmp += query (lson, L, R) % P;
		if (R > Mid)
			tmp += query (rson, L, R) % P;
		sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % P;
		return tmp % P;
	}
}
