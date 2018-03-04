#include <cstdio>
#include <algorithm>

const int MAXN = 1005;

struct stu {
	int num, value;
}a[MAXN];

long long cnt;

inline bool cmp (stu a, stu b);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	int N;
	scanf("%d", &N);

	for (register int i = 1; i <= N; i++) {
		scanf("%d", &a[i].value);
		a[i].num = i;
	}

	std::sort(a + 1, a + N + 1, cmp);

	for (register int i = 1; i <= N; i++) {
		cnt += a[i].value * (N - i);
		printf("%d ", a[i].num);
	}

	printf("\n%.2f", (double)(1.0 * cnt / N));

	return 0;
}

inline bool cmp (stu a, stu b)
{
	if (a.value == b.value)
		return a.num < b.num;
	return a.value < b.value;
}
