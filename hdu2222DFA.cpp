#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define id(a) (a-'a')
const int maxnode=1000000+10;
int ch[maxnode][26];
int f[maxnode];
int val[maxnode];
int sz;
int insert(char *s){
	int u = 0;
	for(int i = 0;s[i];i++){
		int c = id(s[i]);
		if(!ch[u][c]){
			memset(ch[sz],0,sizeof(ch[sz]));
			val[sz] = 0;
			f[sz] = 0;
			ch[u][c] = sz++;
		}
		u = ch[u][c];
	}
	val[u] ++;
}
int find_fail(){
	int u = 0;
	queue<int> que;
	f[0]= 0;
	for(int i = 0;i < 26;i++){
		int u = ch[0][i];
		if(u){
			f[u] = 0;
			que.push(u);		
		}
	}
	while(!que.empty()){
		int r = que.front();
		que.pop();
		for(int i = 0;i < 26;i++){
			if(!ch[r][i]){
				ch[r][i] = ch[f[r]][i];
			}
			else{
				f[ch[r][i]] = ch[f[r]][i];
				que.push(ch[r][i]); 
			}
		}
	}
}
void query(char *s){
	int u = 0;
	int ans = 0;
	for(int i = 0;s[i];i++){
		u = ch[u][id(s[i])];
		int tmp = u;
		while(tmp){
			ans += val[tmp]	;
			if(ans > 0){
				printf("YES");
				return;
			}
			val[tmp] = 0;
			tmp = f[tmp];
		}
	}
	printf("NO\n");
	return ;
}
char s[1000005];
char a[100];
int main(){
	int n;
	cin >> n;
	sz = 1;
	memset(ch[0],0,sizeof(ch[0]));
	val[0]= 0;
	f[0] =0;
	for(int i = 0;i < n;i++){
		scanf("%s",a);
		insert(a);
	}
	find_fail();
	scanf("%s",s);
	query(s);
	return 0;
}
