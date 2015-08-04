#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int len;
char p[200005];
int nex[200005];
int sum[200005];

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> len;
		scanf("%s",p);
		nex[0] = 1;
		int k = 0;
		memset(sum,0,sizeof(sum));
		sum[0] = 1;
		
		for(int i = 1;i < len;i++){
			while(k > 0 && p[i] != p[k]){
				k = nex[k];
			}
			sum[i] = (sum[i-1]+1)%10007;
			if(p[k] == p[i]){
				sum[i] += 1;
				sum[i]%=10007;
				k += 1;
			}
			nex[i] = k;
		}
		cout << sum[len-1]%10007<< endl;
	}	
} 
