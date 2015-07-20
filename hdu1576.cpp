#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t --){
		long long int n,b;
		int i;
		cin >> n >> b;
		for(i = 1;i <= 9973;i++){
			if(i * b % 9973 == 1){
				break;
			}
		}
		cout << n * i % 9973 << endl;
	}
	return 0;
} 
