#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define rep(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 1000210;

struct node {
	int l, r, ques;
	inline bool operator < ( const node& x ) const
	{
		return r < x.r;
	}
}G[MAXN];

int N, M, nxt = 1;
int f[MAXN], a[MAXN], pre[MAXN], sign[MAXN], ans[MAXN];

inline int read ();

inline int lowbit ( int );

inline void update ( int, int );

inline int query ( int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	N = read();
	rep(i, 1, N)
		a[i] = read();
		
	M = read();
	rep(i, 1, M){
		G[i].l = read();
		G[i].r = read();
		G[i].ques = i;
	}

	std::sort(G + 1, G + M + 1);

	rep(i, 1, M){
		rep(j, nxt, G[i].r){
			if(sign[a[j]])
				update(sign[a[j]], -1);
			update(j, 1);
			sign[a[j]] = j;
		}
		nxt = G[i].r + 1;
		ans[G[i].ques] = query(G[i].r) - query(G[i].l - 1);
	}

	rep(i, 1, M)
		printf("%d\n", ans[i]);

	return 0;
}

inline int read ()
{
	int x = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		x = (x << 1) + (x << 3) + c - 48;
		c = getchar();
	}
	return x;
}

inline int lowbit ( int u )
{
	return u & (-u);
}

inline void update ( int u, int v )
{
	while(u <= N){
		f[u] += v;
		u += lowbit(u);
	}
}

inline int query ( int u )
{
	int cnt = 0;
	while(u > 0){
		cnt += f[u];
		u -= lowbit(u);
	}
	return cnt;
}
