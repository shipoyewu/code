#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;
#define INF 0x2fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
double q;
int n;
double val[100][26];
int v[100];
int dp[3000050];
int flag[100];

int main(){
	while(scanf("%lf %d",&q,&n),n){
		int m;
		memset(val,0,sizeof(val));
		for(int i = 0;i < n;i++){
			scanf("%d",&m);
			for(int j = 0;j < m;j++){
				char ch;
				double v;
				scanf(" %c:%lf",&ch,&v);
				val[i][ch-'A'] += v;
			}
		}
		memset(flag,0,sizeof(flag));
		for(int i = 0;i < n;i++){
			double sum = 0;
			for(int j = 0;j < 26;j++){
				if(val[i][j] > 600){
					flag[i] = 1;					
				}
				if(j >= 3 && val[i][j]) flag[i] = 1;
				sum += val[i][j];
			}
			if(sum > 1000){
				flag[i]= 1;
			}
		}
		int g = 1;
		int tt= 0;
		for(int i = 0;i < n;i++){
			if(!flag[i]){
				double sum = 0;
				for(int j = 0;j < 3;j++){
					sum += val[i][j];
				}
				v[g] = sum*100;
				tt += v[g++];		
			}
		}
		memset(dp,0,sizeof(dp));
		int cc = min(tt,(int)(q*100));
		for(int i = 1;i < g;i++){
			for(int j = cc;j >= v[i];j--){
				dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
			}
		}
		printf("%.2lf\n",dp[cc]/100.0);
	}
	return 0;
	
}

