#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int a[3][2];
int main(){
	for(int i = 0;i < 3;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	int flag = 0;
	for(int i = 0;i < 2;i++){
		int x = a[1][i] + a[2][i];
		int y = max(a[1][1-i],a[2][1-i]);
		if(x <= a[0][0] && y <= a[0][1] || x <= a[0][1]  && y <=a[0][0]){
			flag = 1;
		}
		x = a[2][1-i] + a[1][i];
		y = max(a[2][i],a[1][1-i]);
		if(x <= a[0][0] && y <= a[0][1] || x <= a[0][1]  && y <=a[0][0]){
			flag = 1;
		}			
	}
	if(flag){
		cout <<"YES" <<endl;
	}
	else{
		cout << "NO" << endl;
	}
}
