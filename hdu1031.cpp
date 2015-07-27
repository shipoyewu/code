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
struct node{
	double x;
	int y;
};
node a[100000];
int b[100000];

int cmp1(node a,node b){
	return a.x > b.x;
}
int cmp2(int a,int b){
	return a > b;
}
int main(){
	int n,m,k;
	while(cin >> n >> m >> k){
		memset(a,0,sizeof(a));
		for(int i = 0;i < m;i++){
			a[i].y = i+1;
		}
		for(int j = 0; j < n;j++){
			for(int i = 0;i < m;i++){
				double x;
				scanf("%lf",&x);
				a[i].x += x;
			}
		}
	
		sort(a,a+m,cmp1);
//		for(int i = 0;i < m;i++){
//			cout << a[i].x << endl;
//		}
		for(int i = 0;i < k;i++){
			b[i] = a[i].y;
//			cout << a[i].y << endl;
		}
		sort(b,b+k,cmp2);
		for(int i = 0;i < k;i++){
			if(i != 0){
				printf(" ");
			}
			printf("%d",b[i]);
		}
		printf("\n");
	}
	return 0;
}

