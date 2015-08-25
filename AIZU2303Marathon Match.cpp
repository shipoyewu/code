#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
#define LL long long
double p[200];
int t[200];
int v[200];
LL C[100][100];
double dp[105][55];

int main(){
    int n,m,l;
    cin >>  n >> m >> l;
    for(int i = 0;i < n;i++){
        int x,tt,vv;
        scanf("%d%d%d",&x,&tt,&vv);
        p[i] = x / 100.0,t[i] = tt,v[i] = vv;
    }

    for(int i = 0;i <= 50;i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1;j < i;j++){
            C[i][j] = C[i-1][j]+C[i-1][j-1];
            //cout<<C[i][j] << endl;
        }
    }
    for(int i = 0;i < n;i++){
        dp[i][m+1] = 0;
        for(int j = m;j >= 0;j--){ //休息>j次
            dp[i][j] = dp[i][j+1] + C[m][j]*pow(p[i],j)*pow(1-p[i],m-j);
            //cout << dp[i][j] << endl;
        }
    }

    for(int i = 0;i < n;i++){
        double ans = 0;
        if(v[i] != 0){
            for(int j = 0;j <= m;j++){
                double ut = l*1.0/v[i] + j*t[i];
                double pa = C[m][j]*pow(p[i],j)*pow(1-p[i],m-j);
                for(int k = 0;k < n;k++){//赢k个人的概率
                    if(k != i){
                        if(v[k] == 0){
                            pa *= 1;
                            continue;
                        }
                        int tim;
                        if(t[k] == 0){
                            if(l*1.0/v[k] <= ut){
                                pa *= 0;
                            }
                            else{
                                pa *= 1;
                            }
                            continue;
                        }
                        tim = floor((ut-(l*1.0/v[k]))/t[k]);
                        while((tim*t[k]+l*1.0/v[k]) <= ut) tim++;
                        if(tim > m){
                            pa *= 0;
                        }
                        else if(tim < 0){
                            pa *= 1;
                        }else{
                            pa *= dp[k][tim];
                        }

                    }
                }
                //printf("%lf\n",pa);
                ans += pa;
            }
        }
        printf("%.8f\n",ans);
    }
    return 0;
}

