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
int a[1005];
LL dp[1005];

int main(){
    int t;
	while(cin >>t ,t){
		for(int i = 0;i < t;i++){
			scanf("%d",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		dp[0] = a[0];
		LL  ans = a[0];
		for(int i = 0;i < t;i++){
			dp[i] = a[i];
			for(int j = 0;j < i;j++){
				if(a[i] > a[j]){
					dp[i] = MAX(dp[i],dp[j]+a[i]);
				}
			}
			ans = MAX(dp[i],ans);
		}
		printf("%I64d\n",ans);
	}
    return 0;
}

