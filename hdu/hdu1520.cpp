#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n,fa[10000],dp[10000][2],flg[10000];
bool p[10000];
void dfs(int f){
	p[f]=1;
	for(int i=1;i<=n;i++){
//			cout<<"sdf";
		if(fa[i]==f&&!p[i]){
			dfs(i);
			dp[f][1]+=dp[i][0];
			dp[f][0]+=max(dp[i][0],dp[i][1]);
		}
	}
}
int main(){
	int i,j,k,m;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<10000;i++){
			dp[i][1]=0;
			dp[i][0]=0;
			flg[i]=0;
			fa[i]=0;
			p[i]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&dp[i][1]);
			fa[i]=i;
		}
		
		while(1){
			int k,l;
			scanf("%d%d",&l,&k);
			if(l==0&&k==0)break;
			fa[l]=k;
			flg[l]++;
		}
		for(i=1;i<=n;i++){
			if(!flg[i]){
				dfs(i);
				cout<<max(dp[i][0],dp[i][1])<<endl;
				break;
			}
		}
	}
	
	return 0;
}
