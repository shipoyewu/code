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
int s = 0;
int e;
int cx[205];
int cy[205];
vector<int> vec[205];
int vis[205];
int path(int u){
	int si  = vec[u].size();
	for(int i = 0;i < si;i++){
		int v = vec[u][i];
		if(!vis[v]){
			vis[v] = 1;
			if((cy[v] == -1|| path(cy[v]))){
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int max_match(){
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
	memset(vis,0,sizeof(vis));
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(cx[i] == -1){
			memset(vis,0,sizeof(vis));
			ans += path(i);
		}
	}
	return ans;
}
int main(){
    while(cin >> n >> m){
    	for(int i = 0;i < n;i++){
    		vec[i].clear();
    	}
    	for(int i = 1;i <= n;i++){
    		int g;
    		scanf("%d",&g);
    		for(int j = 0;j < g;j++){
    			int x;
				scanf("%d",&x);
				vec[i].push_back(x);
    		}
    	}
    	cout << max_match() << endl;
    }
    return 0;
}

