#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;
#define INF 0x2fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
#define MAXM 10000
#define MAXN 1000
struct edge{
	int form,to,cap,flow,next;
}; 
edge ed[MAXM];
int head[MAXN];

int cnt;
void add(int form,int to,int cap){
	ed[cnt].form = from;
	ed[cnt].to  = to;
	ed[cnt].next = head[from].next;
	head[from].next = cnt++;
	ed[cnt].from = to;
	ed[cnt].to = from;
	ad[cnt].next = head[to].next;
	head[to].next = cnt++;
}
struct dinic{
	int n,m,s,t;
	bool vis[MAXN];
	int d[MAXN];
	int cur[MAXN];
	int bfs(){
		memset(vis,0,sizeof(vis));
		queue<int> que;
		que.push(s);
		d[s] = 0;
		vis[s] = 1;
		while(!que.empty()){
			int u = que.front();
			que.pop();
			for(int v = head[u];v != 0 ;v = ed[v].next){
				if(!vis[ed[v].to] && ed[v].cap > ed[v].flow){
					vis[ed[v].to] = 1;
					d[ed[v].to] = d[x]+1;
					que.push(e.to);
				} 
			}
		}
		return vis[t];
	}
	int dfs(int x,int a){
		if(x == t || a == 0) return a;
		itn flow = 0,f;
		for(int v = head[cur[x]];v != 0;v = ed[v].next){
			edge& e = ed[v];
			if(d[e.from] + 1== d[e.to] && (f = dfs(e.to,min(a,e.cap-e.flow))) > 0){
				e.flow += f;
				ed[v^1].flow -= f;
				flow += f;
				a -= f;
				if(a == 0){
					break;
				}
			}
		}
		return flow;
	}
	int max_flow(int s,int t){
		this->s = s;
		this->t = t;
		int flow = 0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow += dfs(s,INF);
		}
	}		
};

int main(){

	return 0;
}

