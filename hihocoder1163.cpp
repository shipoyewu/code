#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 0;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        x ^= a;
    }
    if(x == 0){
        cout << "Bob" << endl;
    }
    else{
        cout << "Alice"<< endl;
    }
    return 0;
}
