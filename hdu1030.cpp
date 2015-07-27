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
#define INF 0x7fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
#define MAXN  1000000000
LL n,m;
int main(){
	int t = 0;
	while(cin >> n >> m){
		if(n>m)
			swap(n,m);
		int cenn  =ceil(sqrt(n));
		int cenm = ceil(sqrt(m));
		int lev = cenm - cenn;
		int lef = abs( (cenm -( m - (cenm-1)*(cenm-1))/2)- (cenn - (n- (cenn-1)*(cenn-1))/2));
		int righ =abs(cenm-(cenm*cenm-m+1)/2-(cenn-(cenn*cenn-n+1)/2));
		cout << lev + lef + righ << endl;
	}
	return 0;
}

