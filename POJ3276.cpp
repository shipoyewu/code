#include <cstdio>
#include <iostream> 
#include <cstring>

using namespace std;
int n;
int a[5005][2];
int flag[5005];
int fun(int x){
	int sum  = 0;
	int res = 0;
	
	memset(flag,0,sizeof(flag));
	for(int i = 0;i+x <= n;i++){
		if(sum%2 == 0 && a[i][0] == 'B' || sum % 2 == 1 && a[i][0] == 'F'){
			flag[i] = 1;
			res++;
		}
		else{
			flag[i] = 0;
		}
		sum += flag[i];
		if(i+1-x >= 0){
			 sum -= flag[i-x+1];
		}
	}
	for(int i = n-x+1;i < n;i++){
		if(a[i][0] == 'B' && sum % 2 == 0 || sum % 2 == 1&& a[i][0] == 'F'){
			return -1;
		}
		if(i-x+1 >= 0){
			sum -= flag[i-x+1];
		}
	}
	return res;	
}
int main(){
	while(cin >> n){
		for(int i = 0;i < n;i++){
			scanf("%s",a[i]);
		}
		int K = 1;
		int M = n;
		for(int i = 1;i <= n;i++){
			int m = fun(i);
			if(m >= 0&&M > m){
				M = m;
				K = i;
			}
		}
		printf("%d %d\n",K,M);
	}
	return 0;
}
