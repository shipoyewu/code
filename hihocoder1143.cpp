#include <cstdio>
#include <iostream>
#include <map>
#include <vector>


using namespace std;
int A[2][2];
int B[2][2];
const int mod = 19999997;
int mul(int a[][2],int b[][2]){
    int  C[2][2] = {0};
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            for(int k = 0;k < 2;k++){
                C[i][j] = ( C[i][j] + (long long )a[i][k] * b[k][j])%mod;
            }
        }
    }
    for(int i = 0 ;i < 2;i++){
        for(int j = 0;j < 2;j++){
            a[i][j] = C[i][j];
        }
    }
}
int fun(int n){
    B[0][0] = 1;B[0][1] = 0;
    B[1][0] = 0;B[1][1] = 1;
    while(n > 0){
        if(n&1){
            mul(B,A);
        }
        mul(A,A);
        n >>= 1;
    }
    return B[0][0];
}
int main(){
    int n;
    A[0][0] = 1;A[0][1] = 1;
    A[1][0] = 1;A[1][1] = 0;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}
