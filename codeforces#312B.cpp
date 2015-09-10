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
int a[1000005];
int l[1000005];
int r[1000005];
int d[1000005];
int main(){
	int n;
	cin >> n;
	map<int,int> ma;
	int cnt = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(ma[a[i]] ==0){
			ma[a[i]] = cnt++;
			l[ma[a[i]]] = i;
		}
		d[ma[a[i]]]++;
		r[ma[a[i]]] = i;
	}
	int qu = 0;
	int ans = 0;

	for(int i = 0;i < cnt;i++){
		if(d[i] > qu){
			qu = d[i];
			ans = i;
		}
		else if(d[i] == qu){
			if(r[i]-l[i]+1 < r[ans]-l[ans]+1){
				ans = i;
			}
		}
	}
	cout << l[ans] << " " << r[ans] << endl;
	return 0;
}

