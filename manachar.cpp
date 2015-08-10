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
char a[100005];
char b[20005];
int  p[20005];
int suf[10005];
int pre[10005];
int pa[20005];

int lena,lenb;
int newstring(){
	b[0] = '$';
	b[1] = '#';
	int j = 2;
	for(int i = 0;i < lena;i++){
		b[j] = a[i];
		b[++j] = '#';
		++j;	
	}
	b[j] = '\0';
} 
int manachar(){
	int id = 0;
	int maxd = 1;
	for(int i = 1;i < lenb;i++){
		if(maxd > i){
			p[i] = min(p[2*id-i],maxd-i);
		}else{
			p[i] = 1;
		}
		while(b[p[i]+i] == b[i-p[i]]) 
			p[i]++;
		if(p[i]+i > maxd){
			maxd = p[i]+i;
			id = i;
		}
	}
}
void fun(){
	for(int i = 0;i < lena;i++){
		for(int j = 0;j < pa[i];j++){
			if(pre[i+j]&suf[i-j]){
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
}
int main(){
	int t;
	cin >> t;
	while(t--){
		scanf("%s",a);
		lena = strlen(a);
		if(lena < 3){
			printf("No\n");
			continue;
		}
		lenb = 2*lena+1;
		newstring();
		manachar();
		for(int i = 0;i < lena;i++){
			pa[i] = (p[2*i+2])/2;
		}
		memset(suf,0,sizeof(suf));
		memset(pre,0,sizeof(pre));
		for(int i = 0,j = lena-1;i < lena;i++){
			if(i+1-pa[i]==0){
				suf[i+pa[i]] = 1;
			}
			if(j+pa[j]==lena){
				pre[j-pa[j]] = 1;
			}
		}
		fun();
	}	
	return 0;
}

