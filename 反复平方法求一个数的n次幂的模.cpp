#include <cstdio>
#include <stack> 
#include <iostream>
#include <queue>
using namespace std;
//º∆À„a^b%n 
int fun(int a,int b,int n){
	int c = 0;
	int d = 1;
	stack<int> st;
	while(b){
		st.push(b&1);
		b >>= 1; 
	};
	while(!st.empty()){
		int t = st.top();
		st.pop();
		c = 2*c;
		d = (d*d)%n;
		if(t){
			c += 1;
			d = (d * a)%n;
		}
	}aa
	return d;
}
int main(){
	int a,b,n;
	cin  >> a >> b >> n;
	cout << fun(a,b,n) << endl;
	return 0;
}
