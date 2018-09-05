#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int MAXN = 70;

int num, maxlang, a[MAXN], sum, N;
bool used[MAXN];

inline bool compare(const int& a, const int& b);

inline void dfs(int ans, int cnt, int goal, int now);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	for (register int i = 1; i <= N; i++) {
		int lang;
		scanf("%d", &lang);
		if (lang <= 50) {
			a[++num] = lang;
			sum += lang;
			maxlang = std::max(maxlang, lang);
		}
	}

	std::sort(a + 1, a + num + 1, compare);

	for (register int i = maxlang; i <= (sum >> 1); i++)
		if (sum % i == 0)
			dfs(0, 0, i, 1);

	printf("%d\n", sum);

	return 0;
}

inline bool compare(const int& a, const int& b)
{
	return a > b;
}

inline void dfs(int now, int cnt, int goal, int step)
{
	if (cnt * goal == sum) {
		printf("%d\n", goal);
		exit(0);
	}
	if (a[cnt] > (sum - now))
		return ;
	if (now == goal) {
		dfs(0, cnt + 1, goal, 1);
		return ;
	}
	for (register int i = step; i <= num; i++) {
		if (!used[i] && now + a[i] <= goal) {
			used[i] = true;
			dfs(now + a[i], cnt, goal, i + 1);
			used[i] = false;
			if (now + a[i] == goal || now == 0)
				break ;
			while (a[i] == a[i + 1])
				i++;
		}
	}
}
