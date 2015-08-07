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
	cin >> t; 
	while(t--){
		char a[3];
		double x,y;
		scanf("%s %lf %lf",a,&x,&y);
		switch(a[0]){
			case '+':{
				cout << (x + y) << endl;
				break;
			}
			case '-':{
				cout << (x - y) << endl;
				break;
			}
			case '*':{
				cout << (x * y) << endl;
				break;
			} 
			case '/':{
				cout << (x / y) << endl;
				break;
			}
		}
	}    
    return 0;
}

