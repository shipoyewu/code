#include <cstdio>
#include <iostream>
using namespace std;
#define LL long long
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int flag = 0;
    int l = 0;
    int r = 0;
    for(int i = 0;i < n;i++){
        int a;
        scanf("%d",&a);
        if(a > k){
            r++;
        }
        else if(a < k){
            l++;
        }
        else{
            flag = 1;
        }
    }
    if(flag){
        printf("%d\n",l+1);
    }
    else{
        printf("-1\n");
    }
    return 0;
}
