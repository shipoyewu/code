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
int l[1000];
double w[1000];
double dp[10005][105];

int main(){
    int t;
	cin >> t;
	double a;
	int n;
	while(t--){
		scanf("%lf %d",&a,&n);
		int sum  = 0;
		
		for(int i = 1;i <= n;i++){
			scanf("%d%lf",&l[i],&w[i]);
			w[i] = 1 -w[i];
			sum += l[i];
		}
		for(int i = 0;i <= sum;i++){
			for(int j = 0;j <= n;j++){
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for(int i = 0;i <= sum;i++){
			for(int j = 1;j <= n;j++){
				if(l[j] > i){
					dp[i][j] = dp[i][j-1];
				}
				else{
					dp[i][j] = max(dp[i][j-1],dp[i-l[j]][j-1]*w[j]);
				}
			}
		}
		int ans = 0;
		a = 1 - a;
		for(int i = 0;i <= sum;i++){
			if(dp[i][n] >= a ){
				ans = i;
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}

