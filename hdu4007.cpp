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

struct node{
	LL x,y;
	bool operator <(const node & a)const{
		return x < a.x;
	} 
};
node a[10005];
LL b[10005];

int main(){
	LL n,r;
	while(cin >> n >> r){
		for(int i = 0 ;i < n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		sort(a,a+n);
		int ccn = 0;
		for(int i = 0;i < n;i++){
			int cnt = 0;
			for(int j = i;j < n;j++){
				if(a[j].x <= a[i].x + r){
					b[cnt++] = a[j].y;		
				}
			}
			sort(b,b+cnt);
			int l = 0,c = 0;
			while(l < cnt){
				while(b[c] <= b[l] + r && c < cnt){
					if(c-l+1 > ccn){
						ccn = c-l+1;
					}
					c++;				
				} 
				l++;
			}
		}
		cout << ccn << endl;
	}
    return 0;
}

