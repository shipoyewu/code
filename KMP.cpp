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
char t[10000];
char p[10000];
int next[10005];
//next中存放的是next[i]指的是pi的最长的是前缀，同时这个前缀同样是后缀的这个子串的长度 
int find_next(){
	int len2 = strlen(p),k = 0;
	next[0]= 1;
	for(int i = 1;i < len2;i++){
		if( k > 0 && p[k] != p[i])k = next[k];
		if(p[k] == p[i]) k ++;
		next[i] = k;
	}
}
int kmp_match(){
	int len1 = strlen(t),len2 = strlen(p),q = 0;;
	int n = len1 - len2 +1;
	find_next();
	for(int i = 0;i <= n;i++){
		if(q > 0 && p[q] != t[i]) q = next[q];
		if(p[q] == t[i])  q++;
		if(q == len2) printf("%d\n",i);
	}
} 
int main(){
	while(cin >> t >> p){
		kmp_match();
	}	    
    return 0;
}

