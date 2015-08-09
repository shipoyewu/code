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
int a[10005];
int dp[10005];
int l[10005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int now = 0;
		int ans = 0;
		int flag = 0; 
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			if(a[i] >= 0){
				flag = 1;
			}
		}
		int loc = 0;
		for(int i = 0;i < n;i++){
			if(a[i] > 0){
				now += a[i];
			}
			else{
				if(now + a[i] >= 0){
					now += a[i]; 
				}
				else{
					now = 0;
					loc = i+1;
				}
			}
			ans = max(ans,now);
			dp[i] = ans;
			l[i] = loc;
		}
		printf("%d ",ans);
		if(flag == 0){
			printf("%d %d\n",a[0],a[n-1]);
		}
		else{
			int i = 0;
			if(ans!=0)
				for(i = 0;i < n;i++){
					if(dp[i] == ans ){
						break;
					}
				}
			else{
				for(i = 0;i < n;i++){
					if(a[i] == 0) break;
				}
			}
			printf("%d %d\n",a[l[i]],a[i]);						
		}
	}
	return 0;
	
}

