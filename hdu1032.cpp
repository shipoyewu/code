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
#define INF 0x4fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
LL fun(LL n){
	int t = 1;
	while(n != 1){
		if(n&1){
			n = 3*n+1;
		}
		else{
			n>>=1;
		}
		t++;
	}
	return t;
}
int main(){
	LL n,m;
	while(cin >> n >> m){
		LL max = -1;
		cout << n << " " << m << " ";
		if(n > m){
			swap(n,m);
		}
		for(LL i = n;i <= m;i++){
			LL t = fun(i);
			if(t > max){
				max = t;
			}
		}
		cout << max << endl;
	}
	return 0;
}

