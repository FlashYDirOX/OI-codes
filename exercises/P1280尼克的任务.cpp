#include <cstdio>
#include <algorithm>

#define REP(i, a, b) for(register int i = a; i <= b; i++)
#define FREP(i, a, b) for(register int i = a; i >= b; i--)

const int MAXN = 10001;

struct node {
	int head, tail;
}G[MAXN];

int N, K, cnt = 1;
int misson[MAXN], f[MAXN];

inline bool cmp ( node x, node y );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &K);

	REP(i, 1, K){
		scanf("%d%d", &G[i].head, &G[i].tail);
		misson[G[i].head]++;
	}

	std::sort(G + 1, G + K + 1, cmp);

	FREP(i, N, 1){
		if(!misson[i])
			f[i] = f[i + 1] + 1;
		else
			REP(j, 1, misson[i]){
				f[i] = std::max(f[i], f[i + G[cnt].tail]);
				cnt++;
			}
	}

	printf("%d", f[1]);

	return 0;
}

inline bool cmp ( node x, node y )
{
	return x.head > y.head;
}
