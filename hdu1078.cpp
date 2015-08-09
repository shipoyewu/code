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
int dp[105][105];
int n,k;
int a[105][105];
int d[4][2] = {1,0,0,1,-1,0,0,-1};

int fun(int x,int y){
	if(dp[x][y]) return dp[x][y];
	for(int i = 1;i <= k;i++){
		for(int j = 0;j < 4;j++){
			int dx = x + d[j][0]*i;
			int dy = y + d[j][1]*i;
			if(dx < n && dx >= 0 && dy < n && dy >= 0 && a[dx][dy] > a[x][y]){
				dp[x][y] = max(fun(dx,dy),dp[x][y]);
			}
		}
	}
	return dp[x][y] += a[x][y];
}
int main(){
	while(scanf("%d%d",&n,&k),!(n==-1&&k==-1)){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		fun(0,0);
		printf("%d\n",dp[0][0]);
	} 
	return 0;
}

