#include <cstdio>
#include <stack>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::stack;

const int MAXN = 10000001;

stack<int> Q;

int N, ans;
int h[MAXN], v[MAXN], cnt[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d", &N);

	rep(i, 1, N)
		scanf("%d%d", &h[i], &v[i]);

	rep(i, 1, N){
		while(!Q.empty() && h[Q.top()] < h[i]){
			cnt[i] += v[Q.top()];
			Q.pop();
		}
		if(!Q.empty())
			cnt[Q.top()] += v[i];
		Q.push(i);
	}

	rep(i, 1, N)
		ans = std::max(ans, cnt[i]);

	printf("%d", ans);

	return 0;
}
