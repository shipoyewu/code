#include <cstdio>

using namespace std;
int n,m;

int spfa_bfs(){
	int d[100] = {0};
	int c[100] = {0};
	int vis[100] = {0};
	for(int i = 0;i < n;i++){
		d[i] = INF;
	}
	d[s] = 0;
	queue<int> que;
	que.push(s);
	c[s] = 1;
	vis[s] = 1;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		vis[s] = 0;
		int si = vec[u].size();
		for(int i = 0;i < si;i++){
			int v = vec[u][i];
			if(d[v] > d[u]+w[u][i]){
				d[v] = d[u]+w[u][i];
				
				
				if(!vis[v]){
					que.push(v);
					vis[v] = 1;
					c[v] ++;
					if(c[v] > n){
						return 0;
					}
				}
			}
		}
	}
	return 1;
}
int spfa_dfs(int x){
	vis[x] = 1;
	int si = vec[x].size();
	
	for(int i = 0;i < si;i++){
		int v = vec[x][i];
		if(d[v] > d[x] + w[x][i]){
			d[v] = d[x] + w[x][i];
			if(!vis[v]){
				if(spfa_dfs(v)){
					return 1;
				}
			}
			else{
				return 1;
			}
		}
	}
	vis[x] = 0;
	return 0; 
}
int main(){
} 
