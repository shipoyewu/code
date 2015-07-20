#include <cstdio>
#include <iostream>

using namespace std;

int fun(){
	memset(flow,0,sizeof(flow));
	int c = f = 0;
	int d[MAXN];
	queue<int> q;
	
	while(1){
		for(int i = 0;i < n;i++){
			d[i] = (i==s)?0:INF;
		}	
		bool inq[MAXN];
		memset(inq,0,sizeof(inq));
		q.push(s);
		while(!q.empty){
			int u = q.front();
			q.pop();
			inq[u] = 1;
			for(int v = 0;v < n;v++){
				if(cap[u][v] > flow[u][v] &&d[v] > d[u] + cost[u][v]){
					d[v] = d[u] + cost[u][v];
					p[v] = u;
					if(!inq[v]){
						inq[v] = true;
						q.push(v);
					}
				}
			}
		}
		if(d[t] == INF) break;
		for(int u = t;u!=s;u = p[u]){
			a = min(a,cap[p[u]][u]-flow[p[u]][u];
		}
		
		for(int u = t; u != s;u = p[u]){
			flow[p[u]][u] += a;
			flow[p[u]][u] -= a;
		}
		c += d[t] * a;
		f += a;
	}
}
int main(){
	
}
