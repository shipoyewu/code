#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n;
vector<int> vec[100];

int vis[100];

node et[100];
int tm = 0;
/*
	基于dfs的拓扑排序，利用dfs中的完成时间戳，完成时间戳越大越放在前面 
*/
queue<int> que;
int topu_dfs(int s){
&nbsp;&nbsp; &nbsp;vec[s] = 1;
&nbsp;&nbsp; &nbsp;int si = vec[s].size(); 
&nbsp;&nbsp; &nbsp;for(int i = 0;i < si;i++){
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;int v = vec[s][i];
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if(vec[v] == 1){
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;return false;
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if(vec[v] == 0){
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;dfs(v);
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}
&nbsp;&nbsp; &nbsp;}
&nbsp;&nbsp; &nbsp;vec[s] = 2;
&nbsp;&nbsp; &nbsp;que.push(s);
&nbsp;&nbsp; &nbsp;return true;
}
int topu(){
&nbsp;&nbsp; &nbsp;memset(vis,0,sizeof(vis));
&nbsp;&nbsp; &nbsp;for(int i = 0;i < n;i++){
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if(!vis[i]){
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if(!dfs(i)){
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;return false;
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}
&nbsp;&nbsp; &nbsp;}
&nbsp;&nbsp; &nbsp;return true;
}

/*
	基于入度的拓扑排序 
*/ 
int d[100];
int topu_rudu(){
	stack<int> st;
	
	for(int i = 0;i < n;i++){
		d[i] = vec[i].size();
		if(d[i] == 0){
			st.push(i);
		}
	}
	queue<int> que;
	
	while(!st.empty()){
		int u = st.top();
		st.pop();
		que.push(u);	
		int si = vec[u].size();
		for(int i = 0;i < si;i++){
			int v = vec[u][i];
			d[v]--;
			if(d[v] == 0){
				st.push(v);
			}
		}
	}
	if(que.size()!=n){
		printf("no order!!!\n");
	}
	else{
		while(!que.empty()){
			printf("%d ",que.front());
			que.pop();
		}
	}
} 
int main(){
	while(cin >> n){
		int m;
		cin >> m;
		for(int i = 0;i < m;i++){
			int x,y;
			
			cin >> x >> y;
			vec[x].push_back(y);	
		}
		topu_rudu();
		topu_DFS();
		
	}
} 
