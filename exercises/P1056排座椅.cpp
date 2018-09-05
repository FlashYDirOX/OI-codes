#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

const int MAXN = 1010;

int N, M, K, L, D;

struct stu {
  int x, y;
}ans[MAXN], flag[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d%d%d%d", &M, &N, &K, &L, &D);

	for (register int i = 1; i <= D; i++) {
		int x, y, p, q;

		scanf("%d%d%d%d", &x, &y, &p, &q);

		x == p ? ans[min(y, q)].x++ : ans[min(x, p)].y++;
	}

	for (register int i = 1; i <= K; i++) {
		int cnt = -1, num;
		
		for (register int j = 1; j < M; j++)
		  if (ans[j].y > cnt) {
			num = j;
			cnt = ans[j].y;
		  }
		  ans[num].y = 0;
		  flag[num].y++;
	}

	for (register int i = 1; i <= L; i++) {
		int cnt = -1, num;

		for (register int j = 1; j < N; j++)
		if (ans[j].x > cnt) {
			num = j;
			cnt = ans[j].x;
		}
		ans[num].x = 0;
		flag[num].x++;
	}

	for (register int i = 1; i <= N; i++)
		if (flag[i].y)
			printf("%d ", i);
	printf("\n");

	for (register int i = 1; i <= M; i++)
		if (flag[i].x)
			printf("%d ", i);

	return 0;
}
