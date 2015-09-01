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
int a;
int fun(int t){
    while(t%2 == 0){
        t /= 2;
    }
    while(t%3 == 0){
        t/=3;
    }
    return t;
}
int main(){
    int n;
    cin >> n;
    int di;
    int flag = 1;
    for(int i = 0;i < n;i++){
        scanf("%d",&a);
        if(i == 0)
            di = fun(a);
        else{
            if(di != fun(a)){
                flag = 0;
            }
        }
    }
    if(flag){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
