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
int dp[10][10000*6+10];
int a[10];

int main(){
	int t = 1;
	while(scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]),a[1]||a[2]||a[3]||a[4]||a[5]||a[6]){
		int sum = 0;
		for(int i = 1;i <= 6;i++){
			sum += a[i]*i;
		}
		printf("Collection #%d:\n",t++);
		if(sum&1){
			printf("Can't be divided.\n\n");
		}
		else{
			int md = sum/2;
			memset(dp,-1,sizeof(dp));
			dp[0][0] = 0;
			for(int i = 1;i <= 6;i++){
				for(int j = 0;j <= md;j++){
					if(dp[i-1][j] >= 0){
						dp[i][j] = a[i];
					}
					else{
						if(j < i || dp[i][j-i] <= 0)
							dp[i][j] = -1;
						else
							dp[i][j] = dp[i][j-i]-1;
					}
				}
			}
			if(dp[6][md] >= 0){
				printf("Can be divided.\n\n");
			}
			else{
				printf("Can't be divided.\n\n");			
			}
		}
	} 
	return 0;
	
}

