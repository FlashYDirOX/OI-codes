#include<cstdio>
#include<cstring>
int a[106],c[10006],du[101],n,x,y,
    k=0xfffffff,tot;
bool b[106][106];
char s[2];
int min(int u,int v) {
    return u<v ? u:v;
}
void dfs(int u) {
    for(int i=0; i<58; i++) {
        if(b[u][i]) {
            b[u][i]=b[i][u]=0;
            dfs(i);
        }
    }
    c[++tot]=u;
}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%s",&s);
        x=s[0]-'A';
        y=s[1]-'A';
        k=min(k,min(x,y));
        b[x][y]=b[y][x]=1;
        du[x]++;
        du[y]++;
    }
    for(int i=0; i<58; i++)
        if(du[i]%2==1)
            a[++a[0]]=i;
    if(a[0]==0) dfs(k);
    else if(a[0]==2) dfs(a[1]);
    else    {
        printf("No Solution\n");
        return 0;
    }
    for(int i=tot; i>=1; i--)
        printf("%c",c[i]+'A');
    return 0;
}
