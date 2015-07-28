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
int s[4*1000000+100];
int a[2*1000000];
int n;
int init(){
	int t = 1;
	while((1<<t) < n) t++;
	n = (1 << t);
	for(int i = 0;i < n;i++){
		s[i+n-1] = a[i];
	}
	for(int i = t-1;i >= 0;i--){
		for(int j = 0;j < (1<<i);j++){
			int k = (1<<i)-1+j;
			s[k] = min(s[2*k+1],s[2*k+2]);
		}
	}
}
int query(int q,int p,int k,int x,int y){
	if(x <= q && p <= y) return s[k];
	if(q >= y || p <= x) return INF; 
	int vl = query(q,(q+p)/2,2*k+1,x,y);
	int vr = query((q+p)/2,p,2*k+2,x,y);
	return min(vl,vr);
}
int change(int loc,int d){
	loc += n-1;
	s[loc] = d;
	while(loc > 0){
		loc = (loc-1)/2; 
		s[loc] = min(s[2*loc+1],s[2*loc+2]);
	}
}
int main(){
	cin >> n;
	memset(a,0x3f,sizeof(a));
	memset(s,0x3f,sizeof(s));
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	init();
	int m;
	scanf("%d",&m);
	for(int i =  0;i < m;i++){
		int x,y;
		scanf("%d%d",&x ,&y);
		printf("%d\n",query(0,n,0,x-1,y));
	}
	return 0;
}

