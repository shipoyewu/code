#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define LL long long  
const int maxnode = 4000*1000+10;
int head[maxnode];
int next[maxnode];
int tot[maxnode];
int va[maxnode];
LL ans  = 0; 
int sz = 0;
int insert(char *s){
	int n = strlen(s);
	int u = 0;
	for(int i = 0;i <= n;i++){
		int flag = -1;
		for(int t = head[u];t;t =next[t]){
			if(va[t] == s[i]){
				ans += tot[t];
				flag = t;
			}
			ans+=tot[t]; 
		}
		if(flag == -1){
			next[sz] = head[u];
			flag = sz;
			va[flag] = s[i];
			tot[sz] = 0;
			head[sz] = 0;
			head[u] = sz++;
		}
		u = flag;
		tot[flag]++;   
	}
} 
char s[1005];
int main(){
	int n;
	int t = 1;
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout); 
	while(scanf("%d",&n)!=EOF){
		if(n == 0) break;
		ans = 0;
		sz = 1;
		head[0] = 0;
		next[0] = 0;
		tot[0] = 0;
		for(int i = 0;i < n;i++){
			scanf("%s",s);
			insert(s);
		}
		printf("Case %d: %lld\n",t++,ans);
	}	
}
