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
node es[10005];
int head[1005];
int cnt;
int vis[1005];
int c[1005];
int n,m;
int add(int from,int to){
	es[cnt].from = from ;
	es[cnt].to = to;
	es[cnt].next = head[from];
	head[from] = cnt++;
}
int path(int x){
	for(int t = head[x];t != 0;t = es[t].next){
		if(!vis[es[t].to]){
			vis[es[t].to] = 1;
			if(!c[es[t].to] || path(c[es[t].to])){
				c[es[t].to] = x;
				c[x] = es[t].to;
				return 1;
	 		}
	 	}
	}
	return 0;
}
int max_flow(){
	memset(c,0,sizeof(c));
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(!c[i]){
			memset(vis,0,sizeof(vis));
			ans += path(i);
		}
	}
	return ans;
}
int main(){
    while(cin >> n >> m){
    	memset(head,0,sizeof(head));
    	cnt = 1;
    	for(int i = 0;i < m;i++){
    		int x,y;
    		scanf("%d%d",&x,&y);
    		add(x,y);
    		add(y,x);
    	}
    	cout << max_flow() << endl;
    }
    return 0;
}

