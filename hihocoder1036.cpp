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
#define maxnode 1000000+10
#define id(a) (a-'a')
char a[1000005];
struct tire{
	int flag;
	struct tire* ch[26];
	struct tire* f;
	tire(){
		flag = 0;
		memset(ch,0,sizeof(ch));
		f = 0;
	}
};
int insert(tire* root,char *s){
	tire* cur = root;
	for(int i = 0;s[i];i++){
		int c = id(s[i]);
		if(!cur->ch[c]){
			cur->ch[c] = new tire();
		}
		cur = cur->ch[c];
	}
	cur->flag = 1;
}
int build(tire* root){
	queue<tire*> que;
	root->f = root;
	for(int i = 0;i < 26;i++){
		if(!root->ch[i]){
			root->ch[i] = root;
		}
		else{
			root->ch[i]->f = root;
			que.push(root->ch[i]);
		}
	}
	tire* cur,*suf;
	while(!que.empty()){
		cur = que.front();
		que.pop();
		suf = cur->f;
		for(int i = 0;i < 26;i++){
			if(!cur->ch[i]){
				cur->ch[i] = suf->ch[i];
			}
			else{
				cur->ch[i]->f = suf->ch[i];
				que.push(cur->ch[i]);
			} 
		} 
	}
}
int query(tire* root,char *s){
	tire* cur = root;
	for(int i = 0;s[i];i++){
		int c = id(s[i]);
		cur = cur->ch[c];
		if(cur->flag){
			printf("YES\n");
			return 0;
		} 
	}
	printf("NO\n");
	return 0;
}
int main(){
	int n;
	tire* root = new tire();
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%s",a);
		insert(root,a);
	}
	build(root);
	scanf("%s",a);
	query(root,a);	
	return 0;
}

