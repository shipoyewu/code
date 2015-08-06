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
struct edge{
    int x,y,n,f;
}; 
edge es[600015];
int head[100005];
int ans[600005];
int d[100005];
int vis[100005];
int cnt = 0;

void add(int x,int y){
    es[cnt].x = x;
    es[cnt].y = y;
    es[cnt].n = head[x];
    es[es[cnt].n].f = cnt;
    es[cnt].f = -1;
    head[x] = cnt++;
}
void euler(int u){
	while(head[u]!=-1){
		int v = head[u];
		if(v&1)
			ans[v^1] = 0;
		else
			ans[v] = 1;
		head[u] = es[v].n;
		es[es[v^1].f].n = es[v^1].n;
		d[es[v].y] --;
		d[es[v].x] --;
		u = es[v].y;
	}
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        cnt = 0;
        for(int i = 0;i <= n;i++){
            head[i] = -1;
            d[i] = 0;
        }
        for(int i = 0;i < m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            d[x]++;
			d[y]++;  
            add(x,y);
            add(y,x);
        }
        for(int i = 1;i <= n;i++){
        	if(d[i]&1){
        		euler(i);
        	}
        }
        for(int i = 1;i <= n;i++){
        	if(d[i] > 0){
        		euler(i);
        	}
        }
        for(int t = 0;t < m;t++){
            int i = t<<1; 
            printf("%d\n",ans[i]);
        }
    }    
    return 0;
}
