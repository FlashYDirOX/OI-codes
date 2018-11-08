#include <cstdio>
#include <queue>
#include <algorithm>

#define REP(i, a, b) for(int i = a; i <= b; i++)

using std::priority_queue;

const int MAXN = 301;
const int MAXM = 100001;
const int INF = 1e9;

struct Node {
    int num, dist;
    bool operator < (const Node &x) const
    {
        return x.dist < dist;
    }
}G[MAXN];

priority_queue<Node> Q;

int N, M, cnt, d[MAXN];
int e, start[MAXM], to[MAXM], nxt[MAXM], value[MAXM];
bool visit[MAXN];

inline void add_edge ( int u, int v, int w );

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d%d", &N, &M);

    REP(i, 1, M){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    REP(i, 1, N)
        d[i] = INF;
    d[1] = 0;
    visit[1] = true;
    Q.push((Node){1, 0});

    while(!Q.empty()){
        Node now = Q.top();
        Q.pop();
        if(now.dist ^ d[now.num])
            continue ;
        visit[now.num] = true;
        cnt = std::max(cnt, now.dist);
        for(int i = start[now.num]; i; i = nxt[i]){
            int node = to[i];
            if(d[node] > value[i] && !visit[node]){
                d[node] = value[i];
                Q.push((Node){node, value[i]});
            }
        }
    }

    printf("%d %d", N - 1, cnt);

    return 0;
}

inline void add_edge ( int u, int v, int w )
{
    ++e;
    nxt[e] = start[u];
    start[u] = e;
    to[e] = v;
    value[e] = w;
}
