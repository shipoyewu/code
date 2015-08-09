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
LL a[100005];
int l[100005];
int r[100005];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
    	for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        l[1] = 1;
		for(int i = 2;i <= n;i++){
			l[i] = i;
      		while(a[i] <= a[l[i]-1] && l[i] > 1){
      			l[i] = l[l[i]-1];
      		} 	
        }
		r[n]=n;
        for(int i = n-1;i >= 1;i--){
        	r[i]=i;
			while(a[i] <= a[r[i] + 1] && r[i] < n){
				r[i] = r[r[i] + 1];
            }
        }
        LL ans = 0;
        for(int i = 1;i <= n;i++){
            ans  = max(ans,(r[i]-l[i]+1)*a[i]);
        }
        printf("%I64d\n",ans);
    }    
    return 0;
}
