#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n,m;
vector<int> vec[105];
int vis[105][105];
#define INF 10000000
int nex[105];
int pre[105];
int vi[105];


int bfs(int u,int v,int t){
	if(v == 0){
		return 1;
	}
    queue<int> que;
    que.push(u);
    vi[u] = 1;
    while(!que.empty()){
        int tm = que.front();
        que.pop();
        int si = vec[tm].size();
        for(int i = 0;i < si;i++){
            int q = vec[tm][i];
            if(vis[tm][q] < t && !vi[q]){
                if(q == v){
                    int c = q;
                    pre[q] = tm;
                    while( c != u){
                        vis[pre[c]][c] = INF;
                        c = pre[c];
                    }
                   	return 1;
                }
                else{
                    vis[tm][q] = t;
                    vi[q] = 1;
                    pre[q] = tm;
                    que.push(q);
                }
            }
        }
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            vec[i].clear();
        }
        memset(vis,0,sizeof(vis));
        for(int i = 1;i < n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        scanf("%d",&m);
        memset(nex,-1,sizeof(nex));
        int s = 1;
        for(int i = 0;i < m;i++){
            int x;
            scanf("%d",&x);
            nex[s] = x;
            s = nex[s];
        }
        nex[s] = 0;
        int flag = 1;
        int t = 1;
        s = 1;
        while(s){
        	memset(vi,0,sizeof(vi));
        	if(!bfs(s,nex[s],t)){
        		flag = 0;
        		break;
        	}
        	else{
        		s = nex[s];
        		t++;
        	}
        }
        if(flag){
        	printf("YES\n");
        }
        else{
        	printf("NO\n");
        }
    }
    return 0;
}
