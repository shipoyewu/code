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
#define MIN(a,b) ((a)<(b))?(a):(b)
int dp[125][125];

int main(){
	int n;
	for(int i = 0;i <= 120;i++){
		dp[0][i] = 1;
	}
	for(int i = 1;i <= 120;i++){
		for(int j = 1;j <= 120;j++){
			if(j > i){
				dp[i][j] = dp[i][i];
			}
			else
				dp[i][j] = dp[i-j][j] + dp[i][j-1];
		}
	}
	while(cin >> n){
		cout << dp[n][n] << endl;
	}
	return 0;
}

