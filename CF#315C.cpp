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
#define maxn 10000000
int sum1[maxn];
int is[maxn];
int sum2[maxn];
int fun(){
	int t = sqrt(maxn);
	is[0] = 1;
	is[1] = 1;
	for(int i = 0;i < t;i++){
		if(!is[i]){
			for(int j = i+i;j < maxn;j+=i){
				is[j] = 1; 
			}
		}
	}
	sum1[0] = 0;
	for(int i = 1;i < maxn;i++){
		sum1[i]=!is[i] + sum1[i-1];
	}
	sum2[0] = 0;
	for(int i = 1;i < maxn;i++){
		int cnt = 0;
		int n = i;
		int tmp = 0;
		while(n){
			tmp *= 10;
			tmp += n%10;
			n /= 10;
			cnt++;
		}
		if(tmp == i){
			sum2[i] = sum2[i-1] + 1;
		}
		else{
			sum2[i] = sum2[i-1];
		}
	}
}
int main(){
	fun();
	LL p,q;
	cin >> p >> q;
	for(int i = maxn-1;i > 0;i--){
		if(q*sum1[i] <= p * sum2[i]){
			printf("%d\n",i);
			break;
		} 
	}
    return 0;
}
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
   
    return 0;
}

