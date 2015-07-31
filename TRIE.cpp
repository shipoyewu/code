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
#define MAXNODE 1000
#define sigma_size 26
 
struct trie{
	int ch[MAXNODE][sigma_size];
	int val[MAXNODE];
	int sz;
	trie(){
		sz = 1;
		memset(ch[0],0,sizeof(ch[0])); 
	}
	int idx(char c){
		return c = c - 'a';
	}
	void insert(cahr *s,int v){
		int u = 0;
		int n = strlen(s);
		for(int i = 0;i < n;i++){
			int c = idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = v;
	} 
	int query(char* s){
		int u = 0 ;
		int n = strlen(s);
		for(int i = 0;i < n;i++){
			int c = idx(s[i]);
			if(!ch[u][c]){
				return false;
			}
			else{
				u = ch[u][c];
			}
		}
		return val[u];
	}
}; 
int main(){
    
    return 0;
}

