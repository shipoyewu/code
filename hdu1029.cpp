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
int main(){
	int n;
	while(cin >>n){
		map<int,int> ma;
		
		for(int i = 0;i < n;i++){
			int a;
			scanf("%d",&a);
			if(ma.find(a)!=ma.end()){
				ma[a]++;
			}
			else{
				ma[a] = 1;
			}
		}
		for(map<int,int>::iterator ite = ma.begin();ite != ma.end();ite++){
			if(ite->second >= ((n+1)/2)){
				cout << ite->first << endl;
				break;
			}
		}
	}
	return 0;
}

