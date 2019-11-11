#include<bits/stdc++.h>
using namespace std;
map<string,int>vis;//map大法用来标记 
int ans,n;
string s[2001];//存放给定词汇列表，方便还原现场 
string t;//存放一句话中的单词 
string sb;//用来存放文章 
int main(){
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
    cin>>n;//读入 
    for(int j=1;j<=n;j++){
        string now;
        cin>>now;
        for(int i=0;i<now.size();i++){
            if(now[i]>='A'&&now[i]<='Z') now[i]+=32;
        }
        vis[now]=1;//标记为1 
        s[j]=now;//记录 
    }
    string dd;
    getline(cin,dd);//!!!因为getline会读入回车，所以我们先把回车读掉，注意！！一定要用geiline读入回车，千万不能用char读，被坑惨了 
    getline(cin,sb);
    for(int i=0;i<sb.size();i++)
        if(sb[i]>='A'&&sb[i]<='Z') sb[i]=sb[i]+32;//全文转换为小写 
    t="";
    for(int i=0;i<sb.size();i++){
        if(sb[i]=='.'){//判断为句号 
            if(vis[t]==1){//如果没被访问过，答案++ 
                ans++;
                vis[t]=0;
            }
            t="";
            for(int j=1;j<=n;j++)//句子结束了，还原现场 
               vis[s[j]]=1;
        }
        else if(sb[i]==' '||sb[i]==',') {//否则只能是一个单词，不要还原现场 
            if(vis[t]==1){
                vis[t]=0;
                ans++;
            }
            t="";
        }
        else t+=sb[i];//存放单词 
    }
    cout<<ans<<endl;//祝你表白早日成功++ 
    return 0;
}
