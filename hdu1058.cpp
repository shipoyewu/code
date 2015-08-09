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
LL dp[6000];

LL a[] = {2,3,5,7};
const LL IN = 0x2ffffffffff;

int main(){
	int t;
	dp[1] = 1;
	int d = 1;
	for(int i = 2;i <= 5842;i++){
		dp[i] = IN;
		for(int j = d;j < i;j++){
			for(int k = 0;k < 4;k++){
				if(dp[j]*a[k] > dp[i-1])
					dp[i] = min(dp[j]*a[k],dp[i]);
			}
		}
	}
	int n;
	while(cin>>n&&n)
	{
		cout<<"The "<<n;
		if(n%10==1&&n%100!=11)
			cout<<"st";
		else if(n%10==2&&n%100!=12)
			cout<<"nd";
		else if(n%10==3&&n%100!=13)
			cout<<"rd";
		else
			cout<<"th";
		cout<<" humble number is "<<dp[n]<<"."<<endl;
	}
	return 0;
}

