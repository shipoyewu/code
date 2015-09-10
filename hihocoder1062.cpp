#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>

using namespace std;
int n,cnt = 1;
int ne[405] = {0};
map<string,int> ma;
string qu[405];
vector<int> vec[405];
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        string a,b;
        cin >> a >> b;
        if(ma[a] == 0){
            ma[a] = cnt;
            qu[cnt] = a;
            cnt++;
        }
        if(ma[b] == 0){
            ma[b] = cnt;
            qu[cnt] = b;
            cnt++;
        }
        int x,y;
        x = ma[a];
        y = ma[b];
        ne[y] = x;
    }
    for(int i = 1;i < cnt;i++){
        int c = i;
        vec[i].push_back(i);
        while(ne[c] != 0){
            vec[i].push_back(ne[c]);
            c = ne[c];
        }
    }
    int m;
    cin >> m;
    while(m--){
        string a,b;
        cin >> a >> b;
        int x = ma[a];
        int y = ma[b];
        int sx = vec[x].size();
        int sy = vec[y].size();
        int flag = 0;
        if(a == b){
            cout << a << endl;
            flag = 1;
        }
        else if(sx != 0 && sy != 0){
            for(int i = 0;i < sx;i++){
                for(int j = 0;j < sy;j++){
                    if(vec[x][i] == vec[y][j]){
                        cout << qu[vec[x][i]] << endl;
                        flag = 1;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
        }
        if(!flag){
            printf("-1\n");
        }
    }
    return 0;
}
