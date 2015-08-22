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
char a[200005];
int  b[200005];
LL dp[200005][2];
int main(){
    int t;
    cin >> t;
    int T = 1;
    while(t--){
        scanf("%s",a);memset(dp,0,sizeof(dp));
        int len = strlen(a);
        for(int i = 0 ;i < len;i++){
            scanf("%d",&b[i]);
        }
        if(a[0]=='?')
        {
            dp[0][1] = b[0];
            dp[0][0] = 0;
        }
        if(a[0]=='1')
            dp[0][1]=b[0];
        for(int i = 1;i < len;i++){
            if(a[i] == '?'){
                if(a[i-1] != '?'){
                    dp[i][0] = dp[i-1][a[i-1]-'0']+(0^(a[i-1]-'0'))*b[i];
                    dp[i][1] = dp[i-1][a[i-1]-'0']+(1^(a[i-1]-'0'))*b[i];
                }
                else{
                    dp[i][0] = max(dp[i-1][0]+(0^0)*b[i],dp[i-1][1]+(0^1)*b[i]);
                    dp[i][1] = max(dp[i-1][0]+(0^1)*b[i],dp[i-1][1]+(1^1)*b[i]);
                }
            }
            else{
                if(a[i-1] == '?'){
                    dp[i][a[i]-'0'] = max(dp[i-1][0]+(0^(a[i]-'0'))*b[i],dp[i-1][1] + (1^(a[i]-'0'))*b[i]);
                }
                else{
                    dp[i][a[i]-'0'] = dp[i-1][a[i-1]-'0'] + ((a[i]-'0')^(a[i-1]-'0'))*b[i];
                }
            }
        }
        if(a[len-1] != '?'){
            printf("Case #%d: %lld\n",T++,dp[len-1][a[len-1]-'0']);
        }
        else{
            printf("Case #%d: %lld\n",T++,max(dp[len-1][0],dp[len-1][1]));
        }
    }
    return 0;
}
