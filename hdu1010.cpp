#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define INF 10000000
int n,m,t;

struct point{
	int x,y;
};
point p;
int vis[10][10];
int vs[10][10];

char a[10][10];
int v[4][2] = {0,1,1,0,-1,0,0,-1};
int fun(point s){
	queue<point> que;
	vs[s.x][s.y] =1;
	int cc[10][10];
	que.push(s);
	cc[s.x][s.y] = 0;
	while(!que.empty()){
		point u = que.front();
		que.pop();
		for(int i = 0;i < 4;i++){
			point tmp;
			tmp.x = v[i][0] + u.x;
			tmp.y = v[i][1] + u.y;
			if(tmp.x < n &&tmp.x >= 0 && tmp.y < m && tmp.y >= 0){
				if(vis[tmp.x][tmp.y] != 1 && vs[tmp.x][tmp.y] != 1){
					if(a[tmp.x][tmp.y] != 'X'){
						if(a[tmp.x][tmp.y] == 'D'){
							return cc[u.x][u.y]+1;
						}
						else{
							vs[tmp.x][tmp.y] = 1;
							cc[tmp.x][tmp.y] = cc[u.x][u.y]+1;
							que.push(tmp);
						}
					}
				}
			} 
		}			
	}
	return INF;
}
int dfs(point s,int x,int q){
	if(a[s.x][s.y] == 'D'){
		if(x == 0){
			return true;
		}
		else{
			return false;
		}
	}
	else if(x < 0){
		return false;
	}
	else if(x > q){
		return false;
	}else{
		memset(vs,0,sizeof(vs));
		
		int now = fun(s);
		if(x == now){
			return true;
		} 
		if(x < now){
			return false;
		}
		if((x-now)%2){
			return false;
		}
		int t = 0;
		for(int i = 0;i < 4;i++){
			point tmp;
			tmp.x = v[i][0] + s.x;
			tmp.y = v[i][1] + s.y;
			if(tmp.x < n &&tmp.x >= 0 &&tmp.y < m &&tmp.y >= 0){
				if(!vis[tmp.x][tmp.y]){
					if(a[tmp.x][tmp.y] != 'X'){
						vis[tmp.x][tmp.y] = 1;
						t |= dfs(tmp,x-1,q-1);
						vis[tmp.x][tmp.y] = 0;
						if(t){
							return true;
						}
					}
				}
			}
			
		}
		return t;
	}
}
int main(){
	//freopen("ou.txt","w",stdout);
	
	while(cin >> n >> m >> t,n||m||t){
		getchar();
		point s;
		int sum = 0;
		for(int i = 0;i< n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = getchar();
 				if(a[i][j] == 'S'){
 					s.x = i;
 					s.y = j;
 				}
 				if(a[i][j] == 'X'){
 					sum ++;
 				}
			}
 			getchar();
		}
	
		vis[s.x][s.y] = 1;
		
		if(dfs(s,t,n*m-sum-1)){
			printf("YES\n");    
		}
		else{
			printf("NO\n");
		}
		vis[s.x][s.y] = 0;
	}	
	return 0;
} 
