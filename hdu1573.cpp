#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long int a[100];
long long int b[100];

int gcd(int a,int b){
	return b == 0? a: gcd(b,a%b);
}
int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		scanf("%I64d%I64d",&n,&m);
		
		int ma = 1;
		
		for(int i = 0;i < m;i++){
			scanf("%d",&a[i]);
			ma = a[i]/gcd(ma,a[i])*ma;	
		}	
		for(int i = 0;i < m;i++){
			scanf("%d",&b[i]);
		}
		int x,c = 0;
		for(x = a[0]*c+b[0];x < ma && x <= n;c++,x += a[0]){
			int flag = 1;
			for(int i = 1 ;i < m;i++){
				if(x%a[i] != b[i]){
					flag = 0;	
				}
			}
			if(flag){
				break;
			}
		}
		if(x>= ma || x > n){
			cout << "0" << endl;
		}
		else{
			int ans = (n-x)/ma;
			if(x % ma){
				ans ++;
			}
			cout << ans << endl;		
		}
	}
	return 0;
}
