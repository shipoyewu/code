#include <cstdio>
#include <iostream>


using namespace std;
long long int gcd(long long int a,long long int b){
	return (b == 0)?a: gcd(b,a%b);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long int lcm = 1;
		
		for(int i = 0;i < n;i++){
			long long int a;
			cin >> a;
			lcm = lcm/gcd(lcm,a)*a;
		}
		
		cout << lcm << endl;
	}
} 
