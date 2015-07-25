#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
char str1[10000];
char str2[10000];


int main(){
	int n;
	while(scanf("%d%s%s",&n,str1,str2)!=EOF){
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		stack<int> st;
		queue<int> que;
		
		int j = 0;
		for(int i = 0;i < len2;i++){
			while((st.empty() || st.top() != str2[i]) && j < len1){
				st.push(str1[j++]);
				que.push(1);
			}
			int q;
			
			if(j <= len1 && (q = st.top()) == str2[i]){
				st.pop();
				que.push(2);	
			}
		}
		if(!st.empty() || j < len1){
			cout << "No." << endl;
		}
		else{
			cout << "Yes."<< endl;
			while(!que.empty()){
				int u = que.front();
				que.pop();
				if(u==1){
					cout << "in"<< endl;
				}
				else{
					cout << "out" << endl;
				}
			}
		}
		cout << "FINISH" << endl;
	}
	return 0;
}


