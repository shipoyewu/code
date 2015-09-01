#include <cstdio>
#include <iostream>

using namespace std;
int a[100005];
int l[100005];
int r[100005];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }

    for(int i = 1;i <= n;i++){
        l[i] = min(l[i-1]+1,a[i]);
    }
    for(int i = n;i >= 1;i--){
        r[i] = min(r[i+1]+1,a[i]);
    }
    int ma = 0;
    for(int i = 1;i <= n;i++){
        ma = max(ma,min(l[i],r[i]));
    }
    cout << ma << endl;
}
