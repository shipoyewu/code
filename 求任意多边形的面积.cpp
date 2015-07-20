#define LL long long
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
typedef struct{
	int x,y;
} point;

double areafun(point a[],int n){
	int i,j;
	double area = 0;
	for(i = 0;i < n;i++){
		j  = (i+1)%n;

		area += a[i].x * a[j].y;
		area -= a[i].y * a[j].x;
	}
	area /= 2.0;
	return fabs(area);
}
int main(){
	int n;
	point a[105];

	while(cin >> n,n){
		for(int i = 0;i < n;i++){
			cin >> a[i].x >> a[i].y;
		}
		printf("%.1lf\n",areafun(a,n));
	}
	return 0;
}
