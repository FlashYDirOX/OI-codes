#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 10010;
const int MAXM = 100010;

int N, M, cnt1, cnt2;
int start[MAXM], to[MAXM], nxt[MAXM], e;
bool color[MAXN], flag[MAXN];

inline void dfs ( int );

inline void add_edge ( int, int );

int main(){
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	rep(i, 1, M){
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}

	color[1] = 1;
	flag[1] = true;
	cnt1++;

	dfs(1);

	printf("%d", std::min(cnt1, cnt2));

	return 0;
}

inline void dfs ( int x )
{
	for(register int i = start[x]; i; i = nxt[i])
		if(flag[to[i]] && ( color[i] ^ color[to[i]] )){
			puts("Impossible");
			exit(0);
		}
		else if(!flag[to[i]]) {
			color[to[i]] = 1 - color[i];
			color[to[i]] == 1 ? cnt1++ : cnt2++;
			flag[to[i]] = true;
			dfs(to[i]);
		}
}

inline void add_edge ( int u, int v )
{
	nxt[++e] = start[u];
	start[u] = e;
	to[e] = v;
}
