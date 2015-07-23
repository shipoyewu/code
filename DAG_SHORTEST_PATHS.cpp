#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
#define INF 1000000
int d[100];  
queue<int> que; 
vector<int> vec[1000];
vector<int> w[1000];
int n,m;
int F[1000];

int topu_rudu(){  
    stack<int> st;  
    for(int i = 0;i < n;i++){  
        d[i] = vec[i].size();  
        if(d[i] == 0){  
            st.push(i);  
        }  
    }  
    while(!st.empty()){  
        int u = st.top();  
        st.pop();  
        que.push(u);      
        int si = vec[u].size();  
        for(int i = 0;i < si;i++){  
            int v = vec[u][i];  
            d[v]--;  
            if(d[v] == 0){  
                st.push(v);  
            }  
        }  
    }  
}

int DAG_SHORTEST_PATHS(){
	topu_rudu();
	for(int i = 0;i < n;i++){
		d[i] = INF;
		F[i] = -1; 
	}
	while(!que.empty()){
		int u = que.front();
		que.pop();
		int si = vec[u].size();
		for(int i = 0;i < si;i++){
			int v = vec[u][i];
			if(d[v] > d[u] + w[u][i]){
				d[v] = d[u] + w[u][i];
				F[v] = u;
			}
		}
	}
}
int main(){
	while(cin >> n >> m){
		for(int i = 0;i < m;i++){
			int x,y,v;
			
			cin >> x >> y>> v;
			w[x].push_back(y);
			vec[x].push_back(v);
		}
		DAG_SHORTEST_PATHS();
	} 
	return 0;
}
