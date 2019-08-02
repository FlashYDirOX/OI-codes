#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

const int MAXN = 53;
const int INF = 0x3f3f3f3f;

int gree[MAXN], G[MAXN][MAXN];
char s[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	rep(i, 1, N){
		int a, b;
		scanf("%s", s);
		a = s[0] - 'A';
		b = s[1] - 'A';
		first = std::min(first, std::min(a, b));
		gree[a]++;
		gree[b]++;
	}

	rep(i, 0, MAXN)
		if(gree[i] & 1
			num1 ? num1 = i : num2 = i;

	if(num1 == 0){
		puts("No Solution");
		exit(0);
	}

	if

	return 0;
}
