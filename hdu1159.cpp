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
char a[1005];
char b[1005];
int dp[1005][1005];

int main(){
	while(scanf("%s %s",a+1,b+1)!=EOF){
		int len1 = strlen(a+1);
		int len2 = strlen(b+1);
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= len1;i++){
			for(int j = 1;j <= len2;j++){
				if(a[i] == b[j]){
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		printf("%d\n",dp[len1][len2]);
	}     
    return 0;
}

