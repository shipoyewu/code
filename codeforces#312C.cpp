#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
int d[100005];
int c[100005];
int ma[100005];
int vis[100005];
#define INF 100000000

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        queue<int> que;
        que.push(x);
        vis[x] = i;
        ma[x] = 0;
        c[x] ++;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            int a = u >> 1;
            int b = u << 1;
            if(a >= 1  && a <= 1e5){
                if(vis[a] !=i){
                    ma[a] = ma[u] + 1;
                    d[a] += ma[a];
                    c[a] ++;
                    vis[a] = i;
                    que.push(a);
                }
            }
            if(b >= 1 && b <= 1e5){
                if(vis[b] != i){
                    ma[b] = ma[u] + 1;
                    d[b] += ma[b];
                    vis[b] = i;
                    c[b] ++;
                    que.push(b);
                }
            }
        }
    }
    int mi = INF;
    for(int i = 1;i <= 1e5;i++){
        if(c[i] == n && d[i] < mi){
            mi = d[i];
        }
    }
    cout << mi << endl;
    return 0;
}
