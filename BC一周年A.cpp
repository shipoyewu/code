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
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,p,q;
        scanf("%d%d%d%d",&n,&m,&p,&q);
        int ans = 0;
        if(q < m*p){
            ans = (n/m)*q;
            n = n % m;
        }
        if(n < m){
            if(n * p < q){
                ans += n * p;
            }
            else{
                ans += q;
            }
        }
        else{
            ans = p * n;
        }
        printf("%d\n",ans);
    }
    return 0;
}


