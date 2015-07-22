#include <cstdio>

using namespace std;
//Œ¥≤‚ ‘ 
itn n,m;
struct node{
	int x,y,w;
};
vector<node> vec;
int d[1000];
int F[1000];
bool Bellman_Ford(){
	for(int i = 0;i < n;i++){
		d[i] = INF;
		F[i] = -1;
	}
	d[0] = 0;
	for(int i = 0;i < m;i++){
		if(d[vec[i].y] > d[vec[i].x] + vec[i].w){
			d[vec[i].y] = d[vec[i].x] + vec[i].w;
			F[vec[i].y] = vec[i].x;
		}
	}
	for(int i = 0;i < m;i++){
		if(d[vec[i].y] > d[vec[i].x] + vec[i].w){
			return false;
		}
	}
	return true;
}
int main(){
	while(cin >> n >> m){
		for(int i = 0;i < n;i++){
			node a;
			scanf("%d%d%d",&a.x,&a.y,&a.w);
			vec.push_back(a);
		}
	}
} 
