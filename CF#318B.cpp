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
int ma[4005][4005];
int d[4005];
int ed[4005][2];
int main(){
    int t;
    int n,m;
    cin >>n >> m;
    for(int i = 0;i < m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ma[x][y] = 1;
        ma[y][x] = 1;
        d[x]++;
        d[y]++;
        if(x < y){
            ed[i][0] = x;
            ed[i][1] = y;
        }
        else{
            ed[i][0] = y;
            ed[i][1] = x;
        }
    }

    int ans = INF;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
            if(i!=j){
                if(ed[i][0] == ed[j][0]){
                    if(ma[ed[i][1]][ed[j][1]]){
                        ans = min(ans,d[ed[i][0]]+d[ed[i][1]]+d[ed[j][1]] - 6);
                    }
                }
                if(ed[i][1] == ed[j][1]){
                    if(ma[ed[i][0]][ed[j][0]]){
                        ans = min(ans,d[ed[i][0]]+d[ed[j][0]]+d[ed[i][1]]-6);
                    }
                }
            }
        }
    }
    if(ans  == INF){
        printf("-1\n");
    }
    else{
        printf("%d\n",ans);
    }
    return 0;
}
