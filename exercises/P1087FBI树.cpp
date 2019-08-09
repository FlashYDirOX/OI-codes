#include <cstdio>
#include <cstring>
#include <cstdlib>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 11;

int N, cnt;
char s[2 << MAXN], ans[2 << MAXN];

inline void dfs ( int, int );

inline char pd ( int, int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	int len, bit = 0;

	scanf("%d", &N);

	scanf("%s", s);
	
	len = strlen(s);

	while(len != 1){
		len >>= 1;
		bit++;
	}

	dfs(0, bit);

	rep(i, 1, ( 1 << (bit + 1)) - 1) putchar(ans[i]); 

	return 0;
}
inline void dfs ( int start, int step )
{
	if(step < 0)
		return ;
	dfs(start, step - 1);
	dfs(start + (1 << (step - 1)), step - 1);
	ans[++cnt] = pd(start, step);
}

inline char pd ( int start, int step )
{
	int num = start + ( 1 << step );
	bool flag0 = 0, flag1 = 0;
	rep(i, start, num - 1){
		if(s[i] == '0')
			flag0 = true;
		if(s[i] == '1')
			flag1 = true;
	}
	if(flag0 && flag1)
		return 'F';
	if(flag0)
		return 'B';
	if(flag1)
		return 'I';
}
