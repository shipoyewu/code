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
struct node{
	int x,y,i;
	bool operator < (const node& a)const{
		return x < a.x;
	}
};
node a[100000];
int dp[100000];
void dfs(int now,int d){
	for(int i = now-1;i >= 0;i--){
		if(dp[i] == d-1 && a[i].x < a[now].x  && a[i].y > a[now].y){
			dfs(i,d-1);
			break;
		}
	}
	printf("%d\n",a[now].i);
}
int main(){
	int n = 0;
	while(scanf("%d%d",&a[n].x,&a[n].y)!=EOF) a[n].i = n+1,n++;
	sort(a,a+n);
	for(int i = 0;i < n;i++){
		dp[i] = 1;
	}
	int ma = 0;
	int ss ;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < i;j++){
			if(a[i].y < a[j].y && a[i].x > a[j].x){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		if(ma < dp[i]){
			ma = dp[i];
			ss = i;
		}
	}
	printf("%d\n",ma);
	dfs(ss,ma);
    return 0;
}

