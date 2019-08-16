#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define frep(i, a, b) for(register int i = a; i >= b; i--)

const int MAXN = 100001;

int N, ans[MAXN];
char s[MAXN];

int main()
{
	int len;

	scanf("%d", &N);

	scanf("%s", s);

	len = strlen(s);

	rep(i, 0, len - 1){
		if(s[i] == 'L')
			rep(j, 0, 9)
				if(!ans[j]){
					ans[j] = 1;
					break;
				}
		if(s[i] == 'R')
			frep(j, 9, 0)
				if(!ans[j]){
					ans[j] = 1;
					break;
				}
		if(isdigit(s[i]))
			ans[s[i] - '0'] = 0;
	}

	rep(i, 0, 9)
		printf("%d", ans[i]);

	return 0;
}
