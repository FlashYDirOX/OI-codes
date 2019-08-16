#include <cstdio>
#include <cstring>
#include <cstdlib>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100001;

char s1[MAXN], s2[MAXN];

inline void dfs ( int, int, int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	int len;

	scanf("%s%s", s1, s2);

	len = strlen(s1) - 1;

	dfs(0, len, 0, len);

	return 0;
}

inline void dfs ( int L1, int R1, int L2, int R2 )
{
	int p, cnt;
	if(L1 > R1)
		return ;
	char root = s2[R2];
	putchar(root);
	for(p = L1; s1[p] != root; p++);
	cnt = p - L1;
	dfs(L1, p - 1, L2,  L2 + cnt - 1);
	dfs(p + 1, R1, L2 + cnt, R2 - 1);
}
