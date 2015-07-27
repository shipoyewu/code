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
	int t;
	cin >> t;
	
	while(t--){
		set<pair<int,int> > se;
		int a[4][4];
		for(int i = 0;i < 4;i++){
			scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
			se.insert(make_pair(a[i][0],a[i][1]));
			se.insert(make_pair(a[i][2],a[i][3]));
		}
		if(se.size() != 4){
			cout << "NO" << endl;
		}
		else{
			int i;
			int flag = 0;
			int x0 = a[0][2] - a[0][0];
			int y0 = a[0][3] - a[0][1];
			
			for(i = 1;i < 4;i++){
				int xi = a[i][2] - a[i][0];
				int yi = a[i][3] - a[i][1];
				if(x0*yi == y0*xi){
					flag = 1;
					break;
				}
			}
			if(flag){
				for(int j = 1;j < 4;j++){
					if(j!=i){
						int xi = a[j][2] - a[j][0];
						int yi = a[j][3] - a[j][1];
						if(x0*xi + y0*yi == 0){
							flag ++;
						}
					}
				}
				if(flag == 3){
					cout << "YES" << endl;
				}
				else{
					cout << "NO" << endl;
				}
			} 
			else{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}

