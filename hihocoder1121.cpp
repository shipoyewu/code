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
struct node{
	int from,to,next;

};
node es[80010];
int head[10005];
int cnt = 1;
int vis[10005];

int add(int from,int to){
	es[cnt].from = from ;
	es[cnt].to = to;
	es[cnt].next = head[from];
	head[from] = cnt++;
}
bool bfs(int x){
	queue<int> que;
	que.push(x);
	vis[x] = 1;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int t = head[u];t != 0;t = es[t].next){
			node& a = es[t];
			if(!vis[a.to]){
				vis[a.to] = 3 - vis[a.from];
				que.push(a.to); 
			}
			else{
				if(vis[a.to]==vis[a.from]){
					return false;
				}
			}
		}
	}
	return true;
}
int main(){
    int t;
	cin >> t;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(head,0,sizeof(head));
		cnt = 1;
		for(int i = 0;i < m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);			
		}
		memset(vis,0,sizeof(vis));
		int flag = 1;
		for(int i = 1;i <= n;i++){
			if(!vis[i]){
				if(!bfs(i)){
					flag = 0;
					break;
				}
			}
		}
		if(flag){
			printf("Correct\n");
		}
		else{
			printf("Wrong\n");
		}
	} 
    return 0;
}

