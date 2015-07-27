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
#define INF 0x7fffffff
#define MOD 1000000007
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
LL dp[205][205];
int fun(int x1,int y1,int x2,int y2){
	return dp[(abs(x1-x2)+abs(y1-y2))][abs(x1-x2)];
}
int main(){
	int n,m,x,y;
	for(int i = 0;i <= 200;i++){
		dp[i][0] = 1;
	}
	for(int i = 0;i <= 200;i++){
		dp[i][1] = i;
	}
	for(int i = 1;i <= 200;i++){
		for(int j  = 2;j <= i;j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			dp[i][j] %= MOD;
		}
	}
	while(cin >> n >> m >> x >> y){
		LL ans = 0;
		if(n == 1||m == 1){
			ans = n + m - 1; 
		}
		else{
			for(int i = 2;i <= y;i++){
				ans += fun(1,i,x,y);
				ans %= MOD;
			}
			for(int i = y+1;i <= m;i++){
				ans += fun(1,i,x,y);
				ans %= MOD;
			}
			for(int i = 2;i <= x;i++){
				ans += fun(i,m,x,y);
				ans %= MOD;
			}
			for(int i = x+1;i <= n;i++){
				ans += fun(i,m,x,y);
				ans %= MOD;
			}
			for(int i = y;i < m;i++){
				ans += fun(n,i,x,y);
				ans %= MOD;
			}
			for(int i = 1;i < y;i++){
				ans += fun(n,i,x,y);
				ans %= MOD;
			}
			for(int i = x;i < n;i++){
				ans += fun(i,1,x,y);
				ans %= MOD;
			}
			for(int i = 1;i < x;i++){
				ans += fun(i,1,x,y);
				ans %= MOD;
			}
		}
		cout << ans << endl;
	} 
	return 0;
}

