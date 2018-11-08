#include <cstdio>

#define REP(i, a, b) for(register int i = a; i <= b; i++)

const int MAXN = 100001;

int ans, N, K;
int father[MAXN * 3];

inline int find ( int x );

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d%d", &N, &K);

    REP(i, 1, 3 * N)
        father[i] = i;

    REP(i, 1, K){
        int task, x, y;
        scanf("%d%d%d", &task, &x, &y);
        if(x > N || y > N){
            ans++;
            continue ;
        }
        if(task == 1){
            if(find(x + N) == find(y) || find(x) == find(y + N))
                ans++;
            else{
                father[find(x)] = find(y);
                father[find(x + N)] = find(y + N);
                father[find(x + 2 * N)] = find(y + 2 * N);
            }
        }
        else
            if(find(x) == find(y) || find(x) == find(y + N))
                ans++;
            else{
                father[find(x + N)] = find(y);
                father[find(x + 2 * N)] = find(y + N);
                father[find(x)] = find(y + 2 * N);
            }
    }

    printf("%d", ans);

    return 0;
}

inline int find ( int x )
{
    return father[x] == x ? x : father[x] = find(father[x]);
}
