#include <cstdio>
#include <iostream>
#include <queue>
#include <set> 
#include <map>
using namespace std;

int n,k;
int a[100005];


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n ;i++){
			scanf("%d",&a[i]);
		}
		int l = 1;
		int r = 1;
		long long int sum = 0;
		priority_queue<int,vector<int>,less<int> > ma;
		priority_queue<int,vector<int>,greater<int> > mi;
		map<int,int> mp;
		mp[a[l]] = 1;
		ma.push(a[l]);
		mi.push(a[l]);
		int maxa = a[l];
		int mina = a[l];
		long long int x;
		while(l <= n && r <= n ){
			while(maxa - mina < k && r <= n){
				r ++;
				if(mp.find(a[r])!=mp.end()){
					mp[a[r]]++;
				}
				else{
					mp[a[r]] = 1;
				}
				ma.push(a[r]);
				mi.push(a[r]);
				mina = mi.top();
				maxa = ma.top();
				
			};
			x = r-l;
			sum += x*(x+1)/2;
			do{
				mp[a[l]] --;
				while(mp[ma.top()]==0){
					ma.pop();
				}
				while(mp[mi.top()]==0){
					mi.pop();
				}
				maxa = ma.top();
				mina = mi.top();			
				l++;
			}while(maxa - mina >= k && l <= r);
			x = r - l;
			sum -= x*(x+1)/2;
		}
		sum += x*(x+1)/2; 
		cout << sum << endl;
	} 
	return 0;
} 
