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
#define maxn 100010
#define mid ((l+r)>>1)
int n,m;
int tree[30][maxn];
int toleft[30][maxn];
int so[maxn];
void biuld(int p,int l,int r){
	if(l == r) return;
	int lm = 0;
	for(int i = mid;i >= l;i--){
		if(so[i] == so[mid]) lm++;
		else break;
	}
	
	int ls = l;
	int rs = mid+1;
	for(int i = l;i <= r;i++){
		if(i==l)
			toleft[p][i] = 0;
		else
			toleft[p][i] = toleft[p][i-1];
		if(tree[p][i] == so[mid]){
			if(lm){
				lm --;
				toleft[p][i]++;
				tree[p+1][ls++] = tree[p][i];
			}
			else{
				tree[p+1][rs++] = tree[p][i];
			}
		}
		else if(tree[p][i] < so[mid]){
			toleft[p][i] ++;
			tree[p+1][ls++] = tree[p][i];
		}
		else {
			tree[p+1][rs++] = tree[p][i];
		}
	}
	biuld(p+1,l,mid);
	biuld(p+1,mid+1,r);
}
int query(int p,int l,int r,int x,int y,int k){
	if(l == r) return tree[p][l];
	int s;
	int ss;
	if(x == l){
		s = 0;
		ss = toleft[p][y];
	}
	else{
		s = toleft[p][x-1];
		ss = toleft[p][y] - s;
	}
	if(k <= ss){
		return query(p+1,l,mid,l+s,l+toleft[p][y]-1,k);//减一的原因是toleft[p][r] 中包含了l所以要减去一个l开始的位置，这样才有ss大小的区间 
	}
	else{
		return query(p+1,mid+1,r,mid+1+x-l-s,mid+1+y-l-toleft[p][y],k-ss); //放入左子树的是s则放入右子树的是x-l-s, 
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		scanf("%d%d",&n,&m);
		memset(tree,0,sizeof(tree));
		memset(toleft,0,sizeof(toleft));
		for(int i = 1;i <= n;i++){
			scanf("%d",&tree[0][i]);
			so[i] = tree[0][i];
		}
		sort(so+1,so+1+n);
		biuld(0,1,n);
		for(int i = 0; i < m;i++){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			printf("%d\n",query(0,1,n,x,y,k));
		}
	}
	return 0;	
}

