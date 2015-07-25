#include <cstdio>
#include <iostream>

using namespace std;
int main(){
	int t;
	cin >> t;
	for(int k = 1;k <= t;k++){
		int n,m;
		int s = 1;
		while(cin >> n >> m,n || m){
			
			int cc = 0;
			for(int i = 1;i < n;i++){
				for(int j = i+1 ; j < n;j++){
					int x = i*i+j*j + m;
					if(x%(i*j)==0){
						cc++;
					}
				}
			}
			printf("Case %d: ",s++);
			cout << cc << endl;
		}
		if(k!=t){
			cout << endl;
		}
	}
	return 0;
} 
