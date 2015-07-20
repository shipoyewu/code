#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
int fun(int a,int b){
//	int c = 0;
	int d = 1;
	stack<int> st;
	while(b){
		st.push(b & 1);
		b >>= 1l;	
	}
	while(!st.empty()){
		int t = st.top();
		st.pop();
//		c <<= 1;
		d = d*d %1000;
		if(t == 1){
//			c ++;
			d = (d*a)%1000;
		}
	}
	return d;
}
int main(){
	int a,b;
	while(cin >> a >> b,a||b){
		cout << fun(a,b) << endl;
	}
	return 0;
}
