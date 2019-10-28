#include <cstdio>
#include <cmath>

const int MAXN = 61;

int N;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	int start = sqrt(N << 1);
	for(register int i = start; i > 1; i--){
		if((N << 1) % i == 0 && (i + ((N << 1) / i) & 1)){
			int j = ((N << 1) / i);
			printf("%d %d\n", ((j - i + 1) >> 1), (i + j - 1) >> 1);
		}
	}

	return 0;
}
