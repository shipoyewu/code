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
#define id(a) ((a-'a'))
char s[300005];
int sz;
const int maxnode = 4000*100+100;
int ch[maxnode][26];
int val[maxnode];
int dp[300005];
void insert(char *s){
	int n = strlen(s);
	int u = 0;
	for(int i = 0;i < n;i++){
		int c = id(s[i]);
		if(!ch[u][c]){
			memset(ch[sz],0,sizeof(sz));
//			val[sz] = 0;
			ch[u][c] = sz ++;
		}
		u = ch[u][c];
	}
	val[u] = 1;
}
int query(int loc,int c){
	int u  = 0;
	int n = loc + c;
	for(int i = loc;i <= n;i++){
		int c = id(s[i]);
		if(!ch[u][c]){
			return false; 
		}
		u = ch[u][c];
	}
	return val[u];
}
int main(){
	int cc = 1;
    while(scanf("%s",s)!=EOF){
    	int t;
    	int len = strlen(s);
    	memset(ch[0],0,sizeof(ch[0]));
    	memset(val,0,sizeof(val));
    	memset(ch,0,sizeof(ch));
    	memset(dp,0,sizeof(dp));
    	sz = 1;
		scanf("%d",&t);
		char a[200];
		while(t--){
			scanf("%s",a);
			insert(a);
		}
		dp[len] = 1;
		for(int i = len - 1;i >= 0;i--){
			for(int j = 0;j < 100 && i+j < len;j++){
				if(query(i,j)){
					dp[i] += dp[i+j+1];
					dp[i]%=20071027;
				}
			}
		} 
		printf("Case %d: %d\n",cc++,dp[0]);
    }
    return 0;
}

