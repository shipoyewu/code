#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define INF 1000000000 

//Î´²âÊÔ¹ý 
struct edge{
	int u,v,value;
	bool operator <(const edge& a )const {
		return value > a.value; 
	} 
};
struct V{
	int x,key;
	bool operator < (const V& a)const{
		return key > a.key;
	}
};
vector<edge> vec[1000];
V p[1000];
int n,m;
int vis[1000];

int prim(){
	for(int i = 0;i < n;i++){
		p[i].x = i;
		p[i].key = INF;
	}	
	memset(vis,0,sizeof(vis));
	priority_queue<V> que;
	p[0].key  = 0;
	que.push(p[0]);
	int mst = 0;
	
	while(!que.empty()){
		V u = que.top();
		que.pop();
		if(vis[u.x]) continue;
		vis[u.x] = 1;
		
		mst += p[u.x].key;		
		for(int i = 0;i < vec[u.x].size();i ++){
			edge v = vec[u][i];
			if(!vis[u.x]&&v.value < p[v.v].key){
				p[v.v].key = v.value;
				V x;
				x.x = v.v;
				x.key = v.value;
				que.push(x);
			}
		}
	}
} 
int main(){
	while(cin >> n >> m){
		for(int i = 0;i < m;i++){
			cin >> E[i].u >> E[i].v >> E[i].value;
			vec[u].push_back(E[i]);
			
		}
		klouth();
	}	
	return 0;
} 
