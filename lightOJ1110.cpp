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
char a[1000];
char b[1000];
int dp[105][105];
string ans[105][105];
int main(){
	int t;
	cin >> t;
	int T = 1;
	while(t--){
		scanf("%s%s",a+1,b+1);
		int lena = strlen(a+1);
		int lenb = strlen(b+1);
		memset(dp,0,sizeof(dp));
		for(int i = 0;i <= lena ;i++){
			for(int j = 0;j <= lenb;j++){
				ans[i][j] = "";
			}
		}
		for(int i = 1;i <= lena;i++){
			for(int j = 1;j <= lenb;j++){
				if(a[i] == b[j]){
					dp[i][j] = dp[i-1][j-1]+ 1;
					ans[i][j] = ans[i-1][j-1] + a[i];
				}
				else{
					if(dp[i-1][j] == dp[i][j-1]){
						ans[i][j] = min(ans[i-1][j],ans[i][j-1]); 
					}
					else if(dp[i-1][j] > dp[i][j-1]){
						ans[i][j] = ans[i-1][j]; 
					}
					else{
						ans[i][j] = ans[i][j-1]; 
					}
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		if(ans[lena][lenb].length()!=0)
			cout << "Case " << T++ <<": " << ans[lena][lenb] << endl;
		else
			cout << "Case " << T++ <<": " << ":(" << endl; 
	} 
	return 0;
}

