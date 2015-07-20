#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 100000000
int n;
struct point{
	double x,y;
	bool operator < (const point & a)const{
		if(a.x == x){
			return y  < a.y;
		}
		else{
			return x < a.x;
		}
	}
};
int tmp[100005];
point p[100005];

int cmp(int a,int b){
	return p[a].y < p[b].y;
}
double dfun(point& a,point& b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)* (a.y-b.y);
}
double close_pair(int l,int r){
	if(l >= r){
		return INF;
	}else if(l == r - 1){
		return dfun(p[l],p[r]);
	}
	else{
		int mid = l+(r-l)/2;
		double d1 = close_pair(l,mid);
		double d2 = close_pair(mid+1,r);
		double d = min(d1,d2);
		int k = 0;
		for(int i = l;i <= r ;i++){
			if(dfun(p[i],p[mid]) < d){
				tmp[k++] = i; 
			}
		}
		sort(tmp,tmp+k,cmp);
		for(int i = 0;i < k;i++){
			for(int j = i+1;j < k;j++){
				if(dfun(p[tmp[i]],p[tmp[j]]) < d){
					d = dfun(p[tmp[i]],p[tmp[j]]);
				}
			}
		}
		return d;
	}
}
int main(){
	while(cin >> n,n){
		for(int i = 0;i < n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		sort(p,p+n);
		printf("%.2f\n",sqrt(close_pair(0,n-1))/2);
	}	
	return 0;
} 
