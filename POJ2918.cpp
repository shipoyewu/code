#include <cstdio>
#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;
int s[][2] = {{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
int a[10][10];
int ch[] = {0,0,0,1,1,1,2,2,2,
            0,0,0,1,1,1,2,2,2,
            0,0,0,1,1,1,2,2,2,
            3,3,3,4,4,4,5,5,5,
            3,3,3,4,4,4,5,5,5,
            3,3,3,4,4,4,5,5,5,
            6,6,6,7,7,7,8,8,8,
            6,6,6,7,7,7,8,8,8,
            6,6,6,7,7,7,8,8,8,
    };
int check(int step,int k){
    int x = step/9;
    int y = step%9;
    for(int i = 0;i < 9;i++){
        if(a[x][i] == k)return 0;
        if(a[i][y] == k)return 0;
    }
    int q = ch[step];
    x = s[q][0];
    y = s[q][1];
    for(int i = -1;i <= 1;i++){
        for(int j = -1;j <= 1;j ++){
            if(a[x+i][y+j]==k){
                return 0;
            }
        }
    }
    return 1;
}
int fun(int step){
    if(step >= 81) return 1;
    if(a[step/9][step%9] != 0){
       return fun(step+1);
    }
    for(int i = 1;i <= 9;i++){
        if(check(step,i)){
            a[step/9][step%9] = i;
            if(fun(step+1)){
                return 1;
            }
            a[step/9][step%9] = 0;
        }
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    int T = 1;
    while(t--){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                scanf("%1d",&a[i][j]);
            }
        }
        fun(0);
        printf("Scenario #%d:\n",T++);
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


