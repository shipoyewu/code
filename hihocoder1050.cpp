#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> vec[100005];
int vis[100005];
int d[100005];

int dfs(int x,int st){
    vis[x] = 1;
    int si = vec[x].size();
    for(int i = 0;i < si;i++){
        int v = vec[x][i];
        if(!vis[v]){
            d[v] = st+1;
            dfs(v,st+1);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i < n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    dfs(1,0);
    int ma = -1;
    int x = 0;
    for(int i = 1;i <= n;i++){
        if(d[i] > ma){
            ma = d[i];
            x = i;
        }
    }
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    dfs(x,0);
    ma = -1;
    for(int i = 1;i <= n;i++){
        if(d[i]>ma){
            ma = d[i];
        }
    }
    cout << ma << endl;、*
    return 0;
}
//先从任意一点开始找一个最长路，然后从这个最长路的终点开始找最长路这时候找到的最长路就是任意两个点的最长路
/*很明显，两个点之间的最长的距离一定是从某一个根开始的最长路加上次长路的，如果找到最长路然后再从最长路终点开始找最长路那么一定是找到了任意两个点的最长距离*/
