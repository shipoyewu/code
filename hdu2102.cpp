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
	int n,m;
	while(cin >> n >> m){
		if((n+m)%86 == 0){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}    
    return 0;
}

