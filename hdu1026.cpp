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
#define INF 0x7fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
int n,m;
struct node {
	int x,y,t;
	bool operator < (const node& a)const{
		return t > a.t;
	}
};
node pre[105][105];
int vis[105][105];
char a[105][105];
int ti[105][105];
int ve[][2] = {-1,0,0,-1,1,0,0,1};
int print_path(int x,int y,int s){
	node u = pre[x][y];
	printf("%ds:(%d,%d)->(%d,%d)\n",s,x,y,u.x,u.y);
	if(a[u.x][u.y]<='9' && a[u.x][u.y] >= '0'){
		for(int i = 1;i <= (a[u.x][u.y] - '0');i++){
			printf("%ds:FIGHT AT (%d,%d)\n",s+i,u.x,u.y);
		}
		s += (a[u.x][u.y] - '0');
	}
	if(!(u.x == n-1&&u.y== m-1))
		print_path(u.x,u.y,s+1);
}
void solve(){
	priority_queue<node,vector<node>,less<node> > que;
	node s;
	s.x = n-1;
	s.y = m-1;
	s.t = 0;
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	memset(ti,0,sizeof(ti));
	vis[n-1][m-1] = 1;
	int flag = 0;
	que.push(s);
	while(!que.empty()){
		node u = que.top();
		que.pop();
		for(int i = 0;i < 4;i++){
			node v;
			v.x = u.x + ve[i][0];
			v.y = u.y + ve[i][1];
			if(v.x < n &&v.x >= 0 && v.y < m && v.y >= 0){
				if(!vis[v.x][v.y] && a[v.x][v.y] != 'X'){
					int c = 0;
					if(a[v.x][v.y] == '.'){
						c = 1;
					}
					else{
						c = a[v.x][v.y] - '0'+1;
					}
					vis[v.x][v.y] = 1;
					pre[v.x][v.y] = u;
					ti[v.x][v.y] = ti[u.x][u.y] + c;
					v.t = ti[v.x][v.y];
					if(v.x == 0 && v.y == 0){
						flag = 1;
						break;
					}
					que.push(v);
				}
			}
		}
	}
	
	if(flag){
		if(a[n-1][m-1]<='9' && a[n-1][m-1]>='0')
			ti[0][0] += a[n-1][m-1]-'0';
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",ti[0][0]);
		print_path(0,0,1);
	}
	else{
		printf("God please help our poor hero.\n");
	}
	printf("FINISH\n");
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		getchar();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = getchar();
			}
			getchar();
		}
		solve();
	}
	return 0;
}

