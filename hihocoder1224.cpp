#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;
vector<int> vec[100005];
int d[100005];
int dfs(int u){
    int si = vec[u].size();
    if(si == 0){
        return d[u] = 0;
    }
    int ma = 0;
    for(int i = 0;i < si;i++){
        int v = vec[u][i];
        ma= max(ma,dfs(v));
    }
    return d[u] = ma + 1;
}
void del(int u){
    int si = vec[u].size();

    for(int i = 0;i < si;i++){
        int v = vec[u][i];
        if(d[v] == d[u] - 1){
            vec[u].clear();
            del(v);
            return;
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
    }
    dfs(1);
    int ans = d[1];
    del(1);
    int ma = 0;
    for(int i = 0;i < n;i++){
        if(vec[i].size() != 0){
            if(d[i] > ma){
                ma = d[i];
            }
        }
    }
    if(ma == 0){
        ma = -1;
    }
    cout <<ans+ma+1<< endl;
    return 0;
}
