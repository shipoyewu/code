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
#define id(a) ((a)-'a')
const int maxnode = 10000*50+10;
int ch[maxnode][26];
int val[maxnode];
int sz = 0;
int insert(char *s){
	int len =strlen(s);
	int u = 0;
	for(int i = 0;i < len;i++){
		int c = id(s[i]);
		if(!ch[u][c]){
			memset(ch[sz],0,sizeof(ch[sz]));
			val[sz] = 0;
			ch[u][c] = sz++;
		}
		u = ch[u][c];			
	}
	val[u] ++;
}

int query(char *s){
	int ans = 0;
	for(int i = 0;s[i];i++){
		int c = id(s[i]);
		int u = 0;
		int j = 0;
		while(ch[u][c]){
			if(val[ch[u][c]]){
				ans += val[ch[u][c]];
				val[ch[u][c]] = 0;
			}
			u = ch[u][c];
			j ++;
			c = id(s[i+j]);
		}
	}
	printf("%d\n",ans);
}
char s[1000005]; 
int main(){
    int t;
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
    	int n;
    	scanf("%d",&n);
    	char a[100];
    	memset(ch[0],0,sizeof(ch[0]));
    	val[0]= 0;
    	sz = 1;
		for(int i = 0;i < n;i++){
    		scanf("%s",a);
    		insert(a);
    	}
    	scanf("%s",s);
    	query(s);
    }
    return 0;
}

