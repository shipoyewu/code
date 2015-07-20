#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#define INF 10000000
using namespace  std;
int flow[405][405];
int cap[405][405];

int fun(int s,int t,int n){
	memset(flow,0,sizeof(flow));
	int a[405] = {0};
	int p[405];
	a[s] = INF;//开始的时候从中出去的流最大 
	queue<int> q;	
	int f = 0;
	while(1){
		memset(a,0,sizeof(a));//a[i] 代表从s到i的最小残余网络的流量 
		a[s] = INF;//明显从s到s的流量开始的时候是无穷大的 
		q.push(s);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int v = 0;v < n;v++){
				//当前的s到v的残余流量不为零，而且现在从u->v的额定流量是要大于实际的流量的时候意味着这个点可以走， 
				if(!a[v] && cap[u][v] > flow[u][v]){
					p[v] = u;
					q.push(v);
					a[v] = min(a[u],cap[u][v] - flow[u][v]);//v的残余流量是u的残余流量与v自己当前还能通过的流量的值之间的最小值 
				}
			}
		}
		printf("%d\n",a[t]);
		if(a[t] == 0){
			break;
		}
		
		for(int u = 0;u != s;u = p[u]){
			flow[p[u]][u] += a[t];
			flow[u][p[u]] -= a[t];
		}
		f += a[t];
	}
	return f;
}

int main(){
	int n;
	
	while(cin >> n){
		int a[22][22];		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				cin >> a[i][j];
			}
		}
		
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					for(int l = 0;l <n;l++){
						if(abs(i-k) + abs(j-l) > 1){
							cap[i*n+j][k*n+l] = a[i][j] + a[k][l];
						}
					}
				}
			}
		}
		
		int q = n * n;
		
		int m = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n ;k++){
					for(int l = 0; l < n ;l++){
						if(abs(i-k) + abs(j-l) > 1){
							m  = max(m,fun(i*n+j,k*n+l,q));
						}
					}
				}
			}
		}
		cout << m << endl;
	}
	return 0; 
} 
