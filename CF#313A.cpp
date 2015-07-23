#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;
int a[1005];

int main(){
	int  n;
	cin >> n;
	for(int i  = 0;i < n;i++){
		scanf("%d",&a[i]);		
	}	
	sort(a,a+n);
	if(a[0] == 1){
		cout << "-1" << endl;
	}
	else{
		cout << 1 << endl;
	}
	return 0;
} 
