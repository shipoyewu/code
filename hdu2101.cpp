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
	int x,y,z;
};
int vis[2][20][20];
int g[4][2] = {0,1,1,0,-1,0,0,-1};
int n,m,t;
char a[2][20][20];

int bfs(){
	node s;
	s.x = 0;
	s.y = 0;
	s.z = 0;
	queue<node> que;
	vis[0][0][0] = 0;
	que.push(s);
	while(!que.empty()){
		node u  =que.front();
		que.pop();
		for(int i = 0;i < 4;i++){
			node v;
			v.x = u.x + g[i][0];
			v.y = u.y + g[i][1];
			if(v.x < n && v.y < m && v.x >= 0 && v.y >= 0){
				if(a[u.z][v.x][v.y] == '#'){
					v.z = (u.z+1)%2;
				}
				else{
					v.z = u.z;				
				}
				if(vis[v.z][v.x][v.y] == -1&& a[v.z][v.x][v.y] != '*' && a[v.z][v.x][v.y] !='#'){
					vis[v.z][v.x][v.y] = vis[u.z][u.x][u.y] + 1;
					que.push(v);
					if(a[v.z][v.x][v.y] == 'P'){
						return vis[v.z][v.x][v.y];
					}
				}
				
			}
		}
	}
	return INF;
}
int main(){
	int c;
	cin >> c;
	while(c--){
		scanf("%d%d%d",&n,&m,&t);
		getchar();
		memset(vis,-1,sizeof(vis));
		for(int i = 0;i < 2;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < m;k++){
					a[i][j][k] = getchar();
				}
				getchar();
			}
			if(i == 0)
			getchar();
		}
		
		if(bfs() <= t){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}    
    return 0;
}

