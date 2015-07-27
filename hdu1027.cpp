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
int a[1005];

int main(){
	int n,m;
	while(cin >> n >> m){
		for(int i = 1;i <= n;i++){
			a[i-1] = i;
		}
		m --;
		while(m--){
			next_permutation(a,a+n);
		}
		for(int i = 0;i < n;i++){
			if(i!=0)putchar(' ');
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}

