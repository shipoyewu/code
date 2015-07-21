#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int ans[100];
int vis[100];
int n;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43};
set<int> se;
void fun(int y){
	if(n == y){
		if(se.find(ans[n-1]+ans[0])!=se.end()){
			for(int i = 0;i < n;i++){
				if(i != 0){
					putchar(' ');
				}
				printf("%d",ans[i]); 			
			}
			putchar('\n');
		}
	}
	else{
		for(int i = 2 ;i <= n;i++){
			if(!vis[i] && se.find(ans[y-1]+i)!=se.end()){
				vis[i] = 1;
				ans[y] = i;
				fun(y+1);
				vis[i] = 0;
			}
		}				
	}
}
int main(){
	int t = 1;
	for(int i = 0;i < 15;i++){
			se.insert(prime[i]);
	}
	while(cin >> n){
		printf("Case %d:\n",t++);
		memset(vis,0,sizeof(vis));
		ans[0] = 1;
		fun(1);
		cout<< endl; 
	}
	return 0;
	 
} 
