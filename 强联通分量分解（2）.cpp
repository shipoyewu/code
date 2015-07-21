#include <cstdio>
#include <iostream>

using namespace std;

int low[1000];
int pre[1000];
int dfs_time;
int vec[1000]
int scc_no;
int sccno[1000];

int dfs(int u){
	pre[u] = low[u] = ++dfs_time;
	s.push(u);
	int si = G[u].size();
	for(int i = 0;i < si;i++){
		int v = G[u][v];
		if(!pre[v]){
			dfs(v);
			low[u] = min(low[v],low[u]);
		}	
		else if(!scc_no[v]){
			low[u] = min(low[u],pre[v]);
		}
	}
	if(low[u] == pre[u]){ //假如他最远只能到自己那么就说明他是一个scc的入口 
		scc_no++;
		while(!s.enpty()){
			int x = s.top();
			s.pop();
			sccno[x] = scc_no; 
		}
	}
} 
int find_scc(){
	scc_no = 0;
	dfs_time = 0;
	memset(pre,0,sizeof(pre));
	memset(sccno,0,sizeof(sccno));
	for(int i = 1;i <= n;i++){
		if(!pre[i]){
			dfs(i);
		}
	}
}

 
