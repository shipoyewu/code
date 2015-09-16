#include <cstdio>
#include <iostream>

using namespace std;
#define LL long long
LL ans;
int a[100005];
int b[100005];

void fun(int l,int r){
	if(r <= l + 1){
		return;
	}
	int mid = (l+r)/ 2;
	fun(l,mid);
	fun(mid,r);
	int s1 = l;
	int s2 = mid;
	int cc = l;
	while(s1 < mid && s2 < r){
		while(a[s1] > a[s2] && s2 < r){
			b[cc++] = a[s2++];
		}
		ans += s2 - mid;
		b[cc++] = a[s1++];
	}
	int s = l;
	for(;s1 < mid;s1++){
		ans += r -mid;
		b[cc++] = a[s1];
	}
	for(;s2 < r;s2++){
		b[cc++] = a[s2];
	}
	for(int i = l;i < r;i++){
		a[i] = b[i];
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	ans  =  0;
	fun(0,n);
	cout << ans << endl;
	return 0;
}
