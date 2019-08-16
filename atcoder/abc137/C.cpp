#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
char s[20];
int n,ans,p[maxn];
signed main()
{
	scanf("%lld",&n);
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		sort(s+1,s+len+1);
		for(register int j=1;j<=len;j++)
			p[i]=(p[i]*13331+s[j]-96);
	}
	sort(p+1,p+n+1);
	int pre=-1,cnt=0;
	for(register int i=1;i<=n;i++)
		if(p[i]==pre)
			cnt++;
		else
		{
			ans+=cnt*(cnt-1)/2;
			cnt=1;
			pre=p[i];
		}
	ans+=cnt*(cnt-1)/2;
	printf("%lld",ans);
	return 0;
}
