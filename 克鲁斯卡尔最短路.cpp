#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
struct edge{
	int u,v,value;
	bool operator <(const edge& a )const {
		return value > a.value; 
	} 
};
edge E[1000];
int bin[1000];

int find_f(int a){
	return (bin[a] == a)?a: bin[a] = find_f(bin[a]);
}
vector<edge> vec;
int klouth(){
	priority_queue<edge> que;
	int mst = 0;
	for(int i = 0;i < n;i++){
		bin[i] = i;
	}
	for(int i = 0;i < m;i++){
		que.push(E[i]);
	}
	
	while(!que.empty()){
		edge q = que.top();
		que.pop();
		int fa = find_f(q.u);
		int fb = find_f(q.v);
		if(fa != fb){
			vec.push_back(q);
			bin[fa] = fb;
			mst += q.value;	
		}
	}
	
	cout << mst << endl;
	for(int i = 0;i < vec.size();i++){
		cout << vec[i].u <<" " <<vec[i].v << " " << vec[i].value << endl;	
	}
	return mst;
}
int main(){
	while(cin >> n >> m){
		for(int i = 0;i < m;i++){
			cin >> E[i].u >> E[i].v >> E[i].value;
		}
		klouth();
	}	
	return 0;
} 
/*
9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
3 5 14
2 5 4
5 6 2
6 7 1
7 8 7
1 7 11
0 7 8
8 6 6
2 8 2
*/
