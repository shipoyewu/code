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

unsigned long long  f[100];

int main(){
    int n;
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    f[4] = 5;
    f[5] = 8;
    for(int i = 6;i <= 60;i++){
        f[i] = f[i-3] + f[i-4] + f[i-5] + 3 + f[i-3];
    }
    while(cin >> n){
        cout << f[n] << endl;
    }
    return 0;
    
}
