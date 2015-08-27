#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#define INF 1000000
char a[100][100];
char in[10][10];
char s[1000];
int tt[9][9] = {0,0,0,1,1,1,2,2,2,
                0,0,0,1,1,1,2,2,2,
                0,0,0,1,1,1,2,2,2,
                3,3,3,4,4,4,5,5,5,
                3,3,3,4,4,4,5,5,5,
                3,3,3,4,4,4,5,5,5,
                6,6,6,7,7,7,8,8,8,
                6,6,6,7,7,7,8,8,8,
                6,6,6,7,7,7,8,8,8
            };
int po[][2] = {{1,1},{1,4},{1,7},
               {4,1},{4,4},{4,7},
               {7,1},{7,4},      {7,7}};
int x[10],y[10],z[10];
int check(int st,char ch){
    int p = st/9;
    int q = st%9;
    for(int i = 0;i < 9;i++){
        if(in[p][i] == ch) return 0;
        if(in[i][q] == ch) return 0;
    }
    p = po[tt[p][q]][0];
    q = po[tt[p][q]][1];
    for(int i = -1;i <= 1;i++){
        for(int j = -1;j <= 1;j++){
            if(in[p+i][q+j] == ch){
                return 0;
            }
        }
    }
    return 1;
}
int next(){
    int ma = INF;
    int p,q;
    for(int i = 0;i < 9;i++){
        if(x[i] != 0 && x[i] < ma){
            p = 1;
            q = i;
            ma = x[i];
        }
    }
    for(int i = 0;i < 9;i++){
        if(y[i]!=0 && y[i] < ma){
            p = 2;
            q = i;
            ma = y[i];
        }
    }
    for(int i = 0;i < 9;i++){
        if(z[i] !=0 && z[i] < ma){
            p = 3;
            q = i;
            ma = z[i];
        }
    }

    if(ma == INF){
        return 89;
    }
    else{
        if(p == 1){
            for(int i =  0;i < 9;i++){
                if(in[q][i] == '.'){
                    return q*9+i;
                }
            }
        }
        if(p == 2){
            for(int i = 0;i < 9;i++){
                if(in[i][q] == '.'){
                    return i*9+q;
                }
            }
        }
        if(p == 3){
            int w = po[q][0];
            int u = po[q][1];
            for(int i = -1;i <= 1;i++){
                for(int j = -1;j <= 1;j++){
                    if(in[i+w][j+u] == '.'){
                        return (i+w)*9+(j+u);
                    }
                }
            }
        }
    }
}
int find(int t){
    if(t >= 81){
        return 1;
    }
    int p = t / 9,q = t % 9;
    for(int i = '1';i <= '9';i++){
        if(check(t,i)){
            in[p][q] = i;
            x[p]--;
            y[q]--;
            z[tt[p][q]]--;
            if(find(next())){
                return 1;
            }
            in[p][q]='.';
            x[p]++;
            y[q]++;
            z[tt[p][q]]++;
        }
    }
    return 0;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(1){
        scanf("%s",s);
        if(strcmp(s,"end") == 0) break;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        for(int st = 0;s[st];st++){
            in[st/9][st%9] = s[st];
            if(s[st]=='.'){
                x[st/9]++;
                y[st%9]++;
                z[tt[st/9][st%9]] ++;
            }
        }
        find(next());
        for(int st = 0;s[st];st++){
            printf("%c",in[st/9][st%9]);
        }
        printf("\n");
    }
    return 0;
}
