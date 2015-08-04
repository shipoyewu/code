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
#define size 10
#define mod 1000000007
char p[1000];
char t[1000000]; 

int Rabin_karp(){
	int len1 = strlen(p);
	int len2 = strlen(t);
	int d = 0;
	int h  = 1;
	for(int i = 0;i < len1-1;i++){
		h = h*size;
		h %= mod;		
	}
	int q = 0;
	for(int i = 0;i < len1;i++){
		d*=10;d += p[i]-'0';d %= mod;
		q*=10;q += t[i]-'0';q %= mod;
	}
	
	len2 -= len1;
	for(int i = 0;i <= len2;i++){
		if(d % mod == q % mod){
			int flag = 1;
			for(int j = 0;j < len1;j++){
				if(t[i+j]!=p[j]){
					flag = 0;
					break;
				}
			}
			if(flag){
				printf("%d ",i+1);
			}
		}
		q = (size*(q-(t[i]-'0')*h) + (t[i+len1]-'0')) % mod;
	}
	return -1;
}
int main(){
    while(cin >> t >> p){
    	Rabin_karp();
    }
    return 0;
}

