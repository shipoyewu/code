#include <cstdio>
#include <cstdio>
#include <iostream>
using namespace std;
#define LL long long
LL dp[105];

int main(){
	 int n;
	 dp[0] = 1;
	 for(int i = 1;i <= 101;i++){
	 	dp[i] = dp[i-1];
	 	for(int j = 1;j < i;j++){
	 		dp[i] += dp[j]*dp[i-j-1];
	 	}
	 }
	 while(cin >> n){
	 	cout << dp[n] << endl;
	 }
	 return 0;
}
