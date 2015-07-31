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
int k,n,m;
vector<int> vec[1005];
int vx[1005];
int vy[1005];
int vis[1005];

int path(int u){//注意这里其实每次都是从x边开始 
	int si = vec[u].size();
	for(int i = 0;i < si;i++){
		int v = vec[u][i];
		if(!vis[v]){
			vis[v] = 1;
			if(vy[v] == -1 || path(vy[v])){
				vx[u] = v;
				vy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int maxmatch(){
	int res = 0;
	memset(vx,-1,sizeof(vx));
	memset(vy,-1,sizeof(vy));
	for(int i = 1;i <= m;i++){
		if(vx[i] == -1){
			memset(vis,0,sizeof(vis));
			res += path(i);
		}
	}	
	return res;
} 
int main(){
	while(cin >> k,k){
		cin >> m >> n;
		for(int i = 0;i <= n+m;i++){
			vec[i].clear();
		}
		int cnta = 1;
		int cntb = 1;
		for(int i = 0;i < k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
		}
		cout << maxmatch() << endl;;
	} 
	return 0;
}

