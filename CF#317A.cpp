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
int a[100005];
int b[100005];


int main(){
	int na,nb;
	cin >> na >>nb;
	int k,m;
	cin >> k >> m;
	for(int i = 0;i < na;i++){
		scanf("%d",&a[i]);
	} 
	
	for(int i = 0;i < nb;i++){
		scanf("%d",&b[i]);
	}
	if(a[k-1] < b[nb-m]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
    return 0;
}

