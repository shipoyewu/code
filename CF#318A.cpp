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
int n;
int a[10000];

int main(){
    cin >> n;
    int ma = 0;

    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    int ans  = a[0];

    for(;1;ans ++){
        int cc = 0;
        for(int i = 1;i < n;i++){
            if(a[i] >= ans){
                cc += a[i] - ans + 1;
            }
        }
        if(a[0] + cc <= ans){
            cout << ans -  a[0] << endl;
            break;
        }
    }
    return 0;
}
