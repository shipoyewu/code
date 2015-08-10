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
char a[110005];
char b[220010];
int p[220010];
int manachar() {
	int lb = 0;
	b[lb++] = '@';
	b[lb++] = '#';
	for(int  i = 0;a[i];i++){
		b[lb++] = a[i];
		b[lb++] = '#';
	}
	b[lb] = '\0';
	int ans =  1;
	int maxd = 0;
	int id = 0;
	for(int i = 0;i < lb;i++){
		if(maxd==i) p[i] = 1;
		else p[i] = min(p[2*id-i],maxd-i);
		while(b[p[i]+i]==b[i-p[i]])p[i]++;
		if(p[i]+i > maxd){
			maxd = p[i]+i;
			id = i;
		}
		if(ans < p[i]){
			ans = p[i];
		}
	}
	printf("%d\n",ans-1);
}
int main(){
	while(scanf("%s",a)!=EOF){
		manachar();
	}
	return 0;
}

