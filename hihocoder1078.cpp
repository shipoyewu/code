#include <cstdio>
#include <iostream>

using namespace std;
#define LL long long 
const int maxn = 1000005;
struct lin{
	LL s[maxn<<1];
	LL m[maxn<<1];
	void init(int l,int r,int k){
		if(l == r){
			m[k] = 0;
			scanf("%d",&s[k]);
			return ;
		}
		int m = (l+r) >>1;
		init(l,m,k<<1);
		init(m+1,r,k<<1|1);
		s[k] = s[k<<1]+s[k<<1|1];
	}
	void push_down(int k,int len){
		if(m[k]){
			m[k<<1] = m[k<<1|1] = m[k];
			s[k<<1] = (len-(len>>1))*m[k];
			s[k<<1|1] = (len>>1)*m[k];
			m[k] = 0;
		}
	}
	int query(int q,int p,int k,int x,int y){
		if(x <= q && p <= y) return s[k];
		if(p < x || q > y ) return 0;
		push_down(k,p-q+1);
		int res=0;
		int m = (p+q)>>1;
    	if(x<=m) res += query(q,m,k<<1,x,y);
    	if(m<y) res += query(m+1,p,k<<1|1,x,y);
    	return res;
	}
	void change(int p,int q,int k,int x,int y,int d){
		if(x <= p && q <= y){
			m[k] = d;
			s[k] = (LL)(q-p+1)*d;
			return ;
		}
		push_down(k,(q-p+1));
		int m = (p+q)>>1;
		if(x<=m) change(p,m,k<<1,x,y,d);
   		if(y>m) change(m+1,q,k<<1|1,x,y,d);
   		s[k] = s[k<<1]+s[k<<1|1];
	}
}qu;
int main(){
	int n;
	cin >> n;
	qu.init(1,n,1);
	int m;
	cin >> m;
	for(int i = 0;i < m;i++){
		int op;
		scanf("%d",&op);
		if(op == 0){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",qu.query(1,n,1,x,y));
		}
		else{
			int x,y,d;
			scanf("%d%d%d",&x,&y,&d);
			qu.change(1,n,1,x,y,d);
		}
	}
	return 0;
}
