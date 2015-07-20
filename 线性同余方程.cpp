#include <cstdio>
#include <iostream>
using namespace std;
int efun(int a,int b,int &x,int &y){
	if( b == 0){
		x = 1;
		y = 0;
		return a;
	}
	else{
		int d = efun(b,a%b,x,y);
		int t = x;
		x = y;
		y = t - a/b * y;
		return d; 
	}
}
//ax=b(mod n)
void fun(int a,int b,int n){
	int x,y;
	int d = efun(a,n,x,y);
	if(b % d == 0){
		int x0 = x*(b/d) % n;
		for(int i = 0;i < d;i ++){
			printf("%d\n",(x0+i*(n/d)+n)%n);
		}
	}else{
		printf("NO\n");
	}
}
int main() {
	int a,b,n;
	cin >> a >> b >> n;
	fun(a,b,n);
	return 0;
}
