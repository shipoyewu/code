#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
const int M=10007;
typedef long long LL;
mat mul(mat &A,mat &B){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0;i < A.size();i++){
        for(int k = 0; k < B.size();k++){
            for(int j = 0;j < B[0].size();j++){
                C[i][j]+=A[i][k]*B[k][j];
                C[i][j] %= M;
            }
        }
    }
    return C;
}
mat fun(mat A,LL n){
    mat B(A.size(),vec(A.size()));
    for(int i = 0;i < A.size();i ++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n&1) B=mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        mat A(4,vec(4));
        A[0][0]=2;A[0][1]=1;A[0][2]=1;A[0][3]=0;
        A[1][0]=1;A[1][1]=2;A[1][2]=0;A[1][3]=1;
        A[2][0]=1;A[2][1]=0;A[2][2]=2;A[2][3]=1;
        A[3][0]=0;A[3][1]=1;A[3][2]=1;A[3][3]=2;
        A = fun(A,n);
        cout << A[0][0] << endl;
    }
    return 0;
}
