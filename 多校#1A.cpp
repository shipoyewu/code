#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;
#define INF 1000000007
vector<int> vec[10005];
int n;

int fun(){
	for(int i = 1;i <= 10000;i++){
		int d = floor(sqrt(i)+0.5);
		for(int j = 1;j <= d;j++){
			if(i%j == 0){
				vec[i].push_back(j);
				vec[i].push_back(i/j);
			}
		}
	}
}
int l[100005];
int r[100005];
int a[100005];

int main(){
	fun();
	while(cin >> n){
		for(int i = 1 ;i <= n;i++){
			scanf("%d",&a[i]);
		}
		map<int,int> ma;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(int i = 1;i <= n;i++){
			int si = vec[a[i]].size();
			int q = 0;
			for(int j = 0;j < si;j++){
				int v = vec[a[i]][j];
				if(ma.find(v)!=ma.end()){
					q = max(q,ma[v]);	
				}
			}
			l[i] = q;
			ma[a[i]] = i;
		}
		ma.clear();
		for(int i = n ;i >= 1;i--){
			int si = vec[a[i]].size();
			int q = n+1;
			for(int j = 0;j < si;j++){
				int v = vec[a[i]][j];
				if(ma.find(v)!= ma.end()){
					q = min(q,ma[v]);
				}
			}
			r[i] = q;
			ma[a[i]] = i;
		}
		long long ans = 0;
		
 		for(int i = 1;i <= n;i++){
			long long int xl = i - l[i];
			long long int xr = r[i] - i;
			
			ans += (xl*xr)%INF;
			ans %= INF;	
		}
		cout << ans<< endl;
	}
	return 0;
}
