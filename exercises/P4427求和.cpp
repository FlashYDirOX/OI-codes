#include <bits/stdc++.h>
#define int long long 
#define re register
using namespace std;
const int maxn=300500,mod=998244353;
struct nood {
    int nex,to;
} e[maxn<<2];
int head[maxn],fa[maxn][25],dep[maxn];
int n,m,cnt,res,ans,vis[maxn],pre[maxn][55];
inline int ksm(int a,int b) {
    int ret=1;
    while(b) {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret%mod;
}//快速幂
inline void add_edge(int u,int v) {
    e[++cnt].nex=head[u];
    head[u]=cnt;
    e[cnt].to=v;
}
inline void dfs(int u,int f) {
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for ( re int i=1;i<=50;i++ ) 
        pre[u][i]=(pre[f][i]+ksm(dep[u],i)+mod)%mod;
    //因为k最多只有50，所以直接暴力预处理每一个pre数组
    for ( re int i=head[u];i;i=e[i].nex ) {
        int v=e[i].to;
        if(v==f) continue;
        dfs(v,u);
    }
}
inline int Lca(int x,int y) {
    if(dep[x]>dep[y]) swap(x,y);
    for ( re int i=20;i>=0;i-- ) 
        if(dep[x]<=dep[y]-(1<<i)) y=fa[y][i];
    if(x==y) return x;
    for ( re int i=20;i>=0;i-- ) 
        if(fa[x][i]!=fa[y][i]) 
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}//纯种lca模板
inline int read() {
    int sum=0,ff=1; char ch=getchar();
    while(ch<'0' or ch>'9') { if(ch=='-') ff=-1; ch=getchar(); }
    while(ch>='0' and ch<='9') { sum=(sum*10+ch-'0'); ch=getchar(); }
    return sum*ff;
}
signed main() {
//  freopen("BJOI2018.in","r",stdin);
//  freopen("BJOI2018.out","w",stdout);
    n=read();
    for ( re int i=1;i<=n-1;i++ ) {
        int u=read(),v=read();
        add_edge(u,v);
        add_edge(v,u);
    }

    dep[1]=-1; dfs(1,1);//电风扇预处理deep数组
    for ( re int j=1;j<=21;j++ ) 
        for ( re int i=1;i<=n;i++ ) 
            fa[i][j]=fa[fa[i][j-1]][j-1];
    //倍增预处理fa数组
    int q=read();
    while(q--) {
        int x=read(),y=read(),z=read();
        int lca=Lca(x,y);
        int sum1=(pre[x][z]+pre[y][z]+mod)%mod;
        int sum2=(pre[lca][z]+pre[fa[lca][0]][z]+mod)%mod;
        //套用公式
        printf("%lld\n",((sum1-sum2)+mod)%mod);
    }
    return 0;
}
