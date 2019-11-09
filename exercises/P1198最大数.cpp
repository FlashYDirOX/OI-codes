#include <cstdio>

#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define lson ( rt << 1, head, mid)
#define rson ( rt << 1 | 1, mid + 1, tail)
#define mid ( ( head + tail ) >> 1 )

typedef long long ll;

const int MAXN = 200001;

ll N, MOD, a[MAXN], cnt, sum[MAXN];
char s[10];

inline ll query ( int, int, int, int, int );

inline void insert ( int, int, int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &M, &MOD);

	rep(i, 1, M){
		int L;
		scanf("%s%d", s, &L);
		if(s[0] == 'Q')
			printf("%d\n", cnt = query(1, 1, N, N - L + 1, N));
		if(s[0] == 'A')
			insert(1, 1, N, L);
	}

	return 0;
}

inline ll query ( int rt, int head, int tail, int L, int R )
{
	int count;
	if(head >= tail){
		count += sum[rt];
	}
}

inline void insert ( int rt, int head, int tail, int node )
{
	if(head == tail && tail == node){
		scanf("%d", &a[++cnt]);
	}
	else {
		insert(lson, node);
		insert(rson, node);
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
}
