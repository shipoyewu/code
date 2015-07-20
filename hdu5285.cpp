#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> vec[100005];
int color[100005];

int ans = 0;

int bfs(int s){
    queue<int> que;
    int wri = 0;
    int bla = 0;
    que.push(s);
    color[s] = 1;
    wri++;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        int si = vec[u].size();
        for(int i = 0;i < si;i ++){
            int v = vec[u][i];
            if(color[v]){
                if(color[v] == color[u]){
                    return false;
                }
            }
            else{
                color[v] = 3 - color[u];
                if(color[v]==1){
                    wri++;
                }    
                else{
                    bla++;
                }
                que.push(v);
            }
        }
    }
    ans += max(wri,bla);
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++){
            vec[i].clear();
            color[i] = 0;
        }
        if(n == 0){
            printf("Poor wyh\n");
            continue;
        }
        for(int i = 0;i < m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        int flag = 0;
        for(int i = 1;i <= n;i++){
            if(!color[i]){
                if(!bfs(i)){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag){
            printf("Poor wyh\n");
        }        
        else{
            if(m == 0){
                if(ans == 1){
                    printf("Poor wyh\n");
                }else{
                    printf("%d %d\n",ans-1,1);
                }
            }else{
                printf("%d %d\n",ans,n-ans);
            }
        }
    }    
    return 0;
}

