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
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
struct node{
	int x,y,w;
};
int a[1000005];
LL dp[1000005];//dp[i] Ϊǰi��������ǰ���a[i]��m���Ӷ˵����ֵ���������˹������飬
LL cc[1000005];//ǰi���ֳ�m���Ӷ˵����͵�λ��
int main(){
	int n,m;
	while(cin >> m >> n){
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			dp[i] = 0;
			cc[i] = 0;
						
		}
		dp[0] = 0;
		cc[0] = 0;
		LL mmax;
		for(int i = 1;i <= m;i++){
			mmax = -INF; 
			for(int j = i;j <= n;j++){
				dp[j] = MAX(dp[j-1]+a[j],cc[j-1]+a[j]);
				cc[j-1] = mmax;
				mmax = MAX(mmax,dp[j]); 
			}
		}
					
		printf("%I64d\n",mmax);
	} 
	return 0;
}

