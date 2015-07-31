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
int G[20][20];
int d[20];
int n,m;
int bfs(){
	queue<int> que;
	que.push(1);
	memset(d,0,sizeof(d));
	d[1] = 1;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i = 1;i <= n;i++){
			if(G[u][i] > 0 && !d[i]){
				d[i] = d[u] +1;
				que.push(i);
			}
		}
	}
	return d[n];
}
int dfs(int x,int fw){
	if(x == n || fw == 0){
		return fw;
	}
	int a = 0;
	for(int i = 1;i <= n;i++){
		if(G[x][i] > 0 && d[i] == d[x] + 1){
			int flow =  dfs(i,min(fw,G[x][i]));
			if(flow){
				G[x][i] -= flow;
				G[i][x] += flow;
				fw -= flow;
				a += flow;
				if(fw == 0) break;
			}
		}
	}
	return a;
}
int main(){
	int t;
	int cc = 1;
	cin >> t;
	while(t--){
		cin >> n >> m;
		memset(G,0,sizeof(G));
		for(int i = 0;i < m;i++){
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			G[x][y] += w;
		}
		int ans = 0;
		
		while(bfs()) ans += dfs(1,INF);
		printf("Case %d: %d\n",cc++,ans);
	}    
    return 0;
}
/*
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
int n,m;
struct node{
    int u,v,cap,next;
}es[2009];
int cnt ;
int d[20];
int head[20];
void add(int u,int v,int cap){
    es[cnt].u = u;
    es[cnt].v = v;
    es[cnt].cap = cap;
    es[cnt].next = head[u];
    head[u] = cnt++;
    es[cnt].u = v;
    es[cnt].v = u;
    es[cnt].cap = 0;
    es[cnt].next = head[v];
    head[v] = cnt++;
}
int bfs(){
    queue<int> que;
    memset(d,-1,sizeof(d));
    que.push(1);
    d[1] = 1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int t = head[u];t != -1;t = es[t].next){
            if(d[es[t].v] == -1 && es[t].cap > 0){
                d[es[t].v] = d[es[t].u] + 1;
                que.push(es[t].v);
            }        
        }
    }
    if(d[n] > 0){
        return 1;
    }
    else{
        return 0;
    }
}
int dfs(int u,int fw){
    if(u == n || fw == 0){
        return fw;
    }
    int a = 0;
    for(int t = head[u];t != -1;t = es[t].next){
        if(d[es[t].v] == d[es[t].u] + 1 && es[t].cap > 0 ){
            int flow = dfs(es[t].v,min(fw,es[t].cap));
            if(flow){
                es[t].cap -= flow;
                es[t^1].cap += flow;
                a += flow;
                fw -= flow;
                if(fw == 0){
                    break;
                }
            }
        }
    }
    return a;
}
int main(){
    int t;
    cin >> t;
    int cc = 1;
    while(t--){
        memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&m);
        cnt  = 0;
        for(int i = 0;i < m;i++){
            int x,y,cap;
            scanf("%d%d%d",&x,&y,&cap);
            add(x,y,cap);            
        }
        int ans = 0;
        while(bfs()){
            int tmp;
            ans += dfs(1,INF);
        }
        printf("Case %d: %d\n",cc++,ans);
    }
    return 0;
}
*/
