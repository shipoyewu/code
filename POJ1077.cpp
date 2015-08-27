#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10];
int goal[][2] = {{0,0},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
int move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int flag;
char op[] = "ulrd";
int path[1000];
int ans;
int nixu(){
    int ni  = 0;
    for(int i = 0;i < 9;i++){
        if(a[i] == 9) continue;
        for(int j = i+1;j < 9;j++){
            if(a[j] == 9) continue;
            if(a[j] < a[i]){
                ni ++;
            }
        }
    }
    return !(ni%2);
}
int co(){
    int cost = 0;
    int cc = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cost += abs(i-goal[a[cc]][0])+ abs(j-goal[a[cc]][1]);
            cc++;
        }
    }
    return cost;
}
void dfs(int cur,int len,int limit,int pre){
    int cc = co();
    if(cc == 0){
        flag = 1;
        ans = len;
        return;
    }
    if(len <= limit){
        int x = cur/3;
        int y = cur%3;
        for(int i = 0;i < 4;i++){
            if(len == 0 || (i + pre != 3)){
                int sx = x + move[i][0];
                int sy = y + move[i][1];
                if(sx < 3 && sx >=0 && sy < 3 && sy >= 0){
                    swap(a[cur],a[sx*3+sy]);
                    cc = co();
                    if(cc + len <= limit && !flag){
                        path[len] = i;
                        dfs(sx*3+sy,len+1,limit,i);
                        if(flag) return;
                    }
                    swap(a[cur],a[sx*3+sy]);
                }
            }
        }
    }
}
int main(){
    char ch[10];
    int st;
    //freopen("out.txt","w",stdout);
    for(int i = 0;i < 9;i++){
        scanf("%s",ch);
        a[i] = ch[0];
        if(ch[0] == 'x') st = i,a[i]  = '9';
        a[i] -= '0';
    }
    int tmp[15];
    for(int i = 0;i < 9;i++){
        tmp[i] = a[i];
    }
    if(nixu()){
        flag = 0;
        int limit = 0;
        while(!flag){
            for(int i = 0;i < 9;i++){
                a[i] = tmp[i];
            }
            dfs(st,0,limit,0);
            if(!flag)
                limit++;
        }
        for(int i = 0;i < ans;i++){
            putchar(op[path[i]]);
        }
        printf("\n");
    }
    else{
        printf("unsolvable\n");
    }
    return 0;
}
