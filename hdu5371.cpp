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
#define nf -9
#define ng -10
#define ne -100
int a[100015];
int b[200015];
int n;
int p[200015];


void newb(){
    b[0] = ng;
    b[1] = nf;
    int j = 2;
    for(int i = 0;i < n;i++){
        b[j++] = a[i];
        b[j++] = nf;
    }
    b[j] = ne;
}
void manachar(){
    int maxd =  0;
    int id = 0;
    n = n * 2+2;
    for(int i = 0;i < n;i++){
        if(maxd > i){
            p[i] = min(p[2*id-i],maxd-i);
        }else{
            p[i] = 1;
        }
        while(b[p[i]+i] == b[i-p[i]]) p[i]++;
        if(p[i]+i>maxd){
            maxd = p[i]+i;
            id= i;
        }
    }
}
int main(){
    int t;
    cin >> t;
    int T = 1;
    while(t--){
        scanf("%d",&n);
        memset(p,0,sizeof(p));
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }
        newb();
        manachar();
        int ans = 1;
        for(int i = 1;i < n;i+=2){
            for(int j = p[i];j >= ans;j -= 2){
                if(p[i+j-1] >= j){
                	ans = j;
                	break;
                }
                    
            }            
        }        
        printf("Case #%d: %d\n",T++,ans/2*3);
    }
    return 0;
}
