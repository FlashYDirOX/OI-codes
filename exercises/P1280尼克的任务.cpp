#include <cstdio>

#define REP(i, a, b) for(register int i = a; i <= b; i++)
#define FREP(i, a, b) for(register int i = a; i >= b; i--)

const int MAXN = 10001;

int N, K;
int start[MAXN], end[MAXN]. misson[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	scanf("%d%d", &N, &K);

	REP(i, 1, K){
		scanf("%d%d", &start[i], &end[i]);
		misson[start[i]] = ;
	}

	FREP(i, N, 1){
		if(misson[i])
			f[i] = f[i + 1] + 1;
		else
			REP(j, 1, 
	}

	return 0;
}
