#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int pre[209];
int ans[209];
int tmp[209];
int main(){
	int sq= (int)sqrt(209.0);
	for(int i = 0;i <= 200;i+=2){
		pre[i] = 1;
		ans[i] = 1;
	}
	for(int i = 3;i <= 200;i ++){ 
		if(!pre[i]){
			memset(tmp,0,sizeof(tmp));
			for(int j = 0;j <= 200;j += i){
				pre[j] = 1;
				for(int k = 0;k+j <=200;k++){
					tmp[k+j] += ans[k]; 
				}
			}
			for(int i = 0;i <= 200;i++){
				ans[i] = tmp[i];
			}
		}
	}
	int n;
	while(cin >> n){
		printf("%d\n",ans[n]);
	} 
	return 0;
}

