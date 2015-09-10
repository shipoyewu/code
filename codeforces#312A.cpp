#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
struct node{
    int x,y;
    bool operator <(const node& a)const {
        return x < a.x;
    }
};
node a[10000];

int main(){
    int t;
    cin >> t;
    memset(a,0,sizeof(a));
    for(int i = 0;i < n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a,a+n);
    node c;
    c.x = 0;
    int lf = lower_bound(a,a+n,c)-a;
    int ans  = 0;

    if(lf < n/2){
        for(int i = 0;i < 2*lf+1;i++){
            ans += a[i].y;
        }
    }
    else{
        lf = n-lf;
        for(int i = n-1,j = 0;i >= 0 && j < 2*lf+1;i--,j++){
            ans += a[i].y;
        }
    }
    cout << ans << endl;
    return 0;

}
