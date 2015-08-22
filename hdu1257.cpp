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

int main(){
	int t;
	while(cin >> t){
		vector<int> vec;
		for(int i = 0;i < t;i++){
			int x;
			scanf("%d",&x);
			int flag  = 0;
			int mi = INF;
			for(int j = 0;j < vec.size();j++){
				if(vec[j] >= x){
					vec[j] = x;
					flag = 1;
					break;
				}				
			}
			if(!flag){
				vec.push_back(x);
			}
		}
		printf("%d\n",vec.size());
	}
	return 0;
}

