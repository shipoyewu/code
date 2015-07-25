#include <cstdio>
#include <iostream>

using namespace std;
int gcd(int n,int m){
	return m == 0?n:gcd(m,n%m);
}
int main(){
	int n,m;
	while(cin >> n >> m){
		if(gcd(n,m)==1){
			printf("%10d%10d    Good Choice\n\n",n,m);
		}
		else{
			printf("%10d%10d    Bad Choice\n\n",n,m);
		}
	}
	return 0;
} 
