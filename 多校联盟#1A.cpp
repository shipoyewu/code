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
double a[30];
double b[30];
double c[30];
double dp[1 << 21];
double d[30][30];
int n,m;
double ans;

void  fun(int status,int cur,int qu){
	if(qu == m){
		ans = max(ans,dp[status]);
		return;
	}
	if(cur > n){
		return ;
	}
	double c =  0;
	for(int i = 0;i < cur;i++){
		if(status&(1<<i)){
			c += d[cur][i];	
		}
	}
	dp[status|(1<<cur)] = dp[status] + c;
	fun(status|(1<<cur),cur+1,qu+1);
	fun(status,cur+1,qu);
}
int main(){
	while(cin >> n >> m){
		for(int i = 0;i < n;i++){
			cin >> a[i] >> b[i]  >> c[i];
		}
		memset(d,0,sizeof(d));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				d[i][j] = (a[i]-a[j])*(a[i]-a[j]) + (b[i]-b[j])*(b[i]-b[j]) + (c[i]-c[j])*(c[i]-c[j]);
			}
		}
		memset(dp,0,sizeof(dp));
		ans = 0;
		fun(0,0,0);
		printf("%.6f\n",ans);
	}
    return 0;
}

