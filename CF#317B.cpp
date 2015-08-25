#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
char op[100010];
int pre[100010];
int main(){
	int n,s;
	cin >> n >> s;
	memset(pre,0,sizeof(pre));
	for(int i = 0;i < n;i++){
		char ch[3];
		int x,y;
		scanf("%s%d%d",ch,&x,&y);
		op[x] = ch[0];
		pre[x] += y;
	}
	int d = s;
	stack<pair<int,int> > st;
	for(int i = 0;i < 100010 && d > 0;i++){
		if(op[i] == 'S'){
			st.push(make_pair(i,pre[i]));
			d --;
		}
	}	
	while(!st.empty()){
		pair<int,int> a = st.top();
		st.pop();
		printf("S %d %d\n",a.first,a.second);
	}
	for(int i = 100009;i >= 0 && s > 0;i--){
		if(op[i] == 'B'){
			printf("B %d %d\n",i,pre[i]);
			s --;
		}
	}
	
	return 0;
}
