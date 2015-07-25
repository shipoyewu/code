#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int tar;
char a[100];
int pw[29][10];
int len;
int ans[100];
char s[100];
int tet[] = {0,'G'-'A'+1,'H'-'A'+1,'O'-'A'+1,'S'-'A'+1,'T'-'A'+1};
int cmp(int x,int y){
	return y < x;
}
int fun(int cur){
	if(cur == 5){
		int flag = 0;
		for(int i = 1;i <= 5;i++){
			if(ans[i] != tet[i]){
				flag =1;
			}
		}
		if(pw[ans[1]][1]-pw[ans[2]][2]+pw[ans[3]][3]-pw[ans[4]][4]+pw[ans[5]][5] == tar){
		
			for(int i = 1;i <= 5;i++){
				putchar(ans[i]+'A'-1);
			}putchar('\n');
			return true;
		}
		return false;
	}
	for(int i = 0;i < len;i++){
		int flag = 0;
		for(int j = 1;j <= cur;j++){
			if(ans[j] == a[i]){
				flag = 1;
			}
		}
		if(flag)continue;
		ans[cur+1] = a[i];
		if(fun(cur+1)){
			return true;
		}
		
	}
	return false;
}
int main(){
	for(int i = 1;i <= 26;i++){
		pw[i][1] = i;
		for(int j = 2;j <= 5;j++){
			pw[i][j] = pw[i][j-1] * i;
		}
	}
	while(scanf("%d%s",&tar,s),!(tar == 0&&strcmp(s,"END")==0)){
		len = strlen(s);
		for(int i = 0;i < len;i++){
			a[i] = s[i] - 'A' + 1;
		}
		sort(a,a+len,cmp);
		if(!fun(0)){
			printf("no solution\n");
		}
		
	}
	return 0;	
}
