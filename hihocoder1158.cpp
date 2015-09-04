#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int pre[500005];
int n;
int c[1004];
int vis[1004];
int a[1004];

vector<int> vec[1004];

int path(int x){
    int si = vec[x].size();
    for(int i = 0; i < si;i ++){
        int v = vec[x][i];
        if(vis[v] == 0){
            vis[v] = 1;
            if(c[v] ==-1 || path(c[v])){
                c[v] = x;
                c[x] = v;
                return 1;
            }
        }
    }
    return 0;
}
int max_flow(){
    memset(c,-1,sizeof(c));
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(c[i]==-1){
            memset(vis,0,sizeof(vis));
            ans += path(i);
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    pre[0] = 1;
    pre[1] = 1;
    for(int i = 2;i <= 500000;i++){
        if(pre[i] == 0){
            for(int j = i+i;j <=500000;j+=i){
                pre[j] = 1;
            }
        }
    }
    for(int kcase = 1;kcase <= t;kcase ++){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
            vec[i].clear();
        }
        sort(a,a+n);
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(a[j]%a[i] == 0){
                    if(pre[a[j]/a[i]] == 0){
                        vec[i].push_back(j);
                        vec[j].push_back(i);
                    }
                }
            }
        }
        printf("Case #%d: %d\n",kcase,n-max_flow());
    }
    return 0;
}
