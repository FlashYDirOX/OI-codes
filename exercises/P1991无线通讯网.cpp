#include<bits/stdc++.h>
using namespace std;
int n,m,top=0;
double ans=0;
int f[1000086];
struct nodedge{
    int from,to;
    double val;
}edge[1000086];
struct node{
    int x,y;
} a[10005];
int find(int x){
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}
double dis(int x,int y,int z,int w){
    return sqrt((x-z)*(x-z)+(y-w)*(y-w));
}
bool cmp(nodedge a,nodedge b){
    return a.val<b.val;
}
signed main(){
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=m;i++){
        f[i]=i;
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for(register int i=1;i<=m;i++)
        for(register int j=1;j<=m;j++){
            if(i==j)
                continue;
            edge[++top].val=dis(a[i].x,a[i].y,a[j].x,a[j].y);
            edge[top].from=i;
            edge[top].to=j;
        }
    sort(edge+1,edge+1+top,cmp);
    int k=0;
    for(register int i=1;i<=top;i++){
        if(find(edge[i].from)!=find(edge[i].to)){
            f[find(edge[i].to)]=edge[i].from;
            ans=edge[i].val;
            k++;
            if(k==m-n)
                break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}
