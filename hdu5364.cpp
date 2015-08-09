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

int a[100005];

int main(){
    int n;
    while(cin>>n){
        memset(a,0,sizeof(a));
        for(int i = 0;i < n;i++){
            int x;
            scanf("%d",&x);
            a[x]++;
                
        }
        int flag = 0;
        for(int i = 0;i <= 10000;i++){
            if(a[i] > n/2){
                printf("%d\n",i);
                flag = 1;
                break;
            }            
        }
        if(!flag){
            printf("-1\n");
        }
    } 
    return 0;
    
}
