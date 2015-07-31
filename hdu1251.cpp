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
#define  MAXNODE 1000000
#define id(a) (a-'a')
struct trie{
	int ch[MAXNODE][26];
	int val[MAXNODE];
	int sz;
	int insert(char *s){
		int n = strlen(s);
		int u = 0;
		for(int i = 0;i < n;i++){
			int c = id(s[i]);
			if(!ch[u][c]){
				ch[u][c] = sz++; 
			}
			u = ch[u][c];
			val[u]++;
		}
		
	}
	int query(char *s){
		int n = strlen(s);
		int u = 0;
		for(int i = 0;i < n;i++){
			int c = id(s[i]);
			if(!ch[u][c]){
				return 0;
			}
			u = ch[u][c];
		}
		return val[u];
	}
};
trie a;
int main(){
	char s[105];
	memset(a.ch[0],0,sizeof(a.ch[0]));
	memset(a.val,0,sizeof(a.val));
	a.sz = 1;
	while(gets(s),s[0]!='\0'){
		a.insert(s);
	}    
	while(scanf("%s",s)!=EOF){
		cout << a.query(s) << endl;
	}
    return 0;
}

