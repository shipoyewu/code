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
LL dp[5005][5005];
LL sum[300005];
int a[300005];

int main(){
	int n,k;
	cin >>  n >> k;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a+1,a+n+1);
	sum[0] = 0;
	a[0] = a[1];
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i-1] + a[i] - a[i-1];
	}	
	//分成k组
	//有n%k组是长度是n/k+1的，k-n%k组是长度为n/k的 
	int l1 = n/k+1;
	int l2 = n/k;
	int n1 = n%k;
	int n2 = k-n%k;
	for(int i = 0;i <= n1;i++){
		for(int j = 0;j <= n2;j++){
			if(i ==0 || j ==0){
				if(i == 0 && j == 0)
					dp[i][j] = 0;
				else
					if(i == 0)
						dp[i][j] = dp[i][j-1] + sum[j*l2] - sum[(j-1)*l2+1];
					else
						dp[i][j] = dp[i-1][j] + sum[i*l1] - sum[(i-1)*l1+1];
				}
			}
			else 
				dp[i][j] = min(dp[i-1][j]+sum[i*l1+j*l2] - sum[(i-1)*l1 +j*l2+1],dp[i][j-1]+sum[i*l1+j*l2]-sum[i*l1+(j-1)*l2+1]);
		}
	}
	cout << dp[n1][n2] << endl;
    return 0; 
}

