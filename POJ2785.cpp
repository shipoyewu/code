#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long 
using namespace std;
int a[4][4005];
int b[2][4005*4005];


int main(){
	int n;
	while(cin >> n){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 4;j++){
				scanf("%d",&a[j][i]);
			}
		}
		int cnt1 = 0;
		int cnt2 = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				b[0][cnt1++] = a[0][i] + a[1][j];
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				b[1][cnt2++] = a[2][i] + a[3][j];
			}
		}
		sort(b[1],b[1]+cnt2);
		LL ans = 0;
		for(int i = 0;i < cnt1;i++){
			ans += upper_bound(b[1],b[1]+cnt2,0-b[0][i]) - lower_bound(b[1],b[1]+cnt2,0-b[0][i]);
		}
		cout << ans << endl;
	}
	return 0;
}
