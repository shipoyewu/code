#include <cstdio>
#include <iostream> 
#include <algorithm>
using namespace std;
int c[1005];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		c[i]  = 1;
		int max = 0;
		for(int j = 1;j <= n;j++){
			int x;
			cin >> x; 
			if(x > max){
				max = x;
				c[i] = j;				
			}
		}
	}
	
	sort(c,c+m);
	int win;
	int max = -1;
	
	for(int i = 1;i <= n;i++){
		int cc = upper_bound(c,c+m,i) - lower_bound(c,c+m,i);
		if(cc > max){
			max = cc;
			win = i;
		} 
	}
	cout << win  << endl;
	return 0;
} 
