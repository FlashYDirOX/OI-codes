#include <cstdio>
#include <cctype>
#include <cmath>
#include <iostream>

#define REP(i, a, b) for(register int i = a; i <= b; i++)

using std::cin;

const int MAXN = 30001;

int T;
int father[MAXN], head[MAXN], value[MAXN];

inline int find ( int x );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	char c;

	scanf("%d", &T);

	REP(i, 1, 30001){
		father[i] = i;
		head[i] = 0;
		value[i] = 1;
	}

	while(T--){
		int x, y, fx, fy;

		cin >> c;

		scanf("%d%d", &x, &y);
		fx = find(x);
		fy = find(y);
		if(c == 'M'){
			head[fx] += value[fy];
			value[fy] += value[fx];
			value[fx] = 0;
			father[fx] = fy;
		}
		if(c == 'C')
			fx != fy ? puts("-1") : printf("%d\n", abs(head[x] - head[y]) - 1);
	}

	return 0;
}

inline int find ( int x )
{
	int tmp;
	if(father[x] == x)
		return father[x];
	tmp = find(father[x]);
	head[x] += head[father[x]];
	return father[x] = tmp;
}
