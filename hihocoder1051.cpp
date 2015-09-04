#include <cstdio>
#include <iostream>

using namespace std;
int a[105];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>> k;
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        a[0] = 0;
        a[n+1] = 101;
        int l = 1;
        int r = 1;
        int ma = 0;
        while(l <= r){
            while(r < l + k && r <= n) r++;
            if(a[r] - a[l-1]-1 > ma){
                ma = a[r] - a[l-1] - 1;
            }
            l++;
        }
        cout << ma << endl;
    }
    return 0;
}
