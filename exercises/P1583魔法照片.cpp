#include <cstdio>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

using std::sort;

const int MAXN = 20001;

struct node {
	int u, num;
}w[MAXN];

inline bool cmp ( node, node );

int N, K, e[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &K);

	rep(i, 0, 9)
		scanf("%d", &e[i]);

	rep(i, 0, N - 1){
		scanf("%d", &w[i].u);
		w[i].num = i + 1;
	}

	sort(w, w + N, cmp);

	rep(i, 0, N - 1)
		w[i].u += e[i % 10];

	sort(w, w + N, cmp);

	rep(i, 0, K - 1)
		printf("%d ", w[i].num);

	return 0;
}

inline bool cmp ( node u, node v )
{
	if(u.u == v.u)
		return u.num < v.num;
	else return u.u > v.u;
}
