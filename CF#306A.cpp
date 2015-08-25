#include <iostream> 
#include <cstring> 
using namespace std;
char a[100005];
int sum[100005];
int sum2[100005];
int main(){
	cin >>a;
	int n  = strlen(a);
	for(int i = 1;i < n;i++){
		if(a[i] == 'B' && a[i-1] == 'A'){
			sum[i] = sum[i-1] + 1;
		}
		else{
			sum[i] = sum[i-1];
		}
	}
	for(int i = 1;i < n;i++){
		if(a[i] == 'A' && a[i-1] == 'B'){
			sum2[i] = sum2[i-1] + 1;
		}
		else{
			sum2[i] = sum2[i-1];
		}
	}
	sum[n] = sum[n-1];
	sum2[n] = sum2[n-1];
	for(int i = 1;i < n;i++){
		if(a[i] == 'B' && a[i-1] == 'A' && sum2[n-1] - sum2[i+1] > 0 || a[i] == 'A' && a[i-1] == 'B' && sum[n-1] - sum[i+1] > 0){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}

