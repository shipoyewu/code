#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
char a[200005];
int q[10];
int d[10];

int main(){
    int x,y,z;
    map<char,int> ma;
    ma['R'] = 1;
    ma['Y'] = 2;
    ma['B'] = 3;
    scanf("%d%d%d",&q[0],&q[1],&q[2]);
    sort(q,q+3);
    scanf("%s",a);
    int m = 0;
    for(int i = 0;a[i];i++){
        d[ma[a[i]]]++;
        //cout << ma[a[i]] <<endl;
        int c[10];
        c[0] = abs(d[1] - d[2]);
        c[1] = abs(d[2] - d[3]);
        c[2] = abs(d[3] - d[1]);
        sort(c,c+3);
        int flag = 1;
        for(int i = 0;i < 3;i++){
            if(c[i] != q[i]){
                flag = 0;
                break;
            }
        }
        if(d[1]+d[2]+d[3] > m){
            m = d[1]+d[2]+d[3];
        }
        if(flag){
            d[1] = 0;
            d[2] = 0;
            d[3] = 0;
        }
    }
    cout << m <<endl;
    return 0;

}
