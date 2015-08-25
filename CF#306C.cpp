#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#include <map>
#include <vector>
using namespace std;
#define INF 0x2fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
char a[1000];
int in[1000];
int ans[1000];

int main(){
	scanf("%s",a);
	int len = strlen(a);
	int m = len-1;
	for(int i = 0;i < len;i++){
		in[m--] = a[i]-'0';
	}
	int flag=0;
	int t = 0;
	in[len] = 0;
	in[len+1] = 0;
	for(int i = 0;i < len;i++){
		for(int j = i+1;j <= len;j++){
			for(int k = j+1;k <= len+1;k++){
				if((in[i]+2*in[j]+4*in[k])%8==0){
					ans[0] = in[i];
					flag = 1;
					if(j == len || k == len+1){
						t = 1;
						break;
					}
					ans[0] = in[i];
					ans[1] = in[j];
					ans[2] = in[k];
					t = 3;
					k++;
					while(k < len){
						ans[t] = in[k++];
					}
					break;
				}
			} 
			if(flag){
				break;
			} 
		}
		if(flag){
			break;
		} 
	}
	if(flag){
		reverse(ans,ans+t);
		printf("YES\n");
		int i = 0;
		while(i < t && ans[i] == 0){
			i++; 
		}
		if(i == t){
			i --;
		} 
		for(;i < t;i++){
			printf("%d",ans[i]);
		}cout << endl;
	}
	else{
		printf("NO\n");
	}
	return 0;
}

