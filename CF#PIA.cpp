#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    a[0] = a[1];
    a[n+1] = a[n];
    for(int i = 1;i <= n;i++){
        if(i == 1){
            printf("%d",abs(a[i]-a[i+1]));
        }
        else if(i == n){
            printf("%d",abs(a[i]-a[i-1]));
        }else{
            printf("%d",min(abs(a[i]-a[i+1]),abs(a[i]-a[i-1])));
        }
        if(i == n){
            printf(" %d\n",abs(a[0]-a[i]));
        }
        else if(i == 0){
            printf(" %d\n",abs(a[n]-a[i]));
        }else{
            printf(" %d\n",max(abs(a[0]-a[i]),abs(a[n]-a[i])));
        }
    }
    return 0;
}
