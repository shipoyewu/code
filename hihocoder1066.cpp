#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;
int n;
map<string,int> ma;
int cnt = 1;
int f[200005];
int getfa(int x){
    return f[x] == x ? x : f[x] = getfa(f[x]);
}
int main(){
    int n;
    cin >> n;
    cnt = 1;
    for(int i = 1;i <= 2*n;i++){
        f[i] = i;
    }
    for(int i = 0;i < n;i++){
        int x;
        string a,b;
        cin >> x >> a >> b;
        if(ma[a] == 0){
            ma[a] = cnt++;
        }
        if(ma[b] == 0){
            ma[b] = cnt++;
        }
        int fa = getfa(ma[a]);
        int fb = getfa(ma[b]);
        if(x == 0){
            f[fa] = fb;
        }
        else{
            if(fa == fb){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
    return 0;
}
