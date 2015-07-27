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
#define INF 0x4fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
int n,m;
LL c[205][205];
LL f[205][205];
LL a[205];
LL pre[205];
void max_flow(){
	memset(f,0,sizeof(f));
	LL ans  = 0;
	while(1){
		memset(a,0,sizeof(a));
		queue<int> que;
		que.push(1);
		a[1] = INF;
		while(!que.empty()){
			int u = que.front();
			que.pop();
			for(int i = 1;i <= m;i++){
				if(!a[i] && c[u][i] > f[u][i]){
					pre[i] = u;
					a[i] = min(a[u],c[u][i] - f[u][i]);		
					que.push(i);
					
				}
			}
		}
		if(a[m] == 0) break;
		for(int u = m; u!=1;u = pre[u]){
			f[pre[u]][u] += a[m];
			f[u][pre[u]] -= a[m];
		}
		ans += a[m];
	}
	cout << ans << endl; 
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(c,0,sizeof(c));
		for(int i = 0;i < n;i++){
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			c[x][y] += w;
		}
		max_flow();
	}
	return 0;
}

