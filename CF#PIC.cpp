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
LL a[200005];
LL d[200005];
LL g[200005];

int main(){
    int n,k;
    cin >> n >> k;
    map<LL,int> ma;
    LL ans  = 0;
    for(int i = 0;i < n;i++){
        scanf("%I64d",&a[i]);
    }
    for(int i = 0;i < n;i++){
        if(ma.find(a[i]) == ma.end()){
            ma[a[i]] = 0;
        }
        if(a[i]%k == 0){
            LL q =  a[i]/k;
            if(ma.find(q) != ma.end()){
                d[i] = ma[q];
            }
            else{
                d[i] = 0;
            }
        }
        ma[a[i]] ++;
    }
    ma.clear();
    for(int i = n - 1;i >= 0;i--){
        if(ma.find(a[i]) == ma.end()){
            ma[a[i]] = 0;
        }
        LL q =  a[i]*k;
        if(ma.find(q) != ma.end()){
            g[i] = ma[q];
        }
        else{
            g[i] = 0;
        }
        ma[a[i]] ++;
    }
    for(int i = 0;i < n;i++){
        ans += d[i] * g[i];
    }
    cout << ans << endl;
    return 0;
}
