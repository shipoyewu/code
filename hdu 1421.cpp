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
int a[2005];
int dp[2005][10005];

int main(){
    int n,m;
	while(cin >> n >> m){
		
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		
		for(int i = 0;i <= m;i++){
			dp[0][i] = INF;
			dp[1][i] = INF; 
		}
		for(int i = 0;i <= n;i++){
			dp[i][0] = 0;
		}
		for(int i = 2;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(i < 2*j){
					dp[i][j] = INF;
				}	
				else{
					dp[i][j] = min(dp[i-2][j-1]+(a[i-1]-a[i])*(a[i-1]-a[i]),dp[i-1][j]);
				}
			}
		}
		printf("%d\n",dp[n][m]);
	} 
    return 0;
}

