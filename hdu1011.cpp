#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
int vis[105];
int dp[105][105];
vector<int> vec[105];
vector<int> G[105];
int c[105];
int p[105];

void dfs(int x){
	vis[x] = 1;
	int si = G[x].size();
	for(int i = 0;i < si;i++){
		int v = G[x][i];
		if(!vis[v]){
			dfs(v);
			vec[x].push_back(v);
		}
	}
}
void  fun(int u){
	for(int i  = c[u];i <= m;i++){
		dp[u][i] = p[u];
	}
	int si = vec[u].size();
	for(int i = 0;i < si;i++){
		int v = vec[u][i];
		fun(v);
		for(int j = m;j >= c[u];j --){
			for(int k = 1;j+k <= m;k++){//这里一定要从1开始因为每个结点必须有一个士兵经过 
				if(dp[v][k]){
					dp[u][j+k] = max(dp[u][j+k],dp[v][k]+dp[u][j]);//这里有个隐式的0-1背包问题，dp[i][j]为在第i个结点有jj个士兵经过得到的价值 
				}
			}
		}
	}
}
int main(){
	while(cin >> n  >> m,n!=-1 && m!=-1){
		for(int i = 1;i <=  n;i++){
			G[i].clear();
			vec[i].clear();
			scanf("%d%d",&c[i],&p[i]);
			c[i] = (c[i]+19)/20;
		}
		
		for(int i = 0;i < n-1;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if(m == 0){
			puts("0");
			continue;
		}
		memset(vis,0,sizeof(vis));
		dfs(1);
		memset(dp,0,sizeof(dp));
		fun(1);
		cout << dp[1][m] << endl;
	}
	return 0;
}
