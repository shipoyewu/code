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
#define INF 0x0fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
int dp[105][105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++ ){
		for(int j =  1;j <= n;j++){
			dp[i][j] = INF;
		}
	}	
	for(int i = 1;i <= n;i++){
		dp[i][i] = 0;
	}
	for(int i = 0;i < m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		dp[x][y] = min(dp[x][y],w);
		dp[y][x] = min(dp[y][x],w);
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(j != 1)
				putchar(' ');
			printf("%d",dp[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

