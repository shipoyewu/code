#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 100000000;
int to[20005];
int w[20005];
int nex[20005];
int n,m,s,t;
int head[1005];
int cnt = 0;
int d[1005];
int cc[1005];
int add(int from,int t,int wi){
    to[cnt] = t;
    w[cnt] = wi;
    nex[cnt] = head[from];
    head[from] = cnt++;
}
int fun(){
    for(int i = 1;i <= n;i++){
        d[i] = INF;
    }
    d[s] = 0;
    queue<int> que;
    memset(cc,0,sizeof(cc));
    que.push(s);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        cc[u] = false;
        for(int i = head[u];i != -1;i = nex[i]){
            int v = to[i];
            if(d[v] > d[u] + w[i]){
                d[v] = d[u] + w[i];
                if(!cc[v]){
                    cc[v] = true;
                    que.push(v);
                }
            }
        }
    }
    return d[t];
}
int main(){
    cin >> n >> m >> s >> t;
    memset(head,-1,sizeof(head));
    for(int i = 0;i < m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        add(x,y,w);
        add(y,x,w);
    }
    cout << fun() << endl;
    return 0;
}
