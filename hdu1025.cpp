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
#define INF 0x4fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
struct node{
	int x,y;
	bool operator<(const node& a)const{
		return x < a.x && y <= a.y;
	}
};
int cmp(node a,node b){
	return a.x < b.x;
}
node dp[500005];
node a[500005];
int main(){
	int n;
	int T = 1;
	while(cin >> n){
		for(int i = 0;i < n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		for(int i = 0;i <= n;i++){
			dp[i].x = INF;
			dp[i].y = INF;
		}
		sort(a,a+n,cmp);
		for(int i = 0;i < n;i++){
			*lower_bound(dp,dp+n,a[i]) = a[i];
		}
		node ans;
		ans.x = INF;
		ans.y = INF;
		int q = lower_bound(dp,dp+n,ans)-dp;
		if(q == 1)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n",T++,q);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n",T++,q);
	}
	return 0;
}

