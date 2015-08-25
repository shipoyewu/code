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
int a[1000];
int deq[1000];
int b[1000];

int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]); 
	}
	int s= 0,t = 0;
	for(int i = 0;i < n;i++){
		while(s < t && a[deq[t-1]] >= a[i]){
			t--;
		} 
		deq[t++] = i;
		if(i - k +1 >= 0){
			b[i-k+1] = a[deq[s]];
			if(deq[s] == i-k+1){
				s++;
			} 
		}
		
	}
    return 0;
}

