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
struct node{
	int x,y,i;
	bool operator < (const node& a)const{
		return y > a.y;
	}
};
node a[100005];
vector<node> vec[100005];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i].x);
		}
		for(int i = 0;i < n;i++){
			scanf("%d",&a[i].y);
			a[i].i = i+1; 
			vec[i].clear();
		}
		for(int i = 0;i < n;i++){
			vec[a[i].x].push_back(a[i]); 
		}
		int ans = 0;
		priority_queue<node,vector<node>,less<node> > que;
		queue<int> q;
		for(ans = 0;ans < n;ans++){
			int si = vec[ans].size();
			for(int j = 0;j < si;j++){
				que.push(vec[ans][j]);
			}
			if(que.empty()) break;
			node v = que.top();
			
			q.push(v.i);
			que.pop();
			while(!que.empty() && que.top().y <= (ans)){
				q.push(que.top().i);
				
				que.pop();				
			}
		}
		int flag = 0;
		printf("%d\n",ans);
		while(!q.empty()){
			if(flag == 0){
				flag = 1;
			}
			else{
				printf(" ");	
			}
			printf("%d",q.front());
			q.pop();
		}
		for(ans;ans<n;ans++){
			int si = vec[ans].size();
			for(int i = 0;i < si;i++){
				if(flag == 0){
					flag = 1;
				}
				else{
					printf(" ");
				}
				printf("%d",vec[ans][i].i);
			}
		}
		printf("\n");
	}
    return 0;
}

